#pragma once

#include <iostream>
#include <string>

template <class T>
class Point {
  template <class T1>
  friend std::istream& operator>>(std::istream& is, Point<T1>& p);
  template <class T1>
  friend std::ostream& operator<<(std::ostream& os, const Point<T1>& p);

 public:
  Point();
  Point(T x, T y);
  Point(const Point<T>& other);  // конструктор копирования

  Point<T>& operator=(const Point<T>& other);

  T X{};
  T Y{};
};

template <class T>
Point<T>::Point() {
  X = 0;
  Y = 0;
}

template <class T>
Point<T>::Point(T x, T y) {
  X = x;
  Y = y;
}

template <class T>
Point<T>::Point(const Point<T>& other) {
  X = other.X;
  Y = other.Y;
}

template <class T>
bool operator==(const Point<T>& left, const Point<T>& right) {
  return (left.X == right.X) && (left.Y == right.Y);
}

template <class T>
Point<T>& Point<T>::operator=(const Point<T>& right) {
  if (this != &right) {
    X = right.X;
    Y = right.Y;
  }
  return *this;
}

template <class T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
  T x, y;
  std::cout << "Введите x и y:" << std::endl;
  is >> x >> y;

  p.X = x;
  p.Y = y;
  return is;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
  os << "(x: " << p.X << "; y: " << p.Y << ")";
  return os;
}