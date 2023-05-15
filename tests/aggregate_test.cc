#include <gtest/gtest.h>

#include <string>
#include <vector>

struct Aggregate {
  int a{};
  std::string b{};
  std::vector<std::string> c{};
};

TEST(AggregateTest, DefaultConstructor) {
  Aggregate aggregate{.c = {"hello"}};
  EXPECT_EQ(aggregate.a, 0);
  EXPECT_EQ(aggregate.b, "");
  EXPECT_EQ(aggregate.c.size(), 1);
}
