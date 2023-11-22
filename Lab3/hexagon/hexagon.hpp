#pragma once

#include "../figure.hpp"

class Hexagon : public Figure {
 public:
  Hexagon();
  Hexagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5, Point& p6);
  std::string Type() const override { return "Hexagon"; }
  void operator=(const Hexagon& figure);
  void operator=(Hexagon&& figure);
  bool operator==(const Hexagon& figure) const;
  ~Hexagon();
};