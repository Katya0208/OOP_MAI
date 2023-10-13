#include <iostream>
using namespace std;
#include "binary.hpp"

void resizeArray(int *&data, int oldSize, int newSize, int value) {
  int *newData = new int[newSize];
  int razn = newSize - oldSize;

  for (int i = 0; i < newSize; i++) {
    newData[i] = value;
  }
  for (int i = razn; i < newSize; i++) {
    newData[i] = data[i - razn];
  }

  data = newData;
}

Binary::Binary(int size, int *values) {
  this->Size = size;
  this->data = new int[size];
  for (int i = 0; i < size; i++) {
    data[i] = values[i];
  }
}

Binary::Binary(const Binary &other) {
  this->Size = other.Size;
  this->data = new int[other.Size];
  for (int i = 0; i < other.Size; i++) {
    this->data[i] = other.data[i];
  }
}

Binary &Binary::operator=(const Binary &other) {
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
    return false;
  }

  for (size_t i = 0; i < Size; ++i) {
    if (this->data[i] != other.data[i]) {
      return false;
    }
  }

  return true;
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
      return true;
    } else if (a[i] > b[i]) {
      return false;
    }
  }

  return false;
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

Binary::~Binary() { delete[] data; }