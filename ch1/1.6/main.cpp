/* 1-6. What does the following program do if, when it asks you for input,
 * you type two names (for example, Samuel Backett)? Predict the behavior
 * before running the program, then try it.
 */

#include <iostream>
#include <string>

int main() {
  std::cout << "What is your name? ";
  std::string name;

  // we type two words here, like "Sam Backett"
  // but std::cin reads only one word "Sam". There is a white
  // space character after this word so it stops here.
  std::cin >> name; // name contains string "Sam"
  std::cout << "Hello, " << name << std::endl << "And what is yours? ";
  // now std::cin reads next word which is "Backett". It stops reading further
  // because last character in this line is '\n'.
  std::cin >> name; // name contains string "Backett"
  std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
  return 0;
}

