/* 4-2. Write a program to calculate the squares of int values up to 100. The
 * program should write two columns: The first lists the value; the second
 * contains the square of that value. Use setw (described above) to manage the
 * output so that the values line up in columns.
 */

#include <iomanip>
#include <iostream>

int main() {
  for (int i = 1; i <= 100; ++i)
    std::cout << std::setw(3) << i << std::setw(6) << i * i << std::endl;
  return 0;
}
