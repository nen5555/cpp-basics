cmake_minimum_required(VERSION 3.16)
project(opencv_practice CXX)
set(CMAKE_CXX_STANDARD 17)

# 告诉 find_package 去哪里找 OpenCV 的配置文件
set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/../third_party/opencv/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
message(STATUS "OpenCV include: ${OpenCV_INCLUDE_DIRS}")

add_executable(main src/main.cpp src/geometry.cpp)
target_include_directories(main PRIVATE include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${OpenCV_LIBS})