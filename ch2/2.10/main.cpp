/* 2-10. Explain each of the uses of std:: in the following program: */

#include <iostream>

int main() {
  const int n = 10;
  int k = 0;
  while (k != n) { // invariant: we have written k asterisks so far

    using std::cout; // here cout and std::cout are synonyms

    // we can use cout without std:: but only in this while loop scope
    cout << "*";
    ++k;
  }
  // there's no using-directive here in the main scope
  // so we can not use cout and endl without std::
  std::cout << std::endl; // std:: is required here
  return 0;
}
