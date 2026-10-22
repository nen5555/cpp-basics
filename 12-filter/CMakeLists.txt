cmake_minimum_required(VERSION 3.16)
project(filter CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenCV_DIR ${CMAKE_SOURCE_DIR}/../third_party/opencv/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)

set(WARN_FLAGS -Wall -Wextra -Wshadow -Werror=return-type -g -fsanitize=address,undefined)

add_executable(main main.cpp)
target_include_directories(main PRIVATE include)
target_link_libraries(main PRIVATE ${OpenCV_LIBS})
target_compile_options(main PRIVATE ${WARN_FLAGS})
target_link_options(main PRIVATE -fsanitize=address,undefined)