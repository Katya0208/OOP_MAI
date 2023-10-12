#include <iostream>

#include "binary.hpp"
using namespace std;

#define GREEN_COLOR "\x1b[32m"

// Функция для ввода двоичного числа с клавиатуры
Binary InputBinaryNumber() {
  string binaryStr;
  cout << "Введите двоичное число (без пробелов): ";
  cin >> binaryStr;

  int size = binaryStr.length();
  int *values = new int[size];

  for (int i = 0; i < size; i++) {
    if (binaryStr[i] == '0') {
      values[i] = 0;
    } else if (binaryStr[i] == '1') {
      values[i] = 1;
    } else {
      cout << "Введен некорректный символ. Пожалуйста, вводите только 0 и 1."
           << endl;
      return Binary(0, nullptr);
    }
  }

  return Binary(size, values);
}

int main() {
  Binary N1 = InputBinaryNumber();

  Binary N2 = InputBinaryNumber();
  cout << "-----------------------------------------------" << endl;
  printf(GREEN_COLOR);

  cout << "Число N1: ";
  N1.Print();

  cout << "Число N2: ";
  N2.Print();

  cout << "Проверка на равенство: ";
  if (N1 == N2) {
    cout << "Двоичные числа равны!" << endl;
  } else {
    cout << "Упс, числа разные" << endl;
  }

  Binary sum = N1 + N2;
  Binary diff = N1 - N2;

  cout << "Сумма N1 и N2: ";
  sum.Print();

  cout << "Разность N1 и N2: ";
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
  cout << "число1 >= число2? ";
  if (N1 >= N2) {
    cout << "Да" << endl;
  } else {
    cout << "Нет" << endl;
  }
  cout << "число1 <= число2? ";
  if (N1 <= N2) {
    cout << "Да" << endl;
  } else {
    cout << "Нет" << endl;
  }

  return 0;
}