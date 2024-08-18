#ifndef CSV_OPERATIONS_HPP
#define CSV_OPERATIONS_HPP

#include "../student_data/student_data.hpp"
#include <vector>
#include <string>

// Declaration of functions to load and convert student data from a CSV file
std::vector<Student> loadStudentData(const std::string& filename);
std::vector<Student> convertCSVToStudents(const std::vector<std::vector<std::string>>& csvData);

#endif // CSV_OPERATIONS_HPP
