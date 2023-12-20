#pragma once

#include <iostream>

#include "figure.hpp"
#include "point.hpp"

template <class T>
class Hexagon : public Figure<T> {
  template <class T1>
  friend std::ostream& operator<<(std::ostream& os, const Hexagon<T1>& f);

  template <class T1>
  friend std::istream& operator>>(std::istream& is, Hexagon<T1>& f);

 public:
  Hexagon();
  Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4, Point<T>& p5,
          Point<T>& p6);
  Hexagon(const Hexagon<T>& other);

  virtual T Area() const override;
  virtual Point<T> GeomCenter() const override;

  Point<T> get_point(const int i) const;
  size_t size() const;

  Hexagon<T>& operator=(const Hexagon<T>& other);
  Hexagon<T>& operator=(Hexagon<T>&& other);
  bool operator==(const Hexagon<T>& other);
  virtual operator double() const override;

  ~Hexagon(){};

  Point<T> points[6];
  size_t size_;
};

template <class T>
Hexagon<T>::Hexagon()
    : points{Point<T>(), Point<T>(), Point<T>(),
             Point<T>(), Point<T>(), Point<T>()},
      size_{0} {}

template <class T>
Hexagon<T>::Hexagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4,
                    Point<T>& p5, Point<T>& p6) {
  std::array<Point<T>, 6> points = {p1, p2, p3, p4, p5, p6};
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (points[i] == points[j]) {
        throw std::logic_error("Same coordinates for different points");
      }
    }
    points[i] = points[i];
  }
  size_ = 6;
}

template <class T>
Hexagon<T>::Hexagon(const Hexagon<T>& other) {
  if (this != &other) {
    for (size_t i = 0; i < 8; ++i) {
      points[i] = other.points[i];
    }
    size_ = other.size_;
  }
}

template <class T>
Point<T> Hexagon<T>::GeomCenter() const {
  T Xc = 0, Yc = 0;
  for (size_t i = 0; i < size_; ++i) {
    Xc += points[i].X;
    Yc += points[i].Y;
  }
  T x = Xc / 6.0, y = Yc / 6.0;
  return Point(x, y);
}

template <class T>
T Hexagon<T>::Area() const {
  if (size_ == 0) {
    return 0.0;
  }
  T x1 = points[0].X;
  T y1 = points[0].Y;
  Point<T> center = this->GeomCenter();
  double R = sqrt(pow((x1 - center.X), 2) + pow((y1 - center.Y), 2));
  double r = R * cos(M_PI / 6);
  double area = 0.5 * 6 * R * r;
  return area;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T>& other) {
  if (this != &other) {
    for (size_t i = 0; i < 6; ++i) {
      points[i] = other.points[i];
    }
    size_ = other.size_;
  }
  return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& other) {
  if (this != &other) {
    for (size_t i = 0; i < 6; ++i) {
      points[i] = std::move(other.points[i]);
    }
    size_ = other.size_;
  }
  return *this;
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T>& other) {
  if (size_ != other.size_) {
    return false;
  }
  std::array<Point<T>, 6> sorted_points;
  std::array<Point<T>, 6> sorted_other_points;

  for (int i = 0; i < 6; i++) {
    sorted_points[i] = get_point(i);
    sorted_other_points[i] = other.get_point(i);
  }

  std::sort(sorted_points.begin(), sorted_points.end());
  std::sort(sorted_other_points.begin(), sorted_other_points.end());

  return sorted_points == sorted_other_points;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T>& f) {
  for (size_t i = 0; i < 6; ++i) {
    os << f.points[i] << std::endl;
  }
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T>& f) {
  for (size_t i = 0; i < 6; ++i) {
    is >> f.points[i];
    if (is.fail()) {
      throw std::invalid_argument("Input must be a number");
    }
  }
  for (int i = 0; i < 6; i++) {
    for (int j = i + 1; j < 6; j++) {
      if (f.points[i] == f.points[j]) {
        throw std::logic_error("Same coordinates for different points");
      }
    }
  }
  f.size_ = 6;
  return is;
}

template <class T>
Hexagon<T>::operator double() const {
  return Area();
}

template <class T>
size_t Hexagon<T>::size() const {
  return size_;
}

template <class T>
Point<T> Hexagon<T>::get_point(const int i) const {
  if (i < 0 || i > 5) {
    throw std::invalid_argument("Out of index range");
  }
  return points[i];
}