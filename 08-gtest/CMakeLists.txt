cmake_minimum_required(VERSION 3.16)
project(gtest_practice CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(${CMAKE_SOURCE_DIR}/../third_party/googletest
                 ${CMAKE_BINARY_DIR}/googletest)


add_library(core src/ring_buffer.cpp src/geometry.cpp)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(core PRIVATE -Wall -Wextra -Wshadow -Werror=return-type -g -fsanitize=address,undefined)



add_executable(tests
    tests/test_ring_buffer.cpp
    tests/test_geometry.cpp
)
target_link_libraries(tests PRIVATE core GTest::gtest_main)
target_compile_options(tests PRIVATE -Wall -Wextra -g -fsanitize=address,undefined)
target_link_options(tests PRIVATE -fsanitize=address,undefined)

# ④ 注册测试
enable_testing()
include(GoogleTest)
gtest_discover_tests(tests)