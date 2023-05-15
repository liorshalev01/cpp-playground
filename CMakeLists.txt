cmake_minimum_required(VERSION 3.25)
project(playground)

set(CMAKE_CXX_STANDARD 17)

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
  tests/reference_test.cc
  tests/aggregate_test.cc)

target_link_libraries(
  playground_test
  GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(playground_test)
