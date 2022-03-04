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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace kinglong {

class Controllerstatusrequset98ff86a9 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Controllerstatusrequset98ff86a9();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 54, 'is_signed_var': False, 'len': 2, 'name': 'SR_RTK_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_rtk_power(int sr_rtk_power);

  // config detail: {'bit': 52, 'is_signed_var': False, 'len': 2, 'name': 'SR_FullView_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_fullview_power(int sr_fullview_power);

  // config detail: {'bit': 50, 'is_signed_var': False, 'len': 2, 'name': 'SR_Mobieye_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_mobieye_power(int sr_mobieye_power);

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 2, 'name': 'SR_MmRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_mmradar_power(int sr_mmradar_power);

  // config detail: {'bit': 46, 'is_signed_var': False, 'len': 2, 'name': 'SR_UltrasonicRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_ultrasonicradar_power(int sr_ultrasonicradar_power);

  // config detail: {'bit': 44, 'is_signed_var': False, 'len': 2, 'name': 'SR_BSDRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_bsdradar_power(int sr_bsdradar_power);

  // config detail: {'bit': 42, 'is_signed_var': False, 'len': 2, 'name': 'SR_SingleLindLiDar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_singlelindlidar_power(int sr_singlelindlidar_power);

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 2, 'name': 'SR_16LiDar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_16lidar_power(int sr_16lidar_power);

  // config detail: {'bit': 38, 'is_signed_var': False, 'len': 2, 'name': 'SR_REEVERD1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_reeverd1(int sr_reeverd1);

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 2, 'name': 'SR_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_horn(int sr_horn);

  // config detail: {'bit': 34, 'is_signed_var': False, 'len': 2, 'name': 'SR_FluorescentLamps', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_fluorescentlamps(int sr_fluorescentlamps);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 2, 'name': 'SR_Rooflight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_rooflight(int sr_rooflight);

  // config detail: {'bit': 30, 'is_signed_var': False, 'len': 2, 'name': 'SR_MinilLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_minillight(int sr_minillight);

  // config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'SR_BreakLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_breaklight(int sr_breaklight);

  // config detail: {'bit': 26, 'is_signed_var': False, 'len': 2, 'name': 'SR_TurnRight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_turnright(int sr_turnright);

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 2, 'name': 'SR_TurnLeft', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_turnleft(int sr_turnleft);

  // config detail: {'bit': 22, 'is_signed_var': False, 'len': 2, 'name': 'SR_ReversingLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_reversinglight(int sr_reversinglight);

  // config detail: {'bit': 20, 'is_signed_var': False, 'len': 2, 'name': 'SR_Lowbeam', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_lowbeam(int sr_lowbeam);

  // config detail: {'bit': 18, 'is_signed_var': False, 'len': 2, 'name': 'SR_Fdoor', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_fdoor(int sr_fdoor);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 2, 'name': 'SR_Gear_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_gear_status(int sr_gear_status);

  // config detail: {'bit': 12, 'is_signed_var': False, 'len': 4, 'name': 'SR_VehicleMoveing_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_vehiclemoveing_status(int sr_vehiclemoveing_status);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 4, 'name': 'SR_Drive_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_drive_status(int sr_drive_status);

  // config detail: {'bit': 4, 'is_signed_var': False, 'len': 4, 'name': 'SR_InertialNavigation_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_inertialnavigation_status(int sr_inertialnavigation_status);

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 4, 'name': 'SR_RTK_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Controllerstatusrequset98ff86a9* set_sr_rtk_status(int sr_rtk_status);

 private:

  // config detail: {'bit': 54, 'is_signed_var': False, 'len': 2, 'name': 'SR_RTK_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_rtk_power(uint8_t* data, int sr_rtk_power);

  // config detail: {'bit': 52, 'is_signed_var': False, 'len': 2, 'name': 'SR_FullView_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_fullview_power(uint8_t* data, int sr_fullview_power);

  // config detail: {'bit': 50, 'is_signed_var': False, 'len': 2, 'name': 'SR_Mobieye_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_mobieye_power(uint8_t* data, int sr_mobieye_power);

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 2, 'name': 'SR_MmRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_mmradar_power(uint8_t* data, int sr_mmradar_power);

  // config detail: {'bit': 46, 'is_signed_var': False, 'len': 2, 'name': 'SR_UltrasonicRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_ultrasonicradar_power(uint8_t* data, int sr_ultrasonicradar_power);

  // config detail: {'bit': 44, 'is_signed_var': False, 'len': 2, 'name': 'SR_BSDRadar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_bsdradar_power(uint8_t* data, int sr_bsdradar_power);

  // config detail: {'bit': 42, 'is_signed_var': False, 'len': 2, 'name': 'SR_SingleLindLiDar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_singlelindlidar_power(uint8_t* data, int sr_singlelindlidar_power);

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 2, 'name': 'SR_16LiDar_Power', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_16lidar_power(uint8_t* data, int sr_16lidar_power);

  // config detail: {'bit': 38, 'is_signed_var': False, 'len': 2, 'name': 'SR_REEVERD1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_reeverd1(uint8_t* data, int sr_reeverd1);

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 2, 'name': 'SR_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_horn(uint8_t* data, int sr_horn);

  // config detail: {'bit': 34, 'is_signed_var': False, 'len': 2, 'name': 'SR_FluorescentLamps', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_fluorescentlamps(uint8_t* data, int sr_fluorescentlamps);

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 2, 'name': 'SR_Rooflight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_rooflight(uint8_t* data, int sr_rooflight);

  // config detail: {'bit': 30, 'is_signed_var': False, 'len': 2, 'name': 'SR_MinilLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_minillight(uint8_t* data, int sr_minillight);

  // config detail: {'bit': 28, 'is_signed_var': False, 'len': 2, 'name': 'SR_BreakLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_breaklight(uint8_t* data, int sr_breaklight);

  // config detail: {'bit': 26, 'is_signed_var': False, 'len': 2, 'name': 'SR_TurnRight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_turnright(uint8_t* data, int sr_turnright);

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 2, 'name': 'SR_TurnLeft', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_turnleft(uint8_t* data, int sr_turnleft);

  // config detail: {'bit': 22, 'is_signed_var': False, 'len': 2, 'name': 'SR_ReversingLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_reversinglight(uint8_t* data, int sr_reversinglight);

  // config detail: {'bit': 20, 'is_signed_var': False, 'len': 2, 'name': 'SR_Lowbeam', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_lowbeam(uint8_t* data, int sr_lowbeam);

  // config detail: {'bit': 18, 'is_signed_var': False, 'len': 2, 'name': 'SR_Fdoor', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_fdoor(uint8_t* data, int sr_fdoor);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 2, 'name': 'SR_Gear_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_gear_status(uint8_t* data, int sr_gear_status);

  // config detail: {'bit': 12, 'is_signed_var': False, 'len': 4, 'name': 'SR_VehicleMoveing_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_vehiclemoveing_status(uint8_t* data, int sr_vehiclemoveing_status);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 4, 'name': 'SR_Drive_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_drive_status(uint8_t* data, int sr_drive_status);

  // config detail: {'bit': 4, 'is_signed_var': False, 'len': 4, 'name': 'SR_InertialNavigation_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_inertialnavigation_status(uint8_t* data, int sr_inertialnavigation_status);

  // config detail: {'bit': 0, 'is_signed_var': False, 'len': 4, 'name': 'SR_RTK_Status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_sr_rtk_status(uint8_t* data, int sr_rtk_status);

 private:
  int sr_rtk_power_;
  int sr_fullview_power_;
  int sr_mobieye_power_;
  int sr_mmradar_power_;
  int sr_ultrasonicradar_power_;
  int sr_bsdradar_power_;
  int sr_singlelindlidar_power_;
  int sr_16lidar_power_;
  int sr_reeverd1_;
  int sr_horn_;
  int sr_fluorescentlamps_;
  int sr_rooflight_;
  int sr_minillight_;
  int sr_breaklight_;
  int sr_turnright_;
  int sr_turnleft_;
  int sr_reversinglight_;
  int sr_lowbeam_;
  int sr_fdoor_;
  int sr_gear_status_;
  int sr_vehiclemoveing_status_;
  int sr_drive_status_;
  int sr_inertialnavigation_status_;
  int sr_rtk_status_;
};

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo


