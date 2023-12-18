#include <gtest/gtest.h>

#include "hexagon/hexagon.hpp"
#include "pentagon/pentagon.hpp"
#include "rhomb/rhomb.hpp"
#include "vector.hpp"

TEST(PointTest, Distance) {
  Point p1(0, 0);
  Point p2(3, 4);

  EXPECT_EQ(p1.distance(p2), 5);
}

TEST(PointTest, Equality) {
  Point p1(1, 2);
  Point p2(1, 2);

  EXPECT_TRUE(p1 == p2);
}

TEST(HexagonTest, ParameterizedConstructor) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Hexagon hexagon(p1, p2, p3, p4, p5, p6);
  EXPECT_EQ(hexagon.Type(), "Hexagon");
}

TEST(HexagonTest, AssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Hexagon hexagon1(p1, p2, p3, p4, p5, p6);
  Hexagon hexagon2;

  hexagon2 = hexagon1;

  EXPECT_TRUE(hexagon1 == hexagon2);
}

TEST(HexagonTest, MoveAssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Hexagon hexagon1(p1, p2, p3, p4, p5, p6);
  Hexagon hexagon2;

  hexagon2 = std::move(hexagon1);

  EXPECT_EQ(hexagon1.size(), 0);
  EXPECT_TRUE(hexagon2.Geom_check());
}

TEST(HexagonTest, EqualityOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Hexagon hexagon1(p1, p2, p3, p4, p5, p6);
  Hexagon hexagon2(p1, p2, p3, p4, p5, p6);

  EXPECT_TRUE(hexagon1 == hexagon2);
}

TEST(HexagonTest, InequalityOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Hexagon hexagon1(p1, p2, p3, p4, p5, p6);
  Hexagon hexagon2(p1, p2, p3, p4, p5, p6);

  EXPECT_FALSE(hexagon1 != hexagon2);
}

TEST(HexagonTest, GeomCenter) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 1), p5(-1, 1), p6(-1, 0);
  Point p11(-1, 0), p22(-1, 1), p33(0, 1), p44(1, 1), p55(1, 0), p66(0, 0);
  Hexagon hexagon1(p1, p2, p3, p4, p5, p6);
  Hexagon hexagon2(p11, p22, p33, p44, p55, p66);
  Point gc1 = hexagon1.Geom_center();
  Point gc2 = hexagon2.Geom_center();
  double area1 = hexagon1;
  double area2 = hexagon2;
  ASSERT_TRUE(gc1 == gc2 && area1 == area2);
}

TEST(HexagonTest, ErrorConstructing) {
  Point pt1(0, 0);
  Point pt2(4, 0);
  Point pt3(3, 2);
  Point pt4(5, 3);
  Point pt5(8, 0);
  Point pt6(-1, 0);

  ASSERT_THROW(Hexagon hexagon(pt1, pt2, pt3, pt4, pt5, pt6), std::logic_error);
}

TEST(HexagonTest, Destructor) {
  Hexagon* hexagon = new Hexagon();
  delete hexagon;

  EXPECT_TRUE(true);
}

TEST(RhombTest, ParameterizedConstructor) {
  Point p1(0, 0), p2(1, 0), p3(0, 1), p4(-1, 0);
  Rhomb rhomb(p1, p2, p3, p4);

  EXPECT_EQ(rhomb.Type(), "Rhomb");
}

TEST(RhombTest, AssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(0, 1), p4(-1, 0);
  Rhomb rhomb1(p1, p2, p3, p4);
  Rhomb rhomb2;

  rhomb2 = rhomb1;

  EXPECT_TRUE(rhomb1 == rhomb2);
}

TEST(PhombTest, ErrorConstructing) {
  Point pt1(0, 0);
  Point pt2(4, 0);
  Point pt3(3, 2);
  Point pt4(5, 3);

  ASSERT_THROW(Rhomb rhomb(pt1, pt2, pt3, pt4), std::logic_error);
}
TEST(RhombTest, MoveAssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(0, 1), p4(-1, 0);
  Rhomb rhomb1(p1, p2, p3, p4);
  Rhomb rhomb2;

  rhomb2 = std::move(rhomb1);

  EXPECT_EQ(rhomb1.size(), 0);
  EXPECT_TRUE(rhomb2.Geom_check());
}

TEST(RhombTest, EqualityOperator) {
  Point p1(0, 0), p2(1, 0), p3(0, 1), p4(-1, 0);
  Rhomb rhomb1(p1, p2, p3, p4);
  Rhomb rhomb2(p1, p2, p3, p4);

  EXPECT_TRUE(rhomb1 == rhomb2);
}

TEST(RhombTest, GeomCenter) {
  Point p1(0, 0), p2(1, 0), p3(0, 1), p4(-1, 0);
  Point p11(-1, 0), p22(0, 1), p33(1, 0), p44(0, 0);
  Rhomb rhomb1(p1, p2, p3, p4);
  Rhomb rhomb2(p11, p22, p33, p44);
  Point gc1 = rhomb1.Geom_center();
  Point gc2 = rhomb2.Geom_center();
  double area1 = rhomb1;
  double area2 = rhomb2;
  ASSERT_TRUE(gc1 == gc2 && area1 == area2);
}

TEST(RhombTest, Destructor) {
  Rhomb* rhomb = new Rhomb();
  delete rhomb;

  EXPECT_TRUE(true);
}

TEST(PentagonTest, ParameterizedConstructor) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(-1, 1);
  Pentagon pentagon(p1, p2, p3, p4, p5);

  EXPECT_EQ(pentagon.Type(), "Pentagon");
}

TEST(PentagonTest, AssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(-1, 1);
  Pentagon pentagon1(p1, p2, p3, p4, p5);
  Pentagon pentagon2;

  pentagon2 = pentagon1;

  EXPECT_TRUE(pentagon1 == pentagon2);
}

TEST(PentagonTest, MoveAssignmentOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(-1, 1);
  Pentagon pentagon1(p1, p2, p3, p4, p5);
  Pentagon pentagon2;

  pentagon2 = std::move(pentagon1);

  EXPECT_EQ(pentagon1.size(), 0);
  EXPECT_TRUE(pentagon2.Geom_check());
}

TEST(PentagonTest, EqualityOperator) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(-1, 1);
  Pentagon pentagon1(p1, p2, p3, p4, p5);
  Pentagon pentagon2(p1, p2, p3, p4, p5);

  EXPECT_TRUE(pentagon1 == pentagon2);
}

TEST(PentagonTest, ErrorConstructing) {
  Point pt1(0, 0);
  Point pt2(4, 0);
  Point pt3(3, 2);
  Point pt4(5, 3);
  Point pt5(8, 0);

  ASSERT_THROW(Pentagon pentagon(pt1, pt2, pt3, pt4, pt5), std::logic_error);
}

TEST(PentagonTest, GeomCenter) {
  Point p1(0, 0), p2(1, 0), p3(1, 1), p4(0, 2), p5(-1, 1);
  Point p11(-1, 1), p22(0, 2), p33(1, 1), p44(1, 0), p55(0, 0);
  Pentagon pentagon1(p1, p2, p3, p4, p5);
  Pentagon pentagon2(p11, p22, p33, p44, p55);

  Point gc1 = pentagon1.Geom_center();
  Point gc2 = pentagon2.Geom_center();
  double area1 = pentagon1;
  double area2 = pentagon2;
  ASSERT_TRUE(gc1 == gc2 && area1 == area2);
}
TEST(PentagonTest, Destructor) {
  Pentagon* pentagon = new Pentagon();
  delete pentagon;

  EXPECT_TRUE(true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
