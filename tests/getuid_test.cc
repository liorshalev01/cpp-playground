#include <gtest/gtest.h>

TEST(GetuidTest, GetUid) {
  EXPECT_EQ(0, getuid());
}

TEST(GetuidTest, GetEUid) {
  EXPECT_EQ(0, geteuid());
}
