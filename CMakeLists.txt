cmake_minimum_required(VERSION 3.25)
project(playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/googletest.cmake)

add_executable(
  playground_test
  src/list_test.cc)

target_link_libraries(
  playground_test
  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(playground_test)
