
#include <iostream>

#include "figure.hpp"
#include "point.hpp"

template <class T>
class Rhomb : public Figure<T> {
  template <class T1>
  friend std::ostream& operator<<(std::ostream& os, const Rhomb<T1>& f);

  template <class T1>
  friend std::istream& operator>>(std::istream& is, Rhomb<T1>& f);

 public:
  Rhomb();
  Rhomb(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4);
  Rhomb(const Rhomb<T>& other);

  virtual T Area() const override;
  virtual Point<T> GeomCenter() const override;

  Point<T> GetPoint(const int i) const;
  size_t Size() const;

  Rhomb<T>& operator=(const Rhomb<T>& other);  // копирование
  Rhomb<T>& operator=(Rhomb<T>&& other);       // перемещение
  bool operator==(const Rhomb<T>& other);
  virtual operator double() const override;

  ~Rhomb(){};

  Point<T> points[4];
  size_t size_;
};

template <class T>
Rhomb<T>::Rhomb() : points{Point<T>(), Point<T>(), Point<T>()}, size_{0} {}

template <class T>
Rhomb<T>::Rhomb(Point<T>& p1, Point<T>& p2, Point<T>& p3, Point<T>& p4) {
  if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
    throw std::logic_error("Ошибка: координаты не могут быть одинаковыми");
  }
  points[0] = p1;
  points[1] = p2;
  points[2] = p3;
  points[3] = p4;
  size_ = 4;
}

template <class T>
Rhomb<T>::Rhomb(const Rhomb<T>& other) {
  if (this != &other) {
    points[0] = other.points[0];
    points[1] = other.points[1];
    points[2] = other.points[2];
    points[3] = other.points[3];
    size_ = other.size_;
  }
}

template <class T>
Point<T> Rhomb<T>::GeomCenter() const {
  T Xc = (points[0].X + points[2].X) / 2.0;
  T Yc = (points[0].Y + points[2].Y) / 2.0;

  T x = (points[1].X + points[3].X) / 2.0;
  T y = (points[1].Y + points[3].Y) / 2.0;

  // Теперь, чтобы найти точку пересечения диагоналей, просто усредним их центры
  x = (x + Xc) / 2.0;
  y = (y + Yc) / 2.0;

  return Point(x, y);
}

template <class T>
T Rhomb<T>::Area() const {
  if (size_ == 0) {
    return 0.0;
  }
  T d1 = sqrt(pow(points[0].X - points[2].X, 2) +
              pow(points[0].Y - points[2].Y, 2));
  T d2 = sqrt(pow(points[1].X - points[3].X, 2) +
              pow(points[1].Y - points[3].Y, 2));

  // Площадь ромба
  T Area = (d1 * d2) / 2.0;

  return Area;
}

template <class T>
Rhomb<T>& Rhomb<T>::operator=(const Rhomb<T>& other) {
  if (this != &other) {
    points[0] = other.points[0];
    points[1] = other.points[1];
    points[2] = other.points[2];
    points[3] = other.points[3];
    size_ = other.size_;
  }
  return *this;
}

template <class T>
Rhomb<T>& Rhomb<T>::operator=(Rhomb<T>&& other) {
  if (this != &other) {
    points[0] = std::move(other.points[0]);
    points[1] = std::move(other.points[1]);
    points[2] = std::move(other.points[2]);
    points[3] = std::move(other.points[3]);
    size_ = other.size_;
  }
  return *this;
}

template <class T>
bool Rhomb<T>::operator==(const Rhomb<T>& other) {
  if (size_ != other.size_) {
    return false;
  }
  std::array<Point<T>, 4> sorted_points = {GetPoint(0), GetPoint(1),
                                           GetPoint(2), GetPoint(3)};
  std::array<Point<T>, 4> sorted_other_points = {
      other.GetPoint(0), other.GetPoint(1), other.GetPoint(2),
      other.GetPoint(3)};

  std::sort(sorted_points.begin(), sorted_points.end());
  std::sort(sorted_other_points.begin(), sorted_other_points.end());
  // for(size_t i = 0; i < 3; ++i){
  //     std::cout << "left" << sorted_points[i] << std::endl;
  //     std::cout << "other" << sorted_other_points[i] << std::endl;
  // }

  return sorted_points == sorted_other_points;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Rhomb<T>& f) {
  for (size_t i = 0; i < 4; ++i) {
    os << f.points[i] << std::endl;
  }
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Rhomb<T>& f) {
  for (size_t i = 0; i < 4; ++i) {
    is >> f.points[i];
    if (is.fail()) {
      throw std::invalid_argument("Ввод должен быть числом");
    }
  }

  // Проверка на совпадение координат для различных углов
  if (f.points[0] == f.points[1] || f.points[0] == f.points[2] ||
      f.points[1] == f.points[2]) {
    throw std::logic_error("Same coordinates for different points");
  }

  // Проверка на параллельность противоположных сторон
  if ((f.points[0].Y - f.points[2].Y) * (f.points[1].X - f.points[3].X) ==
      (f.points[1].Y - f.points[3].Y) * (f.points[0].X - f.points[2].X)) {
    throw std::logic_error("Opposite sides are parallel");
  }

  f.size_ = 4;
  return is;
}

template <class T>
Rhomb<T>::operator double() const {
  return Area();
}

template <class T>
size_t Rhomb<T>::Size() const {
  return size_;
}

template <class T>
Point<T> Rhomb<T>::GetPoint(const int i) const {
  if (i < 0 || i > 3) {
    throw std::invalid_argument("Out of index range");
  }
  return points[i];
}