#pragma once

#include <stdio.h>

#include <stdexcept>

#include "hexagon/hexagon.hpp"
#include "pentagon/pentagon.hpp"
#include "rhomb/rhomb.hpp"

class Vector {
 private:
  size_t size;
  Figure** vector;

 public:
  Vector();

  ~Vector();
  void Push_back(Figure* figure);
  Figure* Pop(size_t index);

  size_t Get_size();
  Figure** Get_vector();
};