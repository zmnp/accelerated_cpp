/* 4-4. Now change your squares program to use double values instead of ints.
 * Use manipulators to manage the output so that the values line up in columns.
 */

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

void print_squares(double start, double end, double step,
                   int digits_after_point) {
  std::size_t start_char_num = number_of_chars(start);
  std::size_t end_char_num = number_of_chars(end);

  std::size_t width1, width2;

  if (start_char_num > end_char_num) {
    width1 = start_char_num;
    width2 = number_of_chars(start * start);
  } else if (start_char_num < end_char_num) {
    width1 = end_char_num;
    width2 = number_of_chars(end * end);
  } else {
    if (start > end) {
      width1 = start_char_num;
      width2 = number_of_chars(start * start);
    } else {
      width1 = end_char_num;
      width2 = number_of_chars(end * end);
    }
  }

  width1 += 1 + digits_after_point; // 1 for space
  width2 += 2 + digits_after_point; // 1 for space and 1 for dot

  std::cout << std::fixed << std::setprecision(digits_after_point);
  if (start < end) {
    for (double i = start; i <= end; i += step) {
      std::cout << std::setw(width1) << i << std::setw(width2) << i * i
                << std::endl;
    }
  } else {
    for (double i = start; i >= end; i -= step) {
      std::cout << std::setw(width1) << i << std::setw(width2) << i * i
                << std::endl;
    }
  }
}

int main() {
  // print_squares(-123.21, 23.34, 0.5, 4);
  //  print_squares(23.43, -123.23, 0.5, 2);
  //  print_squares(45.34, 23.98, 0.04, 3);
  //  print_squares(23.98, 45.34, 0.5, 1);
  //  print_squares(9.12, 2.41, 0.17, 4);
  //  print_squares(2.41, 9.12, 0.17, 3);
  // print_squares(-5.45, -24.45, 2.34, 2);
  print_squares(-24.45, -5.45, 2.34, 4);
  //  print_squares(5, 6, 0.005, 3);
  //   print_squares(1, 9.999, 0.005, 3);
  //  print_squares(9.999, 1, 0.005, 3);
  return 0;
}
