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

#include "modules/canbus/vehicle/kinglong/kinglong_message_manager.h"

#include "modules/canbus/vehicle/kinglong/protocol/brake_nboost_ctrl_98ff9197.h"
#include "modules/canbus/vehicle/kinglong/protocol/controller_parking_98ff8ca9.h"
#include "modules/canbus/vehicle/kinglong/protocol/controller_pedal_cmd_98ff84a9.h"
#include "modules/canbus/vehicle/kinglong/protocol/controller_status_requset_98ff86a9.h"
#include "modules/canbus/vehicle/kinglong/protocol/controller_steering_cmd_98ff82a9.h"

#include "modules/canbus/vehicle/kinglong/protocol/breaksystem_feedback_98ff87ab.h"
#include "modules/canbus/vehicle/kinglong/protocol/bus_battery_meg_98fa1017.h"
#include "modules/canbus/vehicle/kinglong/protocol/bus_inteligent_control_status_98fa0117.h"
#include "modules/canbus/vehicle/kinglong/protocol/bus_mileage_98fee017.h"
#include "modules/canbus/vehicle/kinglong/protocol/bus_vehicle_speed_msg_8cfe6c17.h"
#include "modules/canbus/vehicle/kinglong/protocol/bus_vehicle_status_98fa0517.h"
#include "modules/canbus/vehicle/kinglong/protocol/eps_feedback_98ff83aa.h"
#include "modules/canbus/vehicle/kinglong/protocol/parkingmode_feedback_98ff8dac.h"
#include "modules/canbus/vehicle/kinglong/protocol/soc_98ffeb97.h"
#include "modules/canbus/vehicle/kinglong/protocol/vcu_basic_message_98ffea97.h"
#include "modules/canbus/vehicle/kinglong/protocol/vcu_breaksys_cmd_98ff85a7.h"
#include "modules/canbus/vehicle/kinglong/protocol/vcu_drive_feedback_98ff7097.h"
#include "modules/canbus/vehicle/kinglong/protocol/vector__independent_sig_msg_c0000000.h"
#include "modules/canbus/vehicle/kinglong/protocol/wheelspeed_feedback_98fe6eab.h"

namespace apollo {
namespace canbus {
namespace kinglong {

KinglongMessageManager::KinglongMessageManager() {
  // Control Messages
  AddSendProtocolData<Brakenboostctrl98ff9197, true>();
  AddSendProtocolData<Controllerparking98ff8ca9, true>();
  AddSendProtocolData<Controllerpedalcmd98ff84a9, true>();
  AddSendProtocolData<Controllerstatusrequset98ff86a9, true>();
  AddSendProtocolData<Controllersteeringcmd98ff82a9, true>();

  // Report Messages
  AddRecvProtocolData<Breaksystemfeedback98ff87ab, true>();
  AddRecvProtocolData<Busbatterymeg98fa1017, true>();
  AddRecvProtocolData<Businteligentcontrolstatus98fa0117, true>();
  AddRecvProtocolData<Busmileage98fee017, true>();
  AddRecvProtocolData<Busvehiclespeedmsg8cfe6c17, true>();
  AddRecvProtocolData<Busvehiclestatus98fa0517, true>();
  AddRecvProtocolData<Epsfeedback98ff83aa, true>();
  AddRecvProtocolData<Parkingmodefeedback98ff8dac, true>();
  AddRecvProtocolData<Soc98ffeb97, true>();
  AddRecvProtocolData<Vcubasicmessage98ffea97, true>();
  AddRecvProtocolData<Vcubreaksyscmd98ff85a7, true>();
  AddRecvProtocolData<Vcudrivefeedback98ff7097, true>();
  AddRecvProtocolData<Vectorindependentsigmsgc0000000, true>();
  AddRecvProtocolData<Wheelspeedfeedback98fe6eab, true>();
}

KinglongMessageManager::~KinglongMessageManager() {}

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
