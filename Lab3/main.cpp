#include "vector.hpp"

int main() {
  Vector *array = new Vector;
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
      std::cout << "Фигура успешно добавлена" << std::endl;

      try {
        if (fig_type == 1) {
          Rhomb *tr = new Rhomb;
          std::cin >> *tr;
          array->Push_back(tr);
        }
        if (fig_type == 2) {
          Pentagon *sq = new Pentagon;
          std::cin >> *sq;
          array->Push_back(sq);
        }
        if (fig_type == 3) {
          Hexagon *rt = new Hexagon;
          std::cin >> *rt;
          array->Push_back(rt);
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
        array->Pop(ind);
      } catch (std::exception &ex) {
        std::cerr << "Ошибка при удалении фигуры под индексом " << ind << ": "
                  << ex.what() << std::endl;
      }
    }
    if (option == 3) {
      for (size_t i = 0; i < array->Get_size(); ++i) {
        std::cout << i + 1 << ") " << array->Get_vector()[i] << std::endl;
      }
    }
    if (option == 4) {
      long double sum_area = 0;
      try {
        for (size_t i = 0; i < array->Get_size(); ++i) {
          Point pt = Point((array->Get_vector()[i])->Geom_center());
          std::cout << i + 1 << ") Геометрический центр фигуры: "
                    << "(" << pt.X << ", " << pt.Y << ')' << "; ";
          std::cout << "Площадь фигуры: " << *(array->Get_vector()[i])
                    << std::endl;
          sum_area += static_cast<double>(*(array->Get_vector()[i]));
        }
        std::cout << "Сумма площадей всех фигур: " << sum_area << std::endl;
      } catch (std::exception &ex) {
        std::cerr << "Ошибка при вычислении: " << ex.what() << std::endl;
      }
    }
    if (option == 5) {
      break;
    }
    // std::cout << "\n1) add to Array\n2) remove by "
    //"index\n3) print array\n4) print geometric center and area of all
    // figures\n5) quit\n";
  } while (option);
}