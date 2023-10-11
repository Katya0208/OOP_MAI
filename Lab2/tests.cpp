#include <gtest/gtest.h>

#include "binary.hpp"  // Подключаем заголовочный файл с объявлением класса
// Binary

TEST(BinaryTest1, Addition) {
  unsigned char number1[] = {1, 1, 1};
  unsigned char number2[] = {1, 1, 0};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary sum = N1 + N2;

  // Проверяем, что результат сложения равен ожидаемому значению
  unsigned char expected_sum[] = {1, 1, 0, 1};
  Binary expected(sizeof(expected_sum) / sizeof(expected_sum[0]), expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest2, Addition) {
  unsigned char number1[] = {1, 1, 1, 1};
  unsigned char number2[] = {1, 1, 0};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary sum = N1 + N2;

  // Проверяем, что результат сложения равен ожидаемому значению
  unsigned char expected_sum[] = {1, 0, 1, 0, 1};
  Binary expected(sizeof(expected_sum) / sizeof(expected_sum[0]), expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest3, Addition) {
  unsigned char number1[] = {1, 1, 1, 1};
  unsigned char number2[] = {1, 1, 0, 1, 1};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary sum = N1 + N2;

  // Проверяем, что результат сложения равен ожидаемому значению
  unsigned char expected_sum[] = {1, 0, 1, 0, 1, 0};
  Binary expected(sizeof(expected_sum) / sizeof(expected_sum[0]), expected_sum);
  ASSERT_TRUE(sum == expected);
}

TEST(BinaryTest4, Subtraction) {
  unsigned char number1[] = {1, 1, 1};
  unsigned char number2[] = {1, 1, 0};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary diff = N1 - N2;

  // Проверяем, что результат вычитания равен ожидаемому значению
  unsigned char expected_diff[] = {0, 0, 1};
  Binary expected(sizeof(expected_diff) / sizeof(expected_diff[0]),
                  expected_diff);
  ASSERT_TRUE(diff == expected);
}

TEST(BinaryTest5, Subtraction) {
  unsigned char number1[] = {1, 1, 1};
  unsigned char number2[] = {1, 1, 0, 1};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary diff = N1 - N2;

  // Проверяем, что результат вычитания равен ожидаемому значению
  unsigned char expected_diff[] = {0, 1, 1, 0};
  Binary expected(sizeof(expected_diff) / sizeof(expected_diff[0]),
                  expected_diff);
  ASSERT_TRUE(diff == expected);
}

TEST(BinaryTest6, Subtraction) {
  unsigned char number1[] = {1, 1, 1, 1};
  unsigned char number2[] = {1, 1, 0, 1};
  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);
  Binary diff = N1 - N2;

  // Проверяем, что результат вычитания равен ожидаемому значению
  unsigned char expected_diff[] = {0, 0, 1, 0};
  Binary expected(sizeof(expected_diff) / sizeof(expected_diff[0]),
                  expected_diff);
  ASSERT_TRUE(diff == expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
