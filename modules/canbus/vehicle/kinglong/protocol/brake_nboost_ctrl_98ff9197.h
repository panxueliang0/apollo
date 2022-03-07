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

class Brakenboostctrl98ff9197 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Brakenboostctrl98ff9197();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'AEB_BrkPelPosDes', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.01, 'type': 'double'}
  Brakenboostctrl98ff9197* set_aeb_brkpelposdes(double aeb_brkpelposdes);

 private:

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 16, 'name': 'AEB_BrkPelPosDes', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 0.01, 'type': 'double'}
  void set_p_aeb_brkpelposdes(uint8_t* data, double aeb_brkpelposdes);

 private:
  double aeb_brkpelposdes_;
};

}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo


