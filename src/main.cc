#include <algorithm>
#include <array>
#include <iostream>
#include <string>

template <std::array UrlPrefix, int Length>
constexpr std::array<char, Length> GenerateUrlOfLength() {
  static_assert(Length > sizeof(UrlPrefix) + 1);
  auto url = std::array<char, Length>{};
  std::copy_n(UrlPrefix.begin(), UrlPrefix.size(), url.begin());
  std::fill_n(url.begin() + sizeof(UrlPrefix), Length - sizeof(UrlPrefix), '*');
  return url;
}

constexpr std::array<char, 13> value = {"https://url1"};

int main() {
  constexpr auto url1 = GenerateUrlOfLength<value, 20>();
  // std::cout << url1 << std::endl;

  const std::string message = R"(hello world)";
  std::cout << message << std::endl;
}
