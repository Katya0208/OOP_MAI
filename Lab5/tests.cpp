#include <gtest/gtest.h>

#include "include/allocator.hpp"
#include "include/list.hpp"

TEST(forward_list, constructor) {
  List<int, 10, MyAllocator<int, 10>> list;
  ASSERT_TRUE(list.Empty());
}

TEST(forward_list, Push) {
  List<int, 100, MyAllocator<int, 100>> list;
  for (auto i = 0; i < 19; ++i) {
    list.Push(i);
  }
  ASSERT_EQ(list.front(), 18);
}

TEST(forward_list, Pop) {
  List<int, 100, MyAllocator<int, 100>> list;
  for (auto i = 0; i < 19; ++i) {
    list.Push(i);
  }
  for (auto i = 1; i < 19; ++i) {
    list.Pop();
    ASSERT_EQ(list.front(), 19 - i - 1);
  }
  list.Pop();
  ASSERT_TRUE(list.Empty());
}

TEST(forward_list, Empty) {
  List<int, 100, MyAllocator<int, 100>> list;
  for (auto i = 0; i < 1; ++i) {
    list.Push(i);
  }
  ASSERT_FALSE(list.Empty());
  list.Pop();
  ASSERT_TRUE(list.Empty());
}

TEST(forward_list, front) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 0; i < 1; ++i) {
    list.Push(i);
  }
  ASSERT_EQ(list.front(), 0);
  list.Pop();
  ASSERT_THROW(list.front(), std::out_of_range);
}

TEST(forward_list, Clean) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 1; i < 4; ++i) {
    list.Push(i);
  }

  list.Clean();
  ASSERT_TRUE(list.Empty());
}

TEST(forward_list, exp_front) {
  List<int, 10, MyAllocator<int, 10>> list;
  ASSERT_THROW(list.front(), std::out_of_range);
}

TEST(forward_list_iterator, begin_n_end) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 1; i < 4; ++i) {
    list.Push(i);
  }

  auto it = list.begin();
  ASSERT_EQ(*it, 3);
  List<int, 10, MyAllocator<int, 10>>::MyIterator it1(nullptr);
  ASSERT_EQ(list.end(), it1);
}

TEST(forward_list_iterator, pre_increment) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 1; i < 4; ++i) {
    list.Push(i);
  }

  auto it = list.begin();
  ++it;
  ASSERT_EQ(*it, 2);
  ++it;
  ASSERT_EQ(*it, 1);
  ++it;
  ASSERT_EQ(it, list.end());
}

TEST(forward_list_iterator, post_increment) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 1; i < 4; ++i) {
    list.Push(i);
  }

  auto it = list.begin();
  auto it2 = it++;
  ASSERT_EQ(*it, 2);
  ASSERT_EQ(*it2, 3);
  auto it3 = it++;
  ASSERT_EQ(*it, 1);
  ASSERT_EQ(*it3, 2);
  auto it4 = it++;
  ASSERT_EQ(it, list.end());
  ASSERT_EQ(*it3, 2);
  ASSERT_EQ(*it4, 1);
}

TEST(forward_list_iterator, before_begin) {
  List<int, 10, MyAllocator<int, 10>> list;
  for (auto i = 1; i < 4; ++i) {
    list.Push(i);
  }

  auto it = list.before_begin();
  ASSERT_EQ(*(++it), list.front());
}

TEST(forward_list_iterator, InsertAfter) {
  List<int, 10, MyAllocator<int, 10>> list;
  list.Push(1);
  list.Push(2);
  list.Push(3);

  list.InsertAfter(list.before_begin(), 1000);
  ASSERT_EQ(*(list.begin()), list.front());

  list.InsertAfter(list.begin(), 777);
  ASSERT_EQ(777, *(++list.begin()));
}

TEST(forward_list_iterator, loop_w_iterator) {
  List<int, 100, MyAllocator<int, 100>> list;

  std::ostringstream os;
  std::string output = "8 7 6 5 4 3 2 1 ";

  for (auto i = 1; i < 9; ++i) {
    list.Push(i);
  }
  for (auto it = list.begin(); it != list.end(); ++it) {
    os << *(it) << " ";
  }

  ASSERT_EQ(os.str(), output);
}

TEST(allocator_test, exp_allocate1) {
  MyAllocator<int, 4> allocator;
  ASSERT_THROW(allocator.allocate(2), std::bad_alloc);
}
TEST(allocator_test, exp_allocate2) {
  MyAllocator<int, 1> allocator;
  allocator.allocate(1);
  ASSERT_THROW(allocator.allocate(1), std::bad_alloc);
}
TEST(allocator_test, exp_deallocate) {
  MyAllocator<int, 1> allocator;
  allocator.allocate(1);
  ASSERT_THROW(allocator.deallocate(nullptr, 1), std::invalid_argument);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
