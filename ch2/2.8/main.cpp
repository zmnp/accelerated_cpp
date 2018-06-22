/* 2-8. Write a program to generate the product of the numbers in the
 * range [1, 10).
 */

#include <iostream>

int main() {
  int product = 1;
  for (int i = 1; i < 10; ++i) {
    product *= i;
  }
  std::cout << "Product of the numbers in the range [1, 10): " << product
            << std::endl;
  return 0;
}
