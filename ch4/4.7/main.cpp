/* 4-7. Write a program to calculate the average of the numbers
 * stored in a vector<double>.
 */

#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

double avrg(const std::vector<double> &vec) {
  typedef std::vector<double>::size_type vec_sz;
  vec_sz size = vec.size();

  if (size == 0)
    throw std::domain_error("average of an empty vector");

  double sum = 0;

  for (vec_sz i = 0; i < size; ++i)
    sum += vec[i];

  return sum / vec.size();
}

int main() {
  std::vector<double> values;
  double x;

  while (std::cin >> x)
    values.push_back(x);

  try {
    double avr = avrg(values);
    std::streamsize prec = std::cout.precision();

    std::cout << "Average value is: " << std::fixed << std::setprecision(3)
              << avr << std::setprecision(prec) << std::endl;

  } catch (std::domain_error e) {
    std::cout << "No values have been entered. Try again." << std::endl;
  }
  return 0;
}
