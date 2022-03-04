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

#include "modules/canbus/vehicle/kinglong/protocol/vector__independent_sig_msg_c0000000.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace kinglong {

using ::apollo::drivers::canbus::Byte;

Vectorindependentsigmsgc0000000::Vectorindependentsigmsgc0000000() {}
const int32_t Vectorindependentsigmsgc0000000::ID = 0x20000000;

void Vectorindependentsigmsgc0000000::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_steering_resverd3(steering_resverd3(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_steering_resverd1(steering_resverd1(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_steering_resverd2(steering_resverd2(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_new_signal_154(new_signal_154(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_new_signal_153(new_signal_153(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_busv_aircondition_status(busv_aircondition_status(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_busv_smalllamp_status(busv_smalllamp_status(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_vehicle_speed_red_byte45(bus_vehicle_speed_red_byte45(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_vehicle_speed_red_byte0123(bus_vehicle_speed_red_byte0123(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_battery_resvered_byte67(bus_battery_resvered_byte67(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_battery_resvered_byte2345(bus_battery_resvered_byte2345(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_resvered_byte67(bus_resvered_byte67(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_resvered_byte45(bus_resvered_byte45(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_bus_resvered1(bus_resvered1(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_brk_reserved_byte7(vcu_brk_reserved_byte7(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_brk_reserved_byte56(vcu_brk_reserved_byte56(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_brk_reserved_byte34(vcu_brk_reserved_byte34(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_brk_reserved1(vcu_brk_reserved1(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_basic_resvered(vcu_basic_resvered(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_basic_resvered_byte23(vcu_basic_resvered_byte23(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_vcu_drive_reserved1(vcu_drive_reserved1(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_pmf_resvered_byte56(pmf_resvered_byte56(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_pmf_resvered_byte34(pmf_resvered_byte34(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_pmf_resvered_byte12(pmf_resvered_byte12(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_eps_resvered0(eps_resvered0(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_eps_revered(eps_revered(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_defaulr_code(sp_defaulr_code(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_revered_byte6(sp_revered_byte6(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_revered_byte45(sp_revered_byte45(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_revered_byte23(sp_revered_byte23(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_rtk_power_fb(sp_rtk_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_fullview_power_fb(sp_fullview_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_mobieye_power_fb(sp_mobieye_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_mmradar_power_fb(sp_mmradar_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_ultrasonicradar_power_fb(sp_ultrasonicradar_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_bsdradar_power_fb(sp_bsdradar_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_singlelindlidar_power_fb(sp_singlelindlidar_power_fb(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sp_16lidar_power_feedback(sp_16lidar_power_feedback(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_sr_resverd_byte7(sr_resverd_byte7(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_pedal_resverd3(pedal_resverd3(bytes, length));
  chassis->mutable_kinglong()->mutable_vector__independent_sig_msg_c0000000()->set_pedal_resverd1(pedal_resverd1(bytes, length));
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'steering_resverd3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::steering_resverd3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'steering_resverd1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::steering_resverd1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'steering_resverd2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::steering_resverd2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'new_signal_154', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::new_signal_154(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'new_signal_153', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::new_signal_153(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'busv_aircondition_status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::busv_aircondition_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'busv_smalllamp_status', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::busv_smalllamp_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'bus_vehicle_speed_red_byte45', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_vehicle_speed_red_byte45(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 32, 'name': 'bus_vehicle_speed_red_byte0123', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_vehicle_speed_red_byte0123(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 1);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t3(bytes + 0);
  t = t3.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'bus_battery_resvered_byte67', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_battery_resvered_byte67(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 32, 'name': 'bus_battery_resvered_byte2345', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_battery_resvered_byte2345(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 1);
  t = t2.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t3(bytes + 0);
  t = t3.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'bus_resvered_byte67', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_resvered_byte67(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'bus_resvered_byte45', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_resvered_byte45(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'bus_resvered1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::bus_resvered1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'vcu_brk_reserved_byte7', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_brk_reserved_byte7(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'vcu_brk_reserved_byte56', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_brk_reserved_byte56(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'vcu_brk_reserved_byte34', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_brk_reserved_byte34(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 6, 'name': 'vcu_brk_reserved1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_brk_reserved1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 6);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 1, 'name': 'vcu_basic_resvered', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vectorindependentsigmsgc0000000::vcu_basic_resvered(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'vcu_basic_resvered_byte23', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_basic_resvered_byte23(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 6, 'name': 'vcu_drive_reserved1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::vcu_drive_reserved1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 6);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'pmf_resvered_byte56', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65535]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::pmf_resvered_byte56(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'pmf_resvered_byte34', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|65535]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::pmf_resvered_byte34(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'pmf_resvered_byte12', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::pmf_resvered_byte12(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'eps_resvered0', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::eps_resvered0(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 4, 'name': 'eps_revered', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::eps_revered(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'sp_defaulr_code', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_defaulr_code(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'sp_revered_byte6', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_revered_byte6(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'sp_revered_byte45', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_revered_byte45(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 16, 'name': 'sp_revered_byte23', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_revered_byte23(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 0);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_rtk_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_rtk_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_fullview_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_fullview_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_mobieye_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_mobieye_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_mmradar_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_mmradar_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_ultrasonicradar_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_ultrasonicradar_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_bsdradar_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_bsdradar_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_singlelindlidar_power_fb', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_singlelindlidar_power_fb(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 2, 'name': 'sp_16lidar_power_feedback', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sp_16lidar_power_feedback(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'sr_resverd_byte7', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::sr_resverd_byte7(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 8, 'name': 'pedal_resverd3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::pedal_resverd3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'is_signed_var': False, 'len': 6, 'name': 'pedal_resverd1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vectorindependentsigmsgc0000000::pedal_resverd1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 6);

  int ret = x;
  return ret;
}
}  // namespace kinglong
}  // namespace canbus
}  // namespace apollo
