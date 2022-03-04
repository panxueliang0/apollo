/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/kinglong/kinglong_controller.h"

#include "modules/common/proto/vehicle_signal.pb.h"

#include "cyber/common/log.h"
#include "modules/canbus/vehicle/kinglong/kinglong_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "cyber/time/time.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace kinglong {

using ::apollo::drivers::canbus::ProtocolData;
using ::apollo::common::ErrorCode;
using ::apollo::control::ControlCommand;

namespace {

const int32_t kMaxFailAttempt = 10;
const int32_t CHECK_RESPONSE_STEER_UNIT_FLAG = 1;
const int32_t CHECK_RESPONSE_SPEED_UNIT_FLAG = 2;
}

ErrorCode KinglongController::Init(
	const VehicleParameter& params,
	CanSender<::apollo::canbus::ChassisDetail> *const can_sender,
    MessageManager<::apollo::canbus::ChassisDetail> *const message_manager) {
  if (is_initialized_) {
    AINFO << "KinglongController has already been initiated.";
    return ErrorCode::CANBUS_ERROR;
  }

  params_.CopyFrom(params);
  if (!params_.has_driving_mode()) {
    AERROR << "Vehicle conf pb not set driving_mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  if (can_sender == nullptr) {
    return ErrorCode::CANBUS_ERROR;
  }
  can_sender_ = can_sender;

  if (message_manager == nullptr) {
    AERROR << "protocol manager is null.";
    return ErrorCode::CANBUS_ERROR;
  }
  message_manager_ = message_manager;

  // sender part
  brake_nboost_ctrl_98ff9197_ = dynamic_cast<Brakenboostctrl98ff9197*>
          (message_manager_->GetMutableProtocolDataById(Brakenboostctrl98ff9197::ID));
  if (brake_nboost_ctrl_98ff9197_ == nullptr) {
     AERROR << "Brakenboostctrl98ff9197 does not exist in the KinglongMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }
  //驻车控制
  controller_parking_98ff8ca9_ = dynamic_cast<Controllerparking98ff8ca9*>
          (message_manager_->GetMutableProtocolDataById(Controllerparking98ff8ca9::ID));
  if (controller_parking_98ff8ca9_ == nullptr) {
     AERROR << "Controllerparking98ff8ca9 does not exist in the KinglongMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }
  //驱动、制动控制
  controller_pedal_cmd_98ff84a9_ = dynamic_cast<Controllerpedalcmd98ff84a9*>
          (message_manager_->GetMutableProtocolDataById(Controllerpedalcmd98ff84a9::ID));
  if (controller_pedal_cmd_98ff84a9_ == nullptr) {
     AERROR << "Controllerpedalcmd98ff84a9 does not exist in the KinglongMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }
  //灯光控制
  controller_status_requset_98ff86a9_ = dynamic_cast<Controllerstatusrequset98ff86a9*>
          (message_manager_->GetMutableProtocolDataById(Controllerstatusrequset98ff86a9::ID));
  if (controller_status_requset_98ff86a9_ == nullptr) {
     AERROR << "Controllerstatusrequset98ff86a9 does not exist in the KinglongMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }
  //转向控制
  controller_steering_cmd_98ff82a9_ = dynamic_cast<Controllersteeringcmd98ff82a9*>
          (message_manager_->GetMutableProtocolDataById(Controllersteeringcmd98ff82a9::ID));
  if (controller_steering_cmd_98ff82a9_ == nullptr) {
     AERROR << "Controllersteeringcmd98ff82a9 does not exist in the KinglongMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  can_sender_->AddMessage(Brakenboostctrl98ff9197::ID, brake_nboost_ctrl_98ff9197_, false);
  can_sender_->AddMessage(Controllerparking98ff8ca9::ID, controller_parking_98ff8ca9_, false);
  can_sender_->AddMessage(Controllerpedalcmd98ff84a9::ID, controller_pedal_cmd_98ff84a9_, false);
  can_sender_->AddMessage(Controllerstatusrequset98ff86a9::ID, controller_status_requset_98ff86a9_, false);
  can_sender_->AddMessage(Controllersteeringcmd98ff82a9::ID, controller_steering_cmd_98ff82a9_, false);

  // need sleep to ensure all messages received
  AINFO << "KinglongController is initialized.";

  is_initialized_ = true;
  return ErrorCode::OK;
}

KinglongController::~KinglongController() {}

bool KinglongController::Start() {
  if (!is_initialized_) {
    AERROR << "KinglongController has NOT been initiated.";
    return false;
  }
  const auto& update_func = [this] { SecurityDogThreadFunc(); };
  thread_.reset(new std::thread(update_func));

  return true;
}

void KinglongController::Stop() {
  if (!is_initialized_) {
    AERROR << "KinglongController stops or starts improperly!";
    return;
  }

  if (thread_ != nullptr && thread_->joinable()) {
    thread_->join();
    thread_.reset();
    AINFO << "KinglongController stopped.";
  }
}

Chassis KinglongController::chassis() {
  chassis_.Clear();

  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);

  // 21, 22, previously 1, 2
  if (driving_mode() == Chassis::EMERGENCY_MODE) {
    set_chassis_error_code(Chassis::NO_ERROR);
  }

  chassis_.set_driving_mode(driving_mode());
  chassis_.set_error_code(chassis_error_code());

  // 3
  chassis_.set_engine_started(true);
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  if (chassis_detail.kinglong().has_bus_vehicle_speed_msg_8cfe6c17() &&
      chassis_detail.kinglong().bus_vehicle_speed_msg_8cfe6c17().has_bus_vehicle_speed()) {
    chassis_.set_speed_mps(
        static_cast<float>(chassis_detail.kinglong().bus_vehicle_speed_msg_8cfe6c17().bus_vehicle_speed()));
  } else {
    chassis_.set_speed_mps(0);
  }
    // 8 throttle
  if (chassis_detail.kinglong().has_vcu_drive_feedback_98ff7097() &&
      chassis_detail.kinglong().vcu_drive_feedback_98ff7097().has_vcu_drive_throttle_pedal_posi()) {
    chassis_.set_throttle_percentage(static_cast<float>(
        chassis_detail.kinglong().vcu_drive_feedback_98ff7097().vcu_drive_throttle_pedal_posi()));
  } else {
    chassis_.set_throttle_percentage(0);
  }
  // 9 brake
  // if (chassis_detail.kinglong().has_breaksystem_feedback_98ff87ab() &&
  //     chassis_detail.kinglong().breaksystem_feedback_98ff87ab().has_epb_fb_main_brkpressure()) {
  //   chassis_.set_brake_percentage(static_cast<float>(
  //       chassis_detail.kinglong().breaksystem_feedback_98ff87ab().epb_fb_main_brkpressure()));
  // } else {
  //   chassis_.set_brake_percentage(0);
  // }
  //这个值反馈不准，需要找到其它替代信号
  if (chassis_detail.kinglong().has_vcu_drive_feedback_98ff7097() &&
      chassis_detail.kinglong().vcu_drive_feedback_98ff7097().has_vcu_drive_break_pedal_position()) {
    chassis_.set_brake_percentage(static_cast<float>(
        chassis_detail.kinglong().vcu_drive_feedback_98ff7097().vcu_drive_break_pedal_position()));
  } else {
    chassis_.set_brake_percentage(0);
  }
  // 23, previously 10   gear
  if (chassis_detail.kinglong().has_vcu_basic_message_98ffea97() &&
      chassis_detail.kinglong().vcu_basic_message_98ffea97().has_vcu_basic_real_gear()) {
    Chassis::GearPosition gear_pos = Chassis::GEAR_INVALID;

    if (chassis_detail.kinglong().vcu_basic_message_98ffea97().vcu_basic_real_gear() ==
        Vcu_basic_message_98ffea97::VCU_BASIC_REAL_GEAR_N) {
      gear_pos = Chassis::GEAR_NEUTRAL;
    }
    if (chassis_detail.kinglong().vcu_basic_message_98ffea97().vcu_basic_real_gear() ==
        Vcu_basic_message_98ffea97::VCU_BASIC_REAL_GEAR_R) {
      gear_pos = Chassis::GEAR_REVERSE;
    }
    if (chassis_detail.kinglong().vcu_basic_message_98ffea97().vcu_basic_real_gear() ==
        Vcu_basic_message_98ffea97::VCU_BASIC_REAL_GEAR_D) {
      gear_pos = Chassis::GEAR_DRIVE;
    }
    if (chassis_detail.kinglong().has_parkingmode_feedback_98ff8dac() &&
      chassis_detail.kinglong().parkingmode_feedback_98ff8dac().has_pmf_current_status() &&
      chassis_detail.kinglong().parkingmode_feedback_98ff8dac().pmf_current_status() == 1) {
      gear_pos = Chassis::GEAR_PARKING;
    }

    chassis_.set_gear_location(gear_pos);
  } else {
    chassis_.set_gear_location(Chassis::GEAR_NONE);
  }
  // 11 steering
  if (chassis_detail.kinglong().has_eps_feedback_98ff83aa() &&
      chassis_detail.kinglong().eps_feedback_98ff83aa().has_eps_real_angle()) {
    chassis_.set_steering_percentage(static_cast<float>(
        chassis_detail.kinglong().eps_feedback_98ff83aa().eps_real_angle() * 100.0 /
        vehicle_params_.max_steer_angle()));
  } else {
    chassis_.set_steering_percentage(0);
  }
  // 27 battery soc
  if (chassis_detail.kinglong().has_soc_98ffeb97() &&
      chassis_detail.kinglong().soc_98ffeb97().has_soc()) {
    chassis_.set_battery_soc_percentage(
        chassis_detail.kinglong().soc_98ffeb97().soc());
  }

  return chassis_;
}

void KinglongController::Emergency() {
  set_driving_mode(Chassis::EMERGENCY_MODE);
  ResetProtocol();
}

ErrorCode KinglongController::EnableAutoMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "already in COMPLETE_AUTO_DRIVE mode";
    return ErrorCode::OK;
  }
  controller_parking_98ff8ca9_->set_cp_epb_enable(1);
  controller_steering_cmd_98ff82a9_->set_steering_ctrl_status(
      Controller_steering_cmd_98ff82a9::STEERING_CTRL_STATUS_AUTO_DRIVE);
  controller_pedal_cmd_98ff84a9_->set_pedal_ctrl_request(
      Controller_pedal_cmd_98ff84a9::PEDAL_CTRL_REQUEST_ON);
  AINFO << "\n\n\n set enable \n\n\n";
  can_sender_->Update();
  const int32_t flag =
      CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  if (!CheckResponse(flag, true)) {
    AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  } else {
    set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
    AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
    return ErrorCode::OK;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_enable();
  throttle_62_->set_enable();
  steering_64_->set_enable();

  can_sender_->Update();
  const int32_t flag =
      CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  if (!CheckResponse(flag, true)) {
    AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;
  */
}

ErrorCode KinglongController::DisableAutoMode() {
  ResetProtocol();
  can_sender_->Update();
  set_driving_mode(Chassis::COMPLETE_MANUAL);
  set_chassis_error_code(Chassis::NO_ERROR);
  AINFO << "Switch to COMPLETE_MANUAL ok.";
  return ErrorCode::OK;
}

ErrorCode KinglongController::EnableSteeringOnlyMode() {
  AFATAL << "SteeringOnlyMode Not supported!";
  return ErrorCode::OK;
/* ADD YOUR OWN CAR CHASSIS OPERATION 
  brake_60_->set_disable();
  throttle_62_->set_disable();
  steering_64_->set_enable();

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_STEER_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_STEER_ONLY);
  AINFO << "Switch to AUTO_STEER_ONLY mode ok.";
  return ErrorCode::OK; */
}

ErrorCode KinglongController::EnableSpeedOnlyMode() {
  AFATAL << "SpeedOnlyMode Not supported!";
  return ErrorCode::OK;
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_enable();
  throttle_62_->set_enable();
  steering_64_->set_disable();  

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_SPEED_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_SPEED_ONLY);
  AINFO << "Switch to AUTO_SPEED_ONLY mode ok.";
  return ErrorCode::OK;*/

}

// NEUTRAL, REVERSE, DRIVE
void KinglongController::Gear(Chassis::GearPosition gear_position) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "This drive mode no need to set gear.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION  */
  switch (gear_position) {
    case Chassis::GEAR_NEUTRAL: {
      controller_parking_98ff8ca9_->set_cp_park_active(0);
      controller_pedal_cmd_98ff84a9_->set_pedal_gear(Controller_pedal_cmd_98ff84a9::PEDAL_GEAR_N);
      break;
    }
    case Chassis::GEAR_REVERSE: {
      controller_parking_98ff8ca9_->set_cp_park_active(0);
      controller_pedal_cmd_98ff84a9_->set_pedal_gear(Controller_pedal_cmd_98ff84a9::PEDAL_GEAR_R);
      break;
    }
    case Chassis::GEAR_DRIVE: {
      controller_parking_98ff8ca9_->set_cp_park_active(0);
      controller_pedal_cmd_98ff84a9_->set_pedal_gear(Controller_pedal_cmd_98ff84a9::PEDAL_GEAR_D);
      break;
    }
    case Chassis::GEAR_INVALID: {
      AERROR << "Gear command is invalid!";
      controller_parking_98ff8ca9_->set_cp_park_active(0);
      controller_pedal_cmd_98ff84a9_->set_pedal_gear(Controller_pedal_cmd_98ff84a9::PEDAL_GEAR_INVALID);
      break;
    }
    case Chassis::GEAR_PARKING: {
      controller_parking_98ff8ca9_->set_cp_park_active(1);
      break;
    }
    default: {
      controller_parking_98ff8ca9_->set_cp_park_active(0);
      controller_pedal_cmd_98ff84a9_->set_pedal_gear(Controller_pedal_cmd_98ff84a9::PEDAL_GEAR_N);
      break;
    }
  }

}

// brake with new acceleration
// acceleration:0.00~99.99, unit:
// acceleration:0.0 ~ 7.0, unit:m/s^2
// acceleration_spd:60 ~ 100, suggest: 90
// -> pedal
void KinglongController::Brake(double pedal) {
  // double real_value = params_.max_acc() * acceleration / 100;
  // TODO(All) :  Update brake value based on mode
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set brake pedal.";
    return;
  }
  //ADD YOUR OWN CAR CHASSIS OPERATION
  controller_pedal_cmd_98ff84a9_->set_pedal_break(static_cast<int>(pedal));

}

// drive with old acceleration
// gas:0.00~99.99 unit:
void KinglongController::Throttle(double pedal) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set throttle pedal.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION*/  
  controller_pedal_cmd_98ff84a9_->set_pedal_throttle(static_cast<int>(pedal));
}

// confirm the car is driven by acceleration command or throttle/brake pedal
// drive with acceleration/deceleration
// acc:-7.0 ~ 5.0, unit:m/s^2
void KinglongController::Acceleration(double acc) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set acceleration.";
    return;
  }
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
}

// kinglong default, -470 ~ 470, left:+, right:-
// need to be compatible with control module, so reverse
// steering with old angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
void KinglongController::Steer(double angle) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }
  const double real_angle = vehicle_params_.max_steer_angle() * angle / 100.0;
  controller_steering_cmd_98ff82a9_->set_streering_angle(real_angle);
}

// steering with new angle speed
// angle:-99.99~0.00~99.99, unit:, left:-, right:+
// angle_spd:0.00~99.99, unit:deg/s
void KinglongController::Steer(double angle, double angle_spd) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }
  const double real_angle = vehicle_params_.max_steer_angle() * angle / 100.0;
  controller_steering_cmd_98ff82a9_->set_streering_angle(real_angle);
}

void KinglongController::SetEpbBreak(const ControlCommand& command) {
  if (command.parking_brake()) {
    // None
  } else {
    // None
  }
}

void KinglongController::SetBeam(const ControlCommand& command) {
  if (command.signal().high_beam()) {
    // None
  } else if (command.signal().low_beam()) {
    // None
  } else {
    // None
  }
}

