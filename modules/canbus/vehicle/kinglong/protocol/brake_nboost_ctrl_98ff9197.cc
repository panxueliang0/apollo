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

#include "modules/canbus/vehicle/kinglong/protocol/brake_nboost_ctrl_98ff9197.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace kinglong {

using ::apollo::drivers::canbus::Byte;

const int32_t Brakenboostctrl98ff9197::ID = 0x38ff9197;

// public
Brakenboostctrl98ff9197::Brakenboostctrl98ff9197() { Reset(); }

uint32_t Brakenboostctrl98ff9197::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Brakenboostctrl98ff9197::UpdateData(uint8_t* data) {
  set_p_aeb_brkpelposdes(data, aeb_brkpelposdes_);
}

void Brakenboostctrl98ff9197::Reset() {
  // TODO(All) :  you should check this manually
  aeb_brkpelposdes_ = 0.0;
}

Brakenboostctrl98ff9197* Brakenboostctrl98ff9197::set_aeb_brkpelposdes(
    double aeb_brkpelposdes) {
  aeb_brkpelposdes_ = aeb_brkpelposdes;
  return this;
 }

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'AEB_BrkPelPosDes', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.01, 'type': 'double'}
void Brakenboostctrl98ff9197::set_p_aeb_brkpelposdes(uint8_t* data,
    double aeb_brkpelposdes) {
  aeb_brkpelposdes = ProtocolData::BoundedValue(0.0, 0.0, aeb_brkpelposdes);
  int x = aeb_brkpelposdes / 0.010000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 2);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xFF;
  Byte to_set1(data + 3);
  to_set1.set_value(t, 0, 8);
}

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
