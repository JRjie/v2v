cmake_minimum_required(VERSION 3.8)
project(posture_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# find all source files automatically
aux_source_directory(src SOURCES)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

find_package(Boost REQUIRED COMPONENTS system)

ament_auto_add_library(${PROJECT_NAME} SHARED ${SOURCES})

target_link_libraries(posture_simulator Boost::system)

ament_auto_package()