void KinglongController::SetHorn(const ControlCommand& command) {
  if (command.signal().horn()) {
    // None
  } else {
    // None
  }
}

void KinglongController::SetTurningSignal(const ControlCommand& command) {
  // Set Turn Signal
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  auto signal = command.signal().turn_signal();
  if (signal == Signal::TURN_LEFT) {
    turnsignal_68_->set_turn_left();
  } else if (signal == Signal::TURN_RIGHT) {
    turnsignal_68_->set_turn_right();
  } else {
    turnsignal_68_->set_turn_none();
  }
  */
}

void KinglongController::ResetProtocol() {
  message_manager_->ResetSendMessages();
}

bool KinglongController::CheckChassisError() {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  return false;
}

void KinglongController::SecurityDogThreadFunc() {
  int32_t vertical_ctrl_fail = 0;
  int32_t horizontal_ctrl_fail = 0;

  if (can_sender_ == nullptr) {
    AERROR << "Failed to run SecurityDogThreadFunc() because can_sender_ is "
              "nullptr.";
    return;
  }
  while (!can_sender_->IsRunning()) {
    std::this_thread::yield();
  }

  std::chrono::duration<double, std::micro> default_period{50000};
  int64_t start = 0;
  int64_t end = 0;
  while (can_sender_->IsRunning()) {
    start = ::apollo::cyber::Time::Now().ToMicrosecond();
    const Chassis::DrivingMode mode = driving_mode();
    bool emergency_mode = false;

    // 1. horizontal control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_STEER_ONLY) &&
        CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, false) == false) {
      ++horizontal_ctrl_fail;
      if (horizontal_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      horizontal_ctrl_fail = 0;
    }

    // 2. vertical control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_SPEED_ONLY) &&
        !CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, false)) {
      ++vertical_ctrl_fail;
      if (vertical_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      vertical_ctrl_fail = 0;
    }
    if (CheckChassisError()) {
      set_chassis_error_code(Chassis::CHASSIS_ERROR);
      emergency_mode = true;
    }

    if (emergency_mode && mode != Chassis::EMERGENCY_MODE) {
      set_driving_mode(Chassis::EMERGENCY_MODE);
      message_manager_->ResetSendMessages();
    }
    end = ::apollo::cyber::Time::Now().ToMicrosecond();
    std::chrono::duration<double, std::micro> elapsed{end - start};
    if (elapsed < default_period) {
      std::this_thread::sleep_for(default_period - elapsed);
    } else {
      AERROR
          << "Too much time consumption in KinglongController looping process:"
          << elapsed.count();
    }
  }
}

