#include "rhomb.hpp"

#define N_POINTS_RHOMB 4

Rhomb::Rhomb() {
  n = N_POINTS_RHOMB;
  array = new Point[n];
}

Rhomb::Rhomb(Point& point1, Point& point2, Point& point3, Point& point4) {
  n = N_POINTS_RHOMB;
  array = new Point[n];
  array[0] = point1, array[1] = point2, array[2] = point3, array[3] = point4;
  if (!this->Geom_check()) {
    throw std::logic_error("This rhomb is wrong");
  }
}

void Rhomb::operator=(const Rhomb& figure) {
  n = figure.n;
  array = new Point[n];
  for (size_t i = 0; i < n; i++) {
    array[i] = figure.array[i];
  }
}

void Rhomb::operator=(Rhomb&& figure) {
  n = figure.n;
  array = figure.array;
  figure.n = 0;
  figure.array = nullptr;
}

bool Rhomb::operator==(const Rhomb& figure) const {
  return static_cast<double>(*this) == static_cast<double>(figure);
}

Rhomb::~Rhomb() {
  n = 0;
  delete[] array;
  array = nullptr;
}