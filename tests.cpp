#include <gtest/gtest.h>

#include "function.hpp"

TEST(test01, numbers) {
  std::string s = "sdfg12sdf34";
  choosing_numbers(s);
  ASSERT_TRUE("1234" == s);
}

TEST(test02, numbers) {
  std::string s = "AD1111DDDFsdfsdg345632";
  choosing_numbers(s);
  ASSERT_TRUE("1111345632" == s);
}

TEST(test03, numbers) {
  std::string s = "sdgfghhk";
  choosing_numbers(s);
  ASSERT_TRUE("" == s);
}

TEST(test04, numbers) {
  std::string s = "12523";
  choosing_numbers(s);
  ASSERT_TRUE("12523" == s);
}

TEST(test05, numbers) {
  std::string s = "";
  choosing_numbers(s);
  ASSERT_TRUE("" == s);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}