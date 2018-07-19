/* 4-5. Write a function that reads words from an input stream and stores them
 * in a vector. Use that function both to write programs that count the number
 * of words in the input, and to count how many times each word occurred.
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

std::istream &read_words(std::istream &in, std::vector<std::string> &words) {
  if (in) {
    words.clear();

    std::string word;
    while (in >> word)
      words.push_back(word);

    in.clear();
  }
  return in;
}

int main() {
  std::vector<std::string> words;

  read_words(std::cin, words);
  std::cout << "Number of entered words: " << words.size() << std::endl;

  if (words.empty())
    return 1;

  std::sort(words.begin(), words.end());

  std::string curr_word = words[0];
  int wcounter = 1;

  for (std::size_t i = 1; i < words.size(); ++i) {
    if (curr_word != words[i]) {
      std::cout << curr_word << ": " << wcounter << std::endl;
      curr_word = words[i];
      wcounter = 1;
    } else {
      ++wcounter;
    }
  }
  std::cout << curr_word << ": " << wcounter << std::endl;
  return 0;
}
