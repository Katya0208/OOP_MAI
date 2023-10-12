#pragma once
#include <iostream>
using namespace std;

#define GREEN_COLOR "\x1b[32m"

void resizeArray(int *&data, int oldSize, int newSize, int value);

class Binary {
 private:
  int Size;

 public:
  int *data;
  Binary(int size, int *values);
  Binary(const Binary &other);
  Binary &operator=(const Binary &other);
  bool operator==(const Binary &other) const;
  Binary operator+(const Binary &other) const;
  Binary operator-(const Binary &other) const;
  bool operator<(const Binary &other) const;
  bool operator>(const Binary &other) const;
  bool operator>=(const Binary &other) const;
  bool operator<=(const Binary &other) const;
  void Print();
  ~Binary();
};
Binary InputBinaryNumber();