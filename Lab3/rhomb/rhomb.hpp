#pragma once

#include "../figure.hpp"

class Rhomb : public Figure {
 public:
  Rhomb();
  Rhomb(Point& p1, Point& p2, Point& p3, Point& p4);
  std::string Type() const override { return "Rhomb"; }
  void operator=(const Rhomb& figure);
  void operator=(Rhomb&& figure);
  bool operator==(const Rhomb& figure) const;

  ~Rhomb();
};