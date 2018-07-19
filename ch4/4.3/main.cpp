/* 4-3. What happens if we rewrite the previous program to allow values up to
 * but not including 1000 but neglect to change the arguments to setw? Rewrite
 * the program to be more robust in the face of changes that allow i to grow
 * without adjusting the setw arguments.
 */

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>

std::size_t number_of_chars(int n) {
  std::size_t result;
  if (n == 0) {
    result = 1;
  } else if (n < 0) {
    n = -n;
    result = std::log10(n) + 2;
  } else {
    result = std::log10(n) + 1;
  }
  return result;
}

void print_squares(int start, int end) {
  std::size_t start_char_num = number_of_chars(start);
  std::size_t end_char_num = number_of_chars(end);
  std::size_t width1, width2;

  if (start_char_num > end_char_num) {
    width1 = start_char_num;
    width2 = number_of_chars(start * start) + 1;
  } else if (start_char_num < end_char_num) {
    width1 = end_char_num;
    width2 = number_of_chars(end * end) + 1;
  } else {
    if (start > end) {
      width1 = start_char_num;
      width2 = number_of_chars(start * start) + 1;
    } else {
      width1 = end_char_num;
      width2 = number_of_chars(end * end) + 1;
    }
  }

  int step = start > end ? -1 : 1;

  int i;
  for (i = start; i != end; i += step)
    std::cout << std::setw(width1) << i << std::setw(width2) << i * i
              << std::endl;

  std::cout << std::setw(width1) << i << std::setw(width2) << i * i
            << std::endl;
}

int main() {
  // print_squares(100, -5);
  // print_squares(45, 23);
  // print_squares(23, 45);
  // print_squares(-40, -80);
  // print_squares(-80, -40);
  // print_squares(4, 9);
  // print_squares(9, 0);
  // print_squares(0, 99);
  // print_squares(99, 0);
  // print_squares(10, 99);
  print_squares(99, 10);
  return 0;
}
