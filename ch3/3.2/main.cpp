/* 3-2. Write a program to compute and print the quartiles (that is, the quarter
 * of the numbers with the largest values, the next highest quarter, and so on)
 * of a set of integers.
 */

#include <algorithm>
#include <iostream>
#include <vector>

// using method 1 from https://en.wikipedia.org/wiki/Quartile
int main() {
  std::vector<int> values;

  std::cout << "Please enter integer values: ";

  int x;
  while (std::cin >> x)
    values.push_back(x);

  if (values.size() < 2) {
    std::cout << "You must enter at least 2 numbers. Try again." << std::endl;
    return 1;
  }

  std::sort(values.begin(), values.end());

  std::size_t total_size = values.size(); // size of the values array

  // find middle point of the entire sequence
  // mid here is also the number of values in the upper and lower halves
  std::size_t mid = total_size / 2;

  // find the median value of the entire sequence
  double median =
      total_size % 2 == 0 ? (values[mid] + values[mid - 1]) / 2.0 : values[mid];

  double q2 = median;
  double q1, q3;
  // If there are an odd number of data points in the original ordered data set,
  // do not include the median in either half
  // If there are an even number of data points in the original ordered data
  // set, split this data set exactly in half.

  // the median of the lower half
  std::size_t lmid = mid / 2;
  double lmedian =
      mid % 2 == 0 ? (values[lmid] + values[lmid - 1]) / 2.0 : values[lmid];

  // the median of the upper half
  std::size_t hmid =
      total_size % 2 == 0 ? (total_size + mid) / 2 : (mid + total_size + 1) / 2;
  double hmedian =
      mid % 2 == 0 ? (values[hmid] + values[hmid - 1]) / 2.0 : values[hmid];

  // The lower quartile value is the median of the lower half of the data
  q1 = lmedian;

  // The upper quartile value is the median of the upper half of the data.
  q3 = hmedian;

  std::cout << std::endl;
  std::cout << "Q1: " << q1 << std::endl;
  std::cout << "Q2: " << q2 << std::endl;
  std::cout << "Q3: " << q3 << std::endl;

  return 0;
}
