#include <gtest/gtest.h>

#include "include/figure.hpp"
#include "include/hexagon.hpp"
#include "include/pentagon.hpp"
#include "include/point.hpp"
#include "include/rhomb.hpp"

TEST(point_test, def_constructor) {
  Point<int> p;
  ASSERT_EQ(p.X, 0);
  ASSERT_EQ(p.Y, 0);
}

TEST(point_test, double_constructor) {
  Point<double> p(1.0, 3.0);
  ASSERT_EQ(p.X, 1.0);
  ASSERT_EQ(p.Y, 3.0);
}

TEST(point_test, point_constructor) {
  Point<double> p1(3.6, 3.4);
  Point<double> p(p1);
  ASSERT_EQ(p.X, p1.X);
  ASSERT_EQ(p.Y, p1.Y);
}

TEST(point_test, assignment_empty) {
  Point<double> p1;
  Point<double> p;
  p = p1;
  ASSERT_EQ(p.X, p1.X);
  ASSERT_EQ(p.Y, p1.Y);
}

TEST(point_test, assignment) {
  Point<double> p1(3.6, 3.4);
  Point<double> p;
  p = p1;
  ASSERT_EQ(p.X, p1.X);
  ASSERT_EQ(p.Y, p1.Y);
}

TEST(point_test, equalitYempty) {
  Point<double> p1;
  Point<double> p;
  ASSERT_TRUE(p == p1);
}

TEST(point_test, equality) {
  Point<double> p1(3.6, 3.4);
  Point<double> p(p1);
  ASSERT_TRUE(p == p1);
}

TEST(point_test, input) {
  std::stringstream input("1 1");
  Point<int> tr1{1, 1};
  Point<int> tr2;
  input >> tr2;
  ASSERT_TRUE(tr1 == tr2);
}

TEST(point_test, input1) {
  Point<int> tr1{1, 3};
  std::stringstream input("1 1");

  Point<int> tr2;
  input >> tr2;
  ASSERT_FALSE(tr1 == tr2);
}

TEST(point_test, output) {
  Point<int> p1(1, 3);

  std::ostringstream os;
  os << p1;
  std::string output = "(x: 1; y: 3)";
  ASSERT_EQ(os.str(), output);
}

TEST(point_test, output_empty) {
  Point<int> p1;

  std::ostringstream os;
  os << p1;
  std::string output = "(x: 0; y: 0)";
  ASSERT_EQ(os.str(), output);
}

TEST(Rhomb_test, point_constructor_excp) {
  Point<int> p1(1, 3);
  Point<int> p2(1, 3);
  Point<int> p3(3, 1);
  Point<int> p4(4, 4);

  ASSERT_THROW(Rhomb<int> p(p1, p2, p3, p4), std::logic_error);
}

TEST(Rhomb_test, area_of_empty) {
  Rhomb<double> p;
  ASSERT_EQ(p.Area(), 0.0);
}

TEST(Rhomb_test, area) {
  Point<int> p1(0, 0);
  Point<int> p2(1, 1);
  Point<int> p3(0, 2);
  Point<int> p4(-1, 1);

  Rhomb<int> p(p1, p2, p3, p4);
  ASSERT_EQ(p.Area(), 2.0);
}

TEST(Rhomb_test, center_of_empty) {
  Rhomb<int> tr1;
  Point<int> p1;
  ASSERT_EQ(tr1.GeomCenter(), p1);
}

TEST(Rhomb_test, center) {
  Point<int> p1(0, 0);
  Point<int> p2(1, 1);
  Point<int> p3(0, 2);
  Point<int> p4(-1, 1);

  Rhomb<int> tr(p1, p2, p3, p4);
  Point<int> prez{0, 1};
  std::cout << tr.GeomCenter() << std::endl;
  ASSERT_EQ(tr.GeomCenter(), prez);
}

TEST(Pentagon_test, area_of_empty) {
  Pentagon<double> p;
  ASSERT_EQ(p.Area(), 0.0);
}

TEST(Pentagon_test, center_of_empty) {
  Pentagon<int> p;
  Point<int> p1;
  ASSERT_EQ(p.GeomCenter(), p1);
}

TEST(Hexagon_test, area_of_empty) {
  Hexagon<double> p;
  ASSERT_EQ(p.Area(), 0.0);
}

TEST(Hexagon_test, center_of_empty) {
  Hexagon<int> p;
  Point<int> p1;
  ASSERT_EQ(p.GeomCenter(), p1);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}