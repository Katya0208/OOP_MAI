#include <iostream>
#include <map>

#include "include/allocator.hpp"
#include "include/list.hpp"

int factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  std::cout << "Демонстрация собственного аллокатора в std::map:\n";
  std::map<int, int, std::less<>, MyAllocator<std::pair<const int, int>, 10>>
      map_;

  std::cout << "Заполнение...\n";
  for (int i = 0; i < 10; i++) {
    map_[i] = factorial(i);
    if (i == 6) {
      map_.erase(2);
      std::cout << "Удален ключ 2\n";
    }
  }

  std::cout << "Итоговое содержимое:\n";
  for (const auto& pair : map_) {
    std::cout << pair.first << " " << pair.second << std::endl;
  }

  std::cout << "\nДемонстрация собственного аллокатора в списке:\n";
  List<int, 100, MyAllocator<int, 100>> list;

  std::cout << "Заполнение списка...\n";
  for (int i = 0; i < 10; i++) {
    list.Push(i);
  }

  std::cout << "Содержимое списка:\n";
  for (const auto& value : list) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;
}
