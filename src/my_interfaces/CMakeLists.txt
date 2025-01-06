cmake_minimum_required(VERSION 3.8)
project(my_interfaces)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Posture.msg"
  "msg/PostureArray.msg"
  DEPENDENCIES builtin_interfaces
)

ament_auto_package()

