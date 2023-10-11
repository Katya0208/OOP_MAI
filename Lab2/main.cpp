#include <iostream>

#include "binary.hpp"
using namespace std;

int main() {
  unsigned char number1[] = {1, 1, 1};
  unsigned char number2[] = {1, 1, 0, 1};

  Binary N1(sizeof(number1) / sizeof(number1[0]), number1);
  Binary N2(sizeof(number2) / sizeof(number2[0]), number2);

  std::cout << "Содержимое массива N1: ";
  N1.Print();

  std::cout << "Содержимое массива N2: ";
  N2.Print();

  if (N1 == N2) {
    std::cout << "Двоичные числа равны!" << std::endl;
  } else {
    std::cout << "Упс, числа разные" << std::endl;
  }

  Binary sum = N1 + N2;
  Binary diff = N1 - N2;

  std::cout << "Сумма N1 и N2: ";
  sum.Print();

  std::cout << "Разница N1 и N2: ";
  diff.Print();
  if (N1 < N2) {
    cout << "Да, первое число меньше второго!" << endl;
  }
  if (N1 > N2) {
    cout << "Да, первое число больше второго!" << endl;
  }

  return 0;
}
