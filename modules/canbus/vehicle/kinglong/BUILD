load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "kinglong_vehicle_factory",
    srcs = [
        "kinglong_vehicle_factory.cc",
    ],
    hdrs = [
        "kinglong_vehicle_factory.h",
    ],
    deps = [
        ":kinglong_controller",
        ":kinglong_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "kinglong_message_manager",
    srcs = [
        "kinglong_message_manager.cc",
    ],
    hdrs = [
        "kinglong_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/kinglong/protocol:canbus_kinglong_protocol",
    ],
)

cc_library(
    name = "kinglong_controller",
    srcs = [
        "kinglong_controller.cc",
    ],
    hdrs = [
        "kinglong_controller.h",
    ],
    deps = [
        ":kinglong_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/canbus/proto:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/kinglong/protocol:canbus_kinglong_protocol",
    ],
)

cpplint()
