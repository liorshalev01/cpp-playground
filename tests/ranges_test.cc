#include <gtest/gtest.h>

#include <string>
#include <vector>

TEST(RangesTest, StringIncludesTest) {
  const auto s1 = std::string{"abcd"};
  const auto s2 = std::string{"cd"};
  EXPECT_TRUE(std::ranges::includes(s1, s2));
}

TEST(RangesTest, AnyOfTest) {
  const auto v1 = std::vector{std::string{"Error: App loading"}};
  EXPECT_TRUE(std::ranges::any_of(v1, [](const auto& s) { return s.find("App2") != std::string::npos; }));
}
