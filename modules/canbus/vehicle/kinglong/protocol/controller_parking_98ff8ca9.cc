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

#include "modules/canbus/vehicle/kinglong/protocol/controller_parking_98ff8ca9.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace kinglong {

using ::apollo::drivers::canbus::Byte;

const int32_t Controllerparking98ff8ca9::ID = 0x38ff8ca9;

// public
Controllerparking98ff8ca9::Controllerparking98ff8ca9() { Reset(); }

uint32_t Controllerparking98ff8ca9::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Controllerparking98ff8ca9::UpdateData(uint8_t* data) {
  set_p_cp_epb_enable(data, cp_epb_enable_);
  set_p_cp_park_active(data, cp_park_active_);
}

void Controllerparking98ff8ca9::Reset() {
  // TODO(All) :  you should check this manually
  cp_epb_enable_ = 0;
  cp_park_active_ = 0;
}

Controllerparking98ff8ca9* Controllerparking98ff8ca9::set_cp_epb_enable(
    int cp_epb_enable) {
  cp_epb_enable_ = cp_epb_enable;
  return this;
 }

// config detail: {'bit': 4, 'is_signed_var': False, 'len': 4, 'name': 'CP_EPB_Enable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Controllerparking98ff8ca9::set_p_cp_epb_enable(uint8_t* data,
    int cp_epb_enable) {
  cp_epb_enable = ProtocolData::BoundedValue(0, 0, cp_epb_enable);
  int x = cp_epb_enable;

  Byte to_set(data + 0);
  to_set.set_value(x, 4, 4);
}


Controllerparking98ff8ca9* Controllerparking98ff8ca9::set_cp_park_active(
    int cp_park_active) {
  cp_park_active_ = cp_park_active;
  return this;
 }

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 4, 'name': 'CP_Park_ACTIVE', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Controllerparking98ff8ca9::set_p_cp_park_active(uint8_t* data,
    int cp_park_active) {
  cp_park_active = ProtocolData::BoundedValue(0, 0, cp_park_active);
  int x = cp_park_active;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 4);
}

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
