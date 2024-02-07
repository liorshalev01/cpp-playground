#include <gtest/gtest.h>

const auto encrypt_key = 0xFF;

void encrypt(const char* source_buffer, char* destination_buffer, int size) {
  std::transform(source_buffer, source_buffer + size, destination_buffer,
                 [](char c) { return c ^ encrypt_key; });
}

void decrypt(char* buffer, int size) {
  std::transform(buffer, buffer + size, buffer, [](char c ) { return c ^ encrypt_key; });
}

TEST(TransformTest, Transform) {
  const char buffer[10] = "hello";
  auto encrypted_buffer = std::make_unique<char[]>(5);

  encrypt(buffer, encrypted_buffer.get(), 5);

  decrypt(encrypted_buffer.get(), 5);
  EXPECT_STREQ(encrypted_buffer.get(), buffer);
}
