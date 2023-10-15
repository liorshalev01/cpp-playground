#include <gtest/gtest.h>

namespace {

class A {
 public:
  void MemberOfA() {}

 private:
  int data_of_a;
};

class B : public A {
 public:
  void MemberOfB() {}

 private:
  int data_of_b;
};

TEST(ClassTest, DirectInitTest) {
  B b{};
  b.MemberOfA();
  b.MemberOfB();
  std::cout << std::endl;
}

}  // namespace
