/* 2-9. Write a program that asks the user to enter two numbers and tells
 * the user which number is larger than the other.
 */

#include <iostream>

int main() {
  int n1, n2;
  std::cout << "Please enter the first number: ";
  std::cin >> n1;
  std::cout << "Please enter the second number: ";
  std::cin >> n2;

  if (n1 > n2) {
    std::cout << n1 << " is greater than " << n2 << std::endl;
  } else if (n2 > n1) {
    std::cout << n2 << " is greater than " << n1 << std::endl;
  } else {
    std::cout << n1 << " and " << n2 << " are equal" << std::endl;
  }
  return 0;
}
