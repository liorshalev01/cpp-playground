#include <gtest/gtest.h>

#include <list>
#include <string>

class A {
 public:
  explicit A(int value) : value_(value) {
    std::cout << "ClassA::ClassA()" << std::endl;
  }

  ~A() = default;

  A(const A&) = default;

  A& operator=(const A& rhs) {
    std::cout << "ClassA::operator=()" << std::endl;
    value_ = rhs.value_;
    return *this;
  }

  A(A&&) = default;
  A& operator=(A&&) noexcept;

 private:
  int value_;
};

TEST(InitTest, DirectInitTest) {
  A class_a{1};
}

TEST(InitTest, CopyInitTest) {
  A class_a = A{1};
}

TEST(InitTest, AssignmentTest) {
  A class_a1{1};
  A class_a2{2};
  class_a2 = class_a1;
}
