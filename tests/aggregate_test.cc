#include <gtest/gtest.h>

#include <string>
#include <vector>

struct Aggregate {
  Aggregate() = default;
  ~Aggregate() = default;

  Aggregate(const Aggregate&) = default;
  Aggregate& operator=(const Aggregate&) = default;

  Aggregate(Aggregate&&) = default;
  Aggregate& operator=(Aggregate&&) = default;

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
