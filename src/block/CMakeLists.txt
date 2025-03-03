cmake_minimum_required(VERSION 3.8)
project(block)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(src SOURCES)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(${PROJECT_NAME} SHARED ${SOURCES})

rclcpp_components_register_node(${PROJECT_NAME}
                                PLUGIN "block::PublisherNode")

ament_auto_package()
