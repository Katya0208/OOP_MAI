#include "point.hpp"

int Point::distance(Point &other) {
  return std::round(
      std::sqrt(std::pow(X - other.X, 2) + std::pow(Y - other.Y, 2)));
}

void Point::operator=(Point &other) {
  X = other.X;
  Y = other.Y;
}

bool Point::operator==(Point &other) {
  return ((X == other.X) && (Y == other.Y));
}