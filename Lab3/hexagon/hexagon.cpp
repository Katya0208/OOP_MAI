#include "hexagon.hpp"

#define N_POINTS_HEXAGON 6

Hexagon::Hexagon() {
  n = N_POINTS_HEXAGON;
  array = new Point[n];
}

Hexagon::Hexagon(Point& point1, Point& point2, Point& point3, Point& point4,
                 Point& point5, Point& point6) {
  n = N_POINTS_HEXAGON;
  array = new Point[n];
  array[0] = point1, array[1] = point2, array[2] = point3, array[3] = point4,
  array[4] = point5, array[5] = point6;
  if (!this->Geom_check()) {
    throw std::logic_error("This hexagon is wrong");
  }
}

void Hexagon::operator=(const Hexagon& figure) {
  n = figure.n;
  array = new Point[n];
  for (size_t i = 0; i < n; i++) {
    array[i] = figure.array[i];
  }
}

void Hexagon::operator=(Hexagon&& figure) {
  n = figure.n;
  array = figure.array;
  figure.n = 0;
  figure.array = nullptr;
}

bool Hexagon::operator==(const Hexagon& figure) const {
  return static_cast<double>(*this) == static_cast<double>(figure);
}

Hexagon::~Hexagon() {
  n = 0;
  delete[] array;
  array = nullptr;
}