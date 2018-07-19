/* 4-8. If the following code is legal, what can we infer about the return type
 * of it?
 * double d =f()[n];
 */

#include <cstddef>
#include <iostream>
#include <map>
#include <vector>

std::vector<double> f() {
  std::vector<double> result;
  result.push_back(14);
  result.push_back(22.12);
  return result;
}

std::map<int, double> f2() {
  std::map<int, double> result;
  result[1] = 123.054;
  result[5] = 0.381;
  return result;
}

int main() {
  const std::size_t n = 1;
  // we can infer that function f returns container which supports operator[]
  // it might be std::vector<double> or std::vector<int> or map<T, double>
  double d = f2()[n];
  std::cout << "f2()[1]: " << d << std::endl;
  d = f()[n];
  std::cout << "f1()[1]: " << d << std::endl;
  return 0;
}
