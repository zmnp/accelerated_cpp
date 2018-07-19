// source file for Student_info-related functions

#include "Student_info.h"

// comparison function (predicate) that compares only names of Student_info
// struct to sort vector of this records alphabetically by name
bool compare(const Student_info &x, const Student_info &y) {
  return x.name < y.name;
}

// read Student_info record
std::istream &read(std::istream &is, Student_info &s) {
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;

  // read and store all student's homework grades
  read_hw(is, s.homework);
  return is;
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
