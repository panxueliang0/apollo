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

#include "modules/canbus/vehicle/kinglong/protocol/wheelspeed_feedback_98fe6eab.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace kinglong {

using ::apollo::drivers::canbus::Byte;

Wheelspeedfeedback98fe6eab::Wheelspeedfeedback98fe6eab() {}
const int32_t Wheelspeedfeedback98fe6eab::ID = 0x38fe6eab;

void Wheelspeedfeedback98fe6eab::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_kinglong()->mutable_wheelspeed_feedback_98fe6eab()->set_ws_rearright_wheelspeed(ws_rearright_wheelspeed(bytes, length));
  chassis->mutable_kinglong()->mutable_wheelspeed_feedback_98fe6eab()->set_ws_rearleft_wheelspeed(ws_rearleft_wheelspeed(bytes, length));
  chassis->mutable_kinglong()->mutable_wheelspeed_feedback_98fe6eab()->set_ws_frontright_wheelspeed(ws_frontright_wheelspeed(bytes, length));
  chassis->mutable_kinglong()->mutable_wheelspeed_feedback_98fe6eab()->set_ws_frontleft_wheelspeed(ws_frontleft_wheelspeed(bytes, length));
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 16, 'name': 'ws_rearright_wheelspeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.00390625, 'type': 'double'}
double Wheelspeedfeedback98fe6eab::ws_rearright_wheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.003906;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 16, 'name': 'ws_rearleft_wheelspeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.00390625, 'type': 'double'}
double Wheelspeedfeedback98fe6eab::ws_rearleft_wheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.003906;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'ws_frontright_wheelspeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.00390625, 'type': 'double'}
double Wheelspeedfeedback98fe6eab::ws_frontright_wheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.003906;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'ws_frontleft_wheelspeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.00390625, 'type': 'double'}
double Wheelspeedfeedback98fe6eab::ws_frontleft_wheelspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.003906;
  return ret;
}
}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
