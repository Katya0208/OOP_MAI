#pragma once

#include <stdio.h>

#include <cmath>

class Point {
 public:
  Point() = default;
  Point(int x, int y) : X(x), Y(y){};
  ~Point() = default;

  int distance(Point& other);
  void operator=(Point& other);
  bool operator==(Point& other);
  int X;
  int Y;
};