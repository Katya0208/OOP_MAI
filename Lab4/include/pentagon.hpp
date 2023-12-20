#pragma once

#include <iostream>

#include "figure.hpp"
#include "point.hpp"

template <class T>
class Pentagon : public Figure<T> {
  template <class T1>
  friend std::ostream& operator<<(std::ostream& os, const Pentagon<T1>& f);

  template <class T1>
  friend std::istream& operator>>(std::istream& is, Pentagon<T1>& f);

 public:
  Pentagon();
  Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4,
           Point<T>& p5);
  Pentagon(const Pentagon<T>& other);

  virtual T Area() const override;
  virtual Point<T> GeomCenter() const override;

  Point<T> get_point(const int i) const;
  size_t size() const;

  Pentagon<T>& operator=(const Pentagon<T>& other);
  Pentagon<T>& operator=(Pentagon<T>&& other);
  bool operator==(const Pentagon<T>& other);
  virtual operator double() const override;

  ~Pentagon(){};

  Point<T> points[5];
  size_t size_;
};

template <class T>
Pentagon<T>::Pentagon()
    : points{Point<T>(), Point<T>(), Point<T>(), Point<T>(), Point<T>()},
      size_{0} {}

template <class T>
Pentagon<T>::Pentagon(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4,
                      Point<T>& p5) {
  std::array<Point<T>, 5> points = {p1, p2, p3, p4, p5};
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (points[i] == points[j]) {
        throw std::logic_error("Same coordinates for different points");
      }
    }
    points[i] = points[i];
  }
  size_ = 5;
}

template <class T>
Pentagon<T>::Pentagon(const Pentagon<T>& other) {
  if (this != &other) {
    for (size_t i = 0; i < 5; ++i) {
      points[i] = other.points[i];
    }
    size_ = other.size_;
  }
}

template <class T>
Point<T> Pentagon<T>::GeomCenter() const {
  T Xc = 0, Yc = 0;
  for (size_t i = 0; i < size_; ++i) {
    Xc += points[i].X;
    Yc += points[i].Y;
  }
  T x = Xc / 5.0, y = Yc / 5.0;
  return Point(x, y);
}

template <class T>
T Pentagon<T>::Area() const {
  if (size_ == 0) {
    return 0.0;
  }
  T x1 = points[0].X;
  T y1 = points[0].Y;
  Point<T> center = this->GeomCenter();
  T R = sqrt(pow((x1 - center.X), 2) + pow((y1 - center.Y), 2));
  T r = R * cos(M_PI / 5);
  T area = 0.5 * 5 * R * r;
  return area;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator=(const Pentagon<T>& other) {
  if (this != &other) {
    for (size_t i = 0; i < 5; ++i) {
      points[i] = other.points[i];
    }
    size_ = other.size_;
  }
  return *this;
}

template <class T>
Pentagon<T>& Pentagon<T>::operator=(Pentagon<T>&& other) {
  if (this != &other) {
    for (size_t i = 0; i < 5; ++i) {
      points[i] = std::move(other.points[i]);
    }
    size_ = other.size_;
  }
  return *this;
}

template <class T>
bool Pentagon<T>::operator==(const Pentagon<T>& other) {
  if (size_ != other.size_) {
    return false;
  }
  std::array<Point<T>, 5> sorted_points;
  std::array<Point<T>, 5> sorted_other_points;

  for (int i = 0; i < 5; i++) {
    sorted_points[i] = get_point(i);
    sorted_other_points[i] = other.get_point(i);
  }

  std::sort(sorted_points.begin(), sorted_points.end());
  std::sort(sorted_other_points.begin(), sorted_other_points.end());

  // for (int i = 0; i < 8; i++) {
  //     std::cout << "left" << sorted_points[i] << std::endl;
  //     std::cout << "other" << sorted_other_points[i] << std::endl;
  // }

  return sorted_points == sorted_other_points;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Pentagon<T>& f) {
  for (size_t i = 0; i < 5; ++i) {
    os << f.points[i] << std::endl;
  }
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Pentagon<T>& f) {
  for (size_t i = 0; i < 5; ++i) {
    is >> f.points[i];
    if (is.fail()) {
      throw std::invalid_argument("Input must be a number");
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (f.points[i] == f.points[j]) {
        throw std::logic_error("Same coordinates for different points");
      }
    }
  }
  f.size_ = 5;
  return is;
}

template <class T>
Pentagon<T>::operator double() const {
  return Area();
}

template <class T>
size_t Pentagon<T>::size() const {
  return size_;
}

template <class T>
Point<T> Pentagon<T>::get_point(const int i) const {
  if (i < 0 || i > 7) {
    throw std::invalid_argument("Out of index range");
  }
  return points[i];
}