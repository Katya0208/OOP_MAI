#include "pentagon.hpp"

#define N_POINTS_PENTAGON 5

Pentagon::Pentagon() {
  n = N_POINTS_PENTAGON;
  array = new Point[n];
}

Pentagon::Pentagon(Point& point1, Point& point2, Point& point3, Point& point4,
                   Point& point5) {
  n = N_POINTS_PENTAGON;
  array = new Point[n];
  array[0] = point1, array[1] = point2, array[2] = point3, array[3] = point4,
  array[4] = point5;
  if (!this->Geom_check()) {
    throw std::logic_error("This pentagon is wrong");
  }
}

void Pentagon::operator=(const Pentagon& figure) {
  n = figure.n;
  array = new Point[n];
  for (size_t i = 0; i < n; i++) {
    array[i] = figure.array[i];
  }
}

void Pentagon::operator=(Pentagon&& figure) {
  n = figure.n;
  array = figure.array;
  figure.n = 0;
  figure.array = nullptr;
}

bool Pentagon::operator==(const Pentagon& figure) const {
  return static_cast<double>(*this) == static_cast<double>(figure);
}

Pentagon::~Pentagon() {
  n = 0;
  delete[] array;
  array = nullptr;
}