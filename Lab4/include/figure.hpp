#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>

#include "point.hpp"

template <class T>
class Figure {
 public:
  Figure() = default;

  virtual T Area() const = 0;
  virtual Point<T> GeomCenter() const = 0;
  virtual operator double() const = 0;

  virtual ~Figure() = default;
};