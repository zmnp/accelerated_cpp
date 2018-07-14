/* 3-4. Write a program to report the length of the longest and shortest string
 * in its input.
 */

#include <iostream>
#include <string>

int main() {
  std::cout << "Enter some words: ";
  std::string word; // current word
  std::string longest_word;
  std::string shortest_word;
  std::size_t max_len = 0;
  std::size_t min_len = 0;

  for (int i = 0; std::cin >> word; ++i) {
    if (i == 0) {
      min_len = max_len = word.size();
      longest_word = word;
      shortest_word = word;
    } else {
      if (min_len > word.size()) {
        shortest_word = word;
        min_len = word.size();
      }
      if (max_len < word.size()) {
        longest_word = word;
        max_len = word.size();
      }
    }
  }
  std::cout << std::endl;
  std::cout << "The length of the longest word (" << longest_word
            << ") that you entered is: " << max_len << std::endl;
  std::cout << "The length of the shortest word (" << shortest_word
            << ") that you entered is: " << min_len << std::endl;

  return 0;
}
