#include <gtest/gtest.h>

#include <memory>

#include "input/dragon.hpp"
#include "input/knight.hpp"
#include "input/npc.hpp"
#include "input/princess.hpp"

TEST(test_01, princess_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x, y);

  EXPECT_EQ((a->position()).first, 100);
}

TEST(test_02, princess_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x, y);

  EXPECT_EQ((a->position()).second, 100);
}

TEST(test_03, princess_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x, y);
  EXPECT_EQ(PrincessType, a->get_type());
}

TEST(test_04, princess_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(test_05, princess_constructor) {
  int x1{100};
  int y1{100};

  int x2{90};
  int y2{90};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x1, y1);

  std::shared_ptr<NPC> b;
  b = std::make_shared<Princess>(x2, y2);
  EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_06, princess_constructor) {
  int x{10};
  int y{10};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Princess>(x, y);

  a->move(50, 50, 100, 100);
  EXPECT_EQ((a->position()).first, 60);
}

TEST(test_07, dragon_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x, y);

  EXPECT_EQ((a->position()).first, 100);
}

TEST(test_08, dragon_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x, y);

  EXPECT_EQ((a->position()).second, 100);
}

TEST(test_09, dragon_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x, y);
  EXPECT_EQ(DragonType, a->get_type());
}

TEST(test_10, dragon_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(test_11, dragon_constructor) {
  int x1{100};
  int y1{100};

  int x2{90};
  int y2{90};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x1, y1);

  std::shared_ptr<NPC> b;
  b = std::make_shared<Princess>(x2, y2);
  EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_12, dragon_constructor) {
  int x{10};
  int y{10};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Dragon>(x, y);

  a->move(50, 50, 100, 100);
  EXPECT_EQ((a->position()).first, 60);
}

TEST(test_13, knight_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x, y);

  EXPECT_EQ((a->position()).first, 100);
}

TEST(test_14, knight_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x, y);

  EXPECT_EQ((a->position()).second, 100);
}

TEST(test_15, knight_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x, y);
  EXPECT_EQ(KnightType, a->get_type());
}

TEST(test_16, knight_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(test_17, knight_constructor) {
  int x1{100};
  int y1{100};

  int x2{90};
  int y2{90};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x1, y1);

  std::shared_ptr<NPC> b;
  b = std::make_shared<Princess>(x2, y2);
  EXPECT_TRUE(a->is_close(b, 100));
}

TEST(test_18, knight_constructor) {
  int x{10};
  int y{10};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Knight>(x, y);

  a->move(50, 50, 100, 100);
  EXPECT_EQ((a->position()).first, 60);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}