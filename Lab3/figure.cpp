#include "figure.hpp"

bool Figure::Geom_check() const {
  bool flag = true;
  for (int i = 0; i < n; ++i) {
    if (std::round(array[i].distance(array[(i + 1) % n])) !=
        round(array[(i + 2) % n].distance(array[(i + 3) % n]))) {
      throw std::logic_error("That's not a correct figure");
      flag = false;
    }
  }

  return flag;
}

Point Figure::Geom_center() const {
  if (!this->Geom_check()) {
    return Point(1e8, 1e8);
  }

  Point res(0, 0);
  for (size_t i = 0; i < n; ++i) {
    res.X += array[i].X;
    res.Y += array[i].Y;
  }
  res.X /= n;
  res.Y /= n;
  return res;
}

Figure::operator double() const {
  return (n * array[1].distance(array[0]) * array[2].distance(array[1]) / 4) *
         (1 / std::tan(M_PI / n));
}

std::istream& operator>>(std::istream& is, Figure& figure) {
  std::cout << "Please enter coordinates of points in " << figure.Type()
            << " (Example: <X> <Y>)\n";
  for (int i = 0; i < figure.n; i++) {
    std::cout << "Point " << i + 1 << ": ";
    is >> figure.array[i].X >> figure.array[i].Y;
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, Figure* figure) {
  os << "Coordinates of " << figure->Type() << ":\n";
  for (int i = 0; i < figure->size(); i++) {
    os << "Point " << i + 1 << ": " << '(' << figure->Get_array()[i].X << ", "
       << figure->Get_array()[i].Y << ')' << '\n';
  }
  return os;
}

size_t Figure::size() { return n; }

Point* Figure::Get_array() { return array; }