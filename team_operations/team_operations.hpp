#ifndef TEAM_OPERATIONS_HPP
#define TEAM_OPERATIONS_HPP

#include "../student_data/student_data.hpp"
#include <vector>
#include <array>
#include <string>
#include <algorithm>

// Declaration of functions for team operations
std::vector<std::vector<Student>> createTeams(std::vector<Student>& students, int teamSize);
std::vector<std::array<int, 3>> computeTeamScores(const std::vector<std::vector<Student>>& teams);
void displayTeamScores(const std::vector<std::vector<Student>>& teams, const std::vector<std::array<int, 3>>& scores);
void saveTeamResults(const std::string& filename, const std::vector<std::vector<Student>>& teams, const std::vector<std::array<int, 3>>& scores);
bool isInUnwantedList(const Student& student, const std::string& otherStudentName); // Ensure this is declared

#endif // TEAM_OPERATIONS_HPP
