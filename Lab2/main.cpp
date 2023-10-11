#include <iostream>

#include "binary.hpp"
using namespace std;

#define GREEN_COLOR "\x1b[32m"

// Функция для ввода двоичного числа с клавиатуры
Binary InputBinaryNumber() {
  string binaryInput;

  cin >> binaryInput;

  // Парсим строку и создаем объект Binary
  unsigned int length = binaryInput.length();
  unsigned char* binaryArray = new unsigned char[length];
  for (int i = 0; i < length; i++) {
    binaryArray[i] =
        binaryInput[i] - '0';  // Преобразуем символы '0' и '1' в числа
  }

  Binary binaryNumber(length, binaryArray);
  delete[] binaryArray;
  return binaryNumber;
}

int main() {
  cout << "Введите двоичное число N1:" << endl;
  Binary N1 = InputBinaryNumber();

  cout << "Введите двоичное число N2:" << endl;
  Binary N2 = InputBinaryNumber();
  printf(GREEN_COLOR);
  cout << endl;
  std::cout << "Содержимое массива N1: ";
  N1.Print();

  std::cout << "Содержимое массива N2: ";
  N2.Print();

  cout << "Проверка на равенство: ";
  if (N1 == N2) {
    std::cout << "Двоичные числа равны!" << std::endl;
  } else {
    std::cout << "Упс, числа разные" << std::endl;
  }

  Binary sum = N1 + N2;
  Binary diff = N1 - N2;

  std::cout << "Сумма N1 и N2: ";
  sum.Print();

  std::cout << "Разность N1 и N2: ";
  diff.Print();
  cout << "число1 > число2? ";
  if (N1 > N2) {
    printf(GREEN_COLOR);
    cout << "Да" << endl;
  } else {
    cout << "Нет" << endl;
  }
  cout << "число1 < число2? ";
  if (N1 < N2) {
    cout << "Да" << endl;
  } else {
    cout << "Нет" << endl;
  }

  return 0;
}
