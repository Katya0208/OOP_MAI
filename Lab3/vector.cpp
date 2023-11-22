#include "vector.hpp"

size_t Vector::Get_size() { return size; }

Figure** Vector::Get_vector() { return vector; }

void Vector::Push_back(Figure* figure) {
  if (!figure->Geom_check()) {
    return;
  }

  size_t newSize = size + 1;
  Figure** newArray = new Figure*[newSize];

  for (size_t i = 0; i < size; ++i) {
    newArray[i] = vector[i];
  }

  newArray[size] = figure;

  vector = newArray;
  size = newSize;
}

Figure* Vector::Pop(size_t idx) {
  if (idx >= size) {
    throw std::logic_error("Index is larger then the size of the array.");
    return nullptr;
  }

  Figure* removedFigure = vector[idx];

  size_t newSize = size - 1;
  Figure** newArray = new Figure*[newSize];

  for (size_t i = 0, j = 0; i < size; ++i) {
    if (i != idx) {
      newArray[j++] = vector[i];
    }
  }

  delete[] vector;
  vector = newArray;
  size = newSize;

  return removedFigure;
}

Vector::Vector() {
  size = 0;
  vector = nullptr;
}

Vector::~Vector() {
  size = 0;
  delete[] vector;
  vector = nullptr;
}