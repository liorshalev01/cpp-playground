cmake_minimum_required(VERSION 3.25)
project(playground)

set(CMAKE_CXX_STANDARD 20)
# add_compile_options(
#   -nostdinc++
#   -I /Users/liors/Talon/chromium/src/buildtools/third_party/libc++
#   -isystem /Users/liors/Talon/chromium/src/buildtools/third_party/libc++/trunk/include
#   -isystem /Users/liors/Talon/chromium/src/buildtools/third_party/libc++abi/trunk/include)

include(cmake/googletest.cmake)

add_executable(
  playground
  src/main.cc)

add_executable(
  playground_test
  tests/class_test.cc
  tests/init_test.cc
  tests/list_test.cc
  tests/iterator_test.cc
  tests/reference_test.cc)

target_link_libraries(
  playground_test
  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(playground_test)
