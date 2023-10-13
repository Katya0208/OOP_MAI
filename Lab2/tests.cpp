#include <gtest/gtest.h>

#include "binary.hpp"

TEST(BinaryTest1, Addition) {
  int number1[] = {1, 1, 1};
  int number2[] = {1, 1, 0};
  Binary N1(3, number1);
  Binary N2(3, number2);
  Binary sum = N1 + N2;

  int expected_sum[] = {1, 1, 0, 1};
  Binary expected(4, expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest2, Addition) {
  int number1[] = {1, 1, 1, 1};
  int number2[] = {1, 1, 0};
  Binary N1(4, number1);
  Binary N2(3, number2);
  Binary sum = N1 + N2;

  int expected_sum[] = {1, 0, 1, 0, 1};
  Binary expected(5, expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest3, Addition) {
  int number1[] = {1, 1, 1, 1};
  int number2[] = {1, 1, 0, 1, 1};
  Binary N1(4, number1);
  Binary N2(5, number2);
  Binary sum = N1 + N2;

  int expected_sum[] = {1, 0, 1, 0, 1, 0};
  Binary expected(6, expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest4, Subtraction) {
  int number1[] = {1, 1, 1};
  int number2[] = {1, 1, 0};
  Binary N1(3, number1);
  Binary N2(3, number2);
  Binary diff = N1 - N2;

  int expected_diff[] = {0, 0, 1};
  Binary expected(3, expected_diff);
  ASSERT_TRUE(diff == expected);
}

TEST(BinaryTest5, Subtraction) {
  int number1[] = {1, 1, 1};
  int number2[] = {1, 1, 0, 1};
  Binary N1(3, number1);
  Binary N2(4, number2);
  Binary diff = N1 - N2;

  int expected_diff[] = {0, 1, 1, 0};
  Binary expected(4, expected_diff);
  ASSERT_TRUE(diff == expected);
}

TEST(BinaryTest6, Subtraction) {
  int number1[] = {1, 1, 1, 1};
  int number2[] = {1, 1, 0, 1};
  Binary N1(4, number1);
  Binary N2(4, number2);
  Binary diff = N1 - N2;

  int expected_diff[] = {0, 0, 1, 0};
  Binary expected(4, expected_diff);
  ASSERT_TRUE(diff == expected);
}

TEST(BinaryTest7, Comparison) {
  int number1[] = {1, 1, 0, 1};
  int number2[] = {1, 1, 0, 0};
  Binary N1(4, number1);
  Binary N2(4, number2);
  ASSERT_TRUE(N1 == N1);
  ASSERT_FALSE(N1 == N2);

  ASSERT_TRUE(N1 > N2);
  ASSERT_FALSE(N1 > N1);
  ASSERT_FALSE(N2 > N1);

  ASSERT_TRUE(N2 < N1);
  ASSERT_FALSE(N1 < N1);
  ASSERT_FALSE(N1 < N2);

  ASSERT_TRUE(N1 >= N1);
  ASSERT_TRUE(N1 >= N2);
  ASSERT_FALSE(N2 >= N1);

  ASSERT_TRUE(N2 <= N2);
  ASSERT_TRUE(N2 <= N1);
  ASSERT_FALSE(N1 <= N2);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
