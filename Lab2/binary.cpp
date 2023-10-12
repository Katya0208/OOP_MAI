#include <iostream>
using namespace std;
#include "binary.hpp"

void resizeArray(int *&data, int oldSize, int newSize, int value) {
  int *newData = new int[newSize];  // Создаем новый массив размером newSize
  int razn = newSize - oldSize;
  // Заполняем новый массив нулями

  for (int i = 0; i < newSize; i++) {
    newData[i] = value;
  }
  for (int i = razn; i < newSize; i++) {
    newData[i] = data[i - razn];  // Копируем старые значения
  }

  data = newData;  // Переключаем указатель на новый массив
}

Binary::Binary(int size, int *values) {  // Конструктор
  this->Size = size;
  this->data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = values[i];
  }
  //  cout << "Вызвался конструктор " << this << endl;
}

Binary::Binary(const Binary &other) {  // конструктор копирования
  this->Size = other.Size;
  this->data = new int[other.Size];
  for (int i = 0; i < other.Size; i++) {
    this->data[i] = other.data[i];
  }
  //  cout << "Вызвался конструктор копирования " << this << endl;
}

Binary &Binary::operator=(
    const Binary &other) {  // перегрузка оператора присваивания
  // cout << "Вызвался оператор = " << this << endl;
  this->Size = other.Size;
  if (this->data != nullptr) {
    delete[] this->data;
  }

  this->data = new int[other.Size];
  for (int i = 0; i < other.Size; i++) {
    this->data[i] = other.data[i];
  }
  return *this;
}

bool Binary::operator==(const Binary &other) const {
  if (this->Size != other.Size) {
    return false;  // Если размеры разные, они точно не равны.
  }

  for (size_t i = 0; i < Size; ++i) {
    if (this->data[i] != other.data[i]) {
      return false;  // Если найдено несовпадение, массивы не равны.
    }
  }

  return true;  // Если размеры одинаковы и все элементы совпадают, массивы
                // равны.
}

Binary Binary::operator+(const Binary &other) const {
  size_t size = max(Size, other.Size);
  Binary result(size, new int[size]{});
  int *a = this->data;
  int *b = other.data;

  if (this->Size < size) {
    resizeArray(a, this->Size, size, 0);
  }

  if (other.Size < size) {
    resizeArray(b, other.Size, size, 0);
  }

  int carry = 0;
  for (int i = size - 1; i >= 0; i--) {
    int sum = carry + a[i] + b[i];
    result.data[i] = sum % 2;
    carry = sum / 2;
  }

  if (carry > 0) {
    size = size + 1;
    resizeArray(result.data, result.Size, size, carry);
    result.Size = size;
  }

  return result;
}

Binary Binary::operator-(const Binary &other) const {
  size_t size = max(Size, other.Size);
  Binary result(size, new int[size]{});
  int *a = this->data;
  int *b = other.data;

  if (this->Size < size) {
    resizeArray(a, this->Size, size, 0);
  }
  if (other.Size < size) {
    resizeArray(b, other.Size, size, 0);
  }

  if (*this < other) {
    swap(a, b);
  }

  int borrow = 0;
  for (int i = size - 1; i >= 0; i--) {
    int diff = a[i] - b[i] - borrow;
    if (diff < 0) {
      diff += 2;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result.data[i] = diff;
  }

  return result;
}

bool Binary::operator<(const Binary &other) const {
  size_t size = max(Size, other.Size);

  int *a = this->data;
  int *b = other.data;

  if (this->Size < size) {
    resizeArray(a, this->Size, size, 0);
  }
  if (other.Size < size) {
    resizeArray(b, other.Size, size, 0);
  }

  for (size_t i = 0; i < size; i++) {
    if (a[i] < b[i]) {
      return true;  // a < b
    } else if (a[i] > b[i]) {
      return false;  // a > b
    }
  }

  return false;  // a == b
}

bool Binary::operator>(const Binary &other) const {
  return !(*this < other) && !(*this == other);
}

bool Binary::operator>=(const Binary &other) const { return !(*this < other); }

bool Binary::operator<=(const Binary &other) const { return !(*this > other); }

void Binary::Print() {
  for (int i = 0; i < Size; i++) {
    cout << data[i] << "";
  }
  cout << endl;
}

Binary::~Binary() {
  // cout << "Вызвался деструктор " << this << endl;
  delete[] data;
}