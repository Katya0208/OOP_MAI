#pragma once

#include <string.h>

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "point.hpp"

class Figure {
 public:
  virtual std::string Type() const = 0;
  operator double() const;
  Point Geom_center() const;
  bool Geom_check() const;
  friend std::istream& operator>>(std::istream& is, Figure& figure);
  friend std::ostream& operator<<(std::ostream& os, Figure* figure);

  size_t size();
  Point* Get_array();

  virtual ~Figure() = default;

 protected:
  size_t n;
  Point* array;
};