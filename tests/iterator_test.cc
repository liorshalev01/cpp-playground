#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

auto GetTestVector() {
  auto test_list = std::vector<std::string>{};
  test_list.emplace_back("1");
  test_list.emplace_back("2");

  auto value = std::string("3");
  const auto& value2 = value;
  test_list.emplace_back(value2);
  return test_list;
}

template <typename Container>
void ForEach(const Container& container) {
  std::for_each(container.begin(), container.end(), [](auto value) { std::cout << value << std::endl; });
}

TEST(Iterator, IteratorTest) {
  auto test_vector = GetTestVector();
  ForEach(test_vector);
}
