/* 4-6. Rewrite the Student_info structure to calculate the grades immediately
 * and store only the final grade.
 */

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

struct Student_info {
  std::string name;
  double final_grade;
};

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(std::vector<double> vec) {
  typedef std::vector<double>::size_type vec_sz;

  vec_sz size = vec.size();

  if (size == 0)
    throw std::domain_error("median of an empty vector");

  std::sort(vec.begin(), vec.end());

  vec_sz mid = size / 2;

  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2.0 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades and
// homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const std::vector<double> &hw) {
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

// comparison function (predicate) that compares only names of Student_info
// struct to sort vector of this records alphabetically by name
bool compare(const Student_info &x, const Student_info &y) {
  return x.name < y.name;
}

// read homework grades from an input stream into a 'vector'
std::istream &read_hw(std::istream &in, std::vector<double> &hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);

    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

// read Student_info record
std::istream &read(std::istream &is, Student_info &s) {
  // read the student's name and midterm and final exam grades
  double midterm, final;
  std::vector<double> homework;

  is >> s.name >> midterm >> final;

  // read all student's homework grades
  read_hw(is, homework);

  double final_grade;
  try {
    final_grade = grade(midterm, final, homework);
  } catch (std::domain_error &e) {
    final_grade = -1;
  }
  s.final_grade = final_grade;
  return is;
}

int main() {
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0; // the length of the longest name

  // read students' name, midterm, final exam grades, and homework grades
  // calculate final grade and store only name and final grade
  // if student doesn't have homework she'll have -1 for final grade
  while (read(std::cin, record)) {
    // find length of the longest name
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the records
  std::sort(students.begin(), students.end(), compare);

  // write names and grades
  for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {

    // write the name, padded on the right to maxlen + 1 characters
    std::cout << students[i].name
              << std::string(maxlen + 1 - students[i].name.size(), ' ');

    // write the grade
    if (students[i].final_grade == -1) {
      std::cout << "Student has done no homework, so we cannot calculate final "
                   "grade.";
    } else {
      std::streamsize prec = std::cout.precision();
      std::cout << std::setprecision(3) << students[i].final_grade
                << std::setprecision(prec);
    }
    std::cout << std::endl;
  }
  return 0;
}
