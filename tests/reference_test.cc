#include <gtest/gtest.h>

#include <utility>

class ClassA {
 public:
  ClassA() {
    std::cout << "ClassA::ClassA()" << std::endl;
  }

  ~ClassA() = default;

  ClassA(const ClassA&) {
    std::cout << "ClassA::ClassA(const ClassA&)" << std::endl;
  }

  ClassA(ClassA&&) noexcept {
    std::cout << "ClassA::ClassA(ClassA&&)" << std::endl;
  }

  ClassA& operator=(const ClassA&) {
    std::cout << "ClassA::operator=(const ClassA&)" << std::endl;
    return *this;
  }

  ClassA& operator=(ClassA&&) noexcept {
    std::cout << "ClassA::operator=(const ClassA&&)" << std::endl;
    return *this;
  }
};

class ClassB {
 public:
  ClassB() {
    std::cout << "ClassB::ClassB()" << std::endl;
  }

  explicit ClassB(ClassA class_a) : class_a_(std::move(class_a)) {
    std::cout << "ClassB::ClassB(ClassA)" << std::endl;
  }

 private:
  ClassA class_a_;
  std::string value_;
};

TEST(ReferenceTest, Ctor) {
  auto class_a = ClassA();
};

TEST(ReferenceTest, CopyCtor) {
  auto class_a1 = ClassA();
  auto class_a2 = ClassA(class_a1);
};

TEST(ReferenceTest, MoveCtor) {
  auto class_a2 = ClassA(ClassA());
};

TEST(ReferenceTest, CopyAssignment) {
  auto class_a1 = ClassA();
  auto class_a2 = ClassA();
  class_a2 = class_a1;
};

TEST(ReferenceTest, MoveAssignment) {
  auto class_a1 = ClassA();
  auto class_a2 = ClassA();
  class_a2 = std::move(class_a1);
};

TEST(ReferenceTest, CtorLValue) {
  auto class_a = ClassA();
  auto class_b = ClassB(class_a);
};

TEST(ReferenceTest, CtorRValue1) {
  auto class_b = ClassB(ClassA());
};

TEST(ReferenceTest, CtorRValue2) {
  auto class_a = ClassA();
  auto class_b = ClassB(std::move(class_a));
};
