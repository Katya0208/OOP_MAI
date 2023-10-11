#include <iostream>
#include <vector>
using namespace std;
#include "binary.hpp"

Binary::Binary(int size, const unsigned char* values) {
  for (int i = 0; i < size; i++) {
    if (values[i] != 0 && values[i] != 1) {
      throw std::invalid_argument("Binary values must be 0 or 1.");
    }
    data.push_back(values[i]);
  }
}

Binary Binary::operator+(const Binary& other) const {
  size_t size = std::max(data.size(), other.data.size());
  Binary result(0, nullptr);
  result.data.resize(size, 0);

  // Дополняем числа нулями до одинаковой длины
  std::vector<unsigned char> a = data;
  std::vector<unsigned char> b = other.data;
  while (a.size() < size) {
    a.insert(a.begin(), 0);
  }
  while (b.size() < size) {
    b.insert(b.begin(), 0);
  }

  int carry = 0;
  for (int i = size - 1; i >= 0; i--) {
    int sum = carry + a[i] + b[i];
    result.data[i] = sum % 2;
    carry = sum / 2;
  }

  if (carry > 0) {
    result.data.insert(result.data.begin(), 1);
  }

  return result;
}

Binary Binary::operator-(const Binary& other) const {
  // Для выполнения вычитания, нам нужно дополнить числа до одинаковой длины

  size_t size = std::max(data.size(), other.data.size());
  Binary result(0, nullptr);
  result.data.resize(size, 0);

  // Дополняем числа нулями до одинаковой длины
  std::vector<unsigned char> a = data;
  std::vector<unsigned char> b = other.data;

  if (*this < other) {
    std::swap(a, b);
  }
  while (a.size() < size) {
    a.insert(a.begin(), 0);
  }
  while (b.size() < size) {
    b.insert(b.begin(), 0);
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

void Binary::Print() const {
  for (size_t i = 0; i < data.size(); ++i) {
    std::cout << static_cast<int>(data[i]) << " ";
  }
  std::cout << std::endl;
}

// Binary(const Binary& other) { data = other.data; }

Binary& Binary::operator=(const Binary& other) {
  if (this != &other) {
    data = other.data;
  }
  return *this;
}

bool Binary::operator==(const Binary& other) const {
  if (data.size() != other.data.size()) {
    return false;
  }

  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i] != other.data[i]) {
      return false;
    }
  }

  return true;
}

bool Binary::operator<(const Binary& other) const {
  // Дополняем числа нулями до одинаковой длины
  size_t size = std::max(data.size(), other.data.size());
  std::vector<unsigned char> a = data;
  std::vector<unsigned char> b = other.data;
  while (a.size() < size) {
    a.insert(a.begin(), 0);
  }
  while (b.size() < size) {
    b.insert(b.begin(), 0);
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

bool Binary::operator>(const Binary& other) const {
  return !(*this < other) && !(*this == other);
}
