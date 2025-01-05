cmake_minimum_required(VERSION 3.8)
project(block)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
 
# C/C++ configuration "compileCommands": "${workspaceFolder}/build/compile_commands.json"
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

# find all source files automatically
aux_source_directory(src SOURCES)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(block ${SOURCES})

# add dependencies to executable by <depend>
ament_target_dependencies(block rclcpp std_msgs)

# install the executable to lib/${PROJECT_NAME}
install(TARGETS block 
        DESTINATION lib/${PROJECT_NAME})

ament_package()
