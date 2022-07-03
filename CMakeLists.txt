project(Snake)
cmake_minimum_required(VERSION 3.18)

add_executable(snake src/main.c)

include(FetchContent)
FetchContent_Declare(
  libuv
  GIT_REPOSITORY https://github.com/libuv/libuv.git
  GIT_TAG        v1.44.1
)
FetchContent_MakeAvailable(libuv)
