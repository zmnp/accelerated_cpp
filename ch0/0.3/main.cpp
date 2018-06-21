/* 0-3. The string literal "\t" represents a tab character;
 * different C++ implementations display tabs in different ways.
 * Experiment with your implementation to learn how it treats tabs.
 */

#include <iostream>

int main() {
  std::cout << "\tTesting \\t escape sequence in the beginning.\n";
  std::cout << "Testing \\t escape\tsequence in the middle of the sentence\n";
  std::cout << "Testing \\t escape sequence in the end of the sentence\t\n";
  std::cout << "Testing\t\t2 \\t escape sequences in the middle of"
               " the sentence\n";

  std::cout << "\t\tTesting 2 \\t escape sequences in the beginning of"
               " the sentence\n";
  return 0;
}
