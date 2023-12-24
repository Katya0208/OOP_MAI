#pragma once
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

template <class T, size_t Block_count>
class MyAllocator {
 public:
  template <class T1>
  struct rebind {
    using other = MyAllocator<T1, Block_count>;
  };

  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using size_type = size_t;

  MyAllocator() {
    if (Block_count == 0) {
      throw std::logic_error("Block size must be positive");
    }
    buffer = new value_type[Block_count];
    for (size_t i = 0; i < Block_count; ++i) {
      free_blocks.push_back(std::make_pair(buffer + i, false));
    }
  }

  ~MyAllocator() { delete[] buffer; }

  template <class T1>
  MyAllocator(const MyAllocator<T1, Block_count>&) noexcept {}

  pointer allocate(size_type n) {
    if (n != 1) throw std::bad_alloc();

    auto it = std::find_if(free_blocks.begin(), free_blocks.end(),
                           [](const auto& pair) { return !pair.second; });

    if (it == free_blocks.end()) {
      throw std::bad_alloc();
    }

    it->second = true;
    return it->first;
  }

  void deallocate(pointer p, size_type n) {
    if (n != 1) return;

    auto it = std::find_if(free_blocks.begin(), free_blocks.end(),
                           [p](const auto& pair) { return pair.first == p; });

    if (it == free_blocks.end()) {
      throw std::invalid_argument("Invalid pointer");
    }

    it->second = false;
  }

  template <class T1, class... Args>
  void construct(T1* p, Args&&... args) {
    new (p) T1(std::forward<Args>(args)...);
  }

  void destroy(pointer p) { p->~T(); }

 private:
  std::vector<std::pair<pointer, bool>> free_blocks;
  pointer buffer;
};
