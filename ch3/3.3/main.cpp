/* 3-3. Write a program to count how many times each distinct word appears in
 * its input. 
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::cout << "Enter some words: ";

  std::string word;                    // current word
  std::vector<std::string> dist_words; // collection of distinct words
  std::vector<int> counters; // counters for each word in dist_words vector

  std::size_t max_len = 0; // max len of the word so far
  while (std::cin >> word) {
    max_len = std::max(max_len, word.size());
    bool is_distinct = true;

    for (std::size_t i = 0; i < dist_words.size(); ++i) {
      if (dist_words[i] == word) {
        is_distinct = false;
        ++counters[i];
        break;
      }
    }
    if (is_distinct) {
      dist_words.push_back(word);
      counters.push_back(1);
    }
  }

  std::cout << std::endl;
  for (std::size_t i = 0; i < dist_words.size(); ++i) {
    std::cout << dist_words[i] << ":"
              << std::string(max_len - dist_words[i].size() + 1, ' ')
              << counters[i] << std::endl;
  }

  return 0;
}