bool KinglongController::CheckResponse(const int32_t flags, bool need_wait) {
  int32_t retry_num = 20;
  ChassisDetail chassis_detail;
  bool is_eps_online = false;
  bool is_vcu_online = false;
  bool is_esp_online = false;

  do {
    if (message_manager_->GetSensorData(&chassis_detail) != ErrorCode::OK) {
      AERROR_EVERY(100) << "get chassis detail failed.";
      return false;
    }
    bool check_ok = true;
    if (flags & CHECK_RESPONSE_STEER_UNIT_FLAG) {
      is_eps_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_eps_online() &&
                      chassis_detail.check_response().is_eps_online();
      check_ok = check_ok && is_eps_online;
    }

    if (flags & CHECK_RESPONSE_SPEED_UNIT_FLAG) {
      is_vcu_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_vcu_online() &&
                      chassis_detail.check_response().is_vcu_online();
      is_esp_online = chassis_detail.has_check_response() &&
                      chassis_detail.check_response().has_is_esp_online() &&
                      chassis_detail.check_response().is_esp_online();
      check_ok = check_ok && is_vcu_online && is_esp_online;
    }
    if (check_ok) {
      return true;
    } else {
      AINFO << "Need to check response again.";
    }
    if (need_wait) {
      --retry_num;
      std::this_thread::sleep_for(
          std::chrono::duration<double, std::milli>(20));
    }
  } while (need_wait && retry_num);

  AINFO << "check_response fail: is_eps_online:" << is_eps_online
        << ", is_vcu_online:" << is_vcu_online
        << ", is_esp_online:" << is_esp_online;

  return false;
}

void KinglongController::set_chassis_error_mask(const int32_t mask) {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  chassis_error_mask_ = mask;
}

int32_t KinglongController::chassis_error_mask() {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  return chassis_error_mask_;
}

Chassis::ErrorCode KinglongController::chassis_error_code() {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  return chassis_error_code_;
}

void KinglongController::set_chassis_error_code(
    const Chassis::ErrorCode& error_code) {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  chassis_error_code_ = error_code;
}

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
