#include <iostream>
#include <string>

#include "include/figure.hpp"
#include "include/hexagon.hpp"
#include "include/pentagon.hpp"
#include "include/point.hpp"
#include "include/rhomb.hpp"
#include "include/vector.hpp"
int main() {
  Vector<std::shared_ptr<Figure<double>>> arr;

  std::cout
      << "Введите что вы хотите сделать:\n1) добавить фигуру в массив\n2) "
         "удалить фигуру по индексу\n3) вывести массив с фигурами\n4) вывод "
         "геометрического центра и площади фигур из массива\n5) выход\n";
  size_t option = 0;
  do {
    option = 0;

    std::cin >> option;
    if (option == 1) {
      size_t fig_type = 0;
      std::cout
          << "Выберите фигуру:\n1) Ромб\n2) 5-тиугольник\n3) 6-тиугольник\n";
      std::cin >> fig_type;

      try {
        if (fig_type == 1) {
          auto r = std::make_shared<Rhomb<double>>();
          std::cin >> *r;
          arr.push_back(r);
        }
        if (fig_type == 2) {
          auto p = std::make_shared<Pentagon<double>>();
          std::cin >> *p;
          arr.push_back(p);
        }
        if (fig_type == 3) {
          auto h = std::make_shared<Hexagon<double>>();
          std::cin >> *h;
          arr.push_back(h);
        }
      } catch (std::exception &ex) {
        std::cerr << "Ошибка при добавлении фигуры: " << ex.what() << std::endl;
      }
    }
    if (option == 2) {
      size_t ind = 0;
      std::cout << "Введите индекс(нумеруется с 0): ";
      std::cin >> ind;
      try {
        arr.remove(ind);
      } catch (std::exception &ex) {
        std::cerr << "Ошибка при удалении фигуры под индексом " << ind << ": "
                  << ex.what() << std::endl;
      }
    }
    if (option == 3) {
      for (int i = 0; i < arr.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ": " << *arr.get(i) << std::endl;
      }
    }

    if (option == 4) {
      try {
        for (int i = 0; i < arr.size(); ++i) {
          std::cout << "Геометрический центр фигуры " << i + 1 << ": "
                    << arr.get(i)->GeomCenter() << std::endl;
          std::cout << "Площадь фигуры " << i + 1 << ": " << arr.get(i)->Area()
                    << std::endl;
        }
        std::cout << "Сумма площадей всех фигур: " << SumArea(arr) << std::endl;
      } catch (std::exception &ex) {
        std::cerr << "Ошибка при вычислении: " << ex.what() << std::endl;
      }
    }
    if (option == 5) {
      break;
    }
  } while (option);
}