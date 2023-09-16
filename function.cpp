#include "function.hpp"

void choosing_numbers(string& input) {
  string output;
  for (char c : input) {
    if (isdigit(c) || isalpha(c)) {
      if (isdigit(c)) {
        output += c;
      }
    } else {
      output = "Error input!";
      break;
    }
  }
  input = output;
}
