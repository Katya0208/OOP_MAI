#pragma once

#include "../figure.hpp"

class Pentagon : public Figure {
 public:
  Pentagon();
  Pentagon(Point& p1, Point& p2, Point& p3, Point& p4, Point& p5);
  std::string Type() const override { return "Pentagon"; }
  void operator=(const Pentagon& figure);
  void operator=(Pentagon&& figure);
  bool operator==(const Pentagon& figure) const;
  ~Pentagon();
};