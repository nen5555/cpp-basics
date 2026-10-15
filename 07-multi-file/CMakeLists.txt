cmake_minimum_required(VERSION 3.16)
project(RingBuffer)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp ring_buffer.cpp)

target_compile_options(main PRIVATE -Wall -Wextra -Wshadow -Werror=return-type -g -fsanitize=address,undefined)
target_link_options(main PRIVATE -fsanitize=address,undefined)