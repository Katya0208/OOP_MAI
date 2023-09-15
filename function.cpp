#include "function.hpp"

void choosing_numbers(string& input) {
  string output;
  for (char c : input) {
    if (isdigit(c)) {
      output += c;
    }
  }
  input = output;
}
