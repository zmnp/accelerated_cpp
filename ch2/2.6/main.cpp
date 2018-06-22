/* 2-6. What does the following code do? */

#include <iostream>

// this program prints numbers from 1 to 10
int main() {
  int i = 0;
  while (i < 10) {
    i += 1;
    std::cout << i << std::endl;
  }
  return 0;
}
