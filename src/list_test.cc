#include <gtest/gtest.h>

#include <list>
#include <string>

auto GetTestList() {
  auto test_list = std::list<std::string>{};
  test_list.emplace_back("1");
  test_list.emplace_back("2");

  auto value = std::string("3");
  const auto& value2 = value;
  test_list.emplace_back(value2);
  return test_list;
}

TEST(ListTest, Playground) {
  auto test_list = GetTestList();
  EXPECT_EQ(test_list.size(), 3);
}
