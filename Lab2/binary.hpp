#pragma once
#include <stdexcept>
#include <vector>

class Binary {
 private:
  std::vector<unsigned char> data;

 public:
  Binary(int size, const unsigned char* values);

  Binary operator+(const Binary& other) const;
  Binary operator-(const Binary& other) const;

  void Print() const;

  Binary& operator=(const Binary& other);
  bool operator==(const Binary& other) const;
  bool operator<(const Binary& other) const;
  bool operator>(const Binary& other) const;
};
