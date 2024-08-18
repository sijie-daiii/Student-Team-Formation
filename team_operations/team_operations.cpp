#include "team_operations.hpp"
#include "../skill_level/skill_level.hpp"
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include <sstream>

// Check if a student is in another student's unwanted list
bool isInUnwantedList(const Student& student, const std::string& otherStudentName) {
    return std::find(student.unwantedList.begin(), student.unwantedList.end(), otherStudentName) != student.unwantedList.end();
}

// Function to create teams based on student data and team size
std::vector<std::vector<Student>> createTeams(std::vector<Student>& students, int teamSize) {
    std::vector<std::vector<Student>> projectTeams;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(students.begin(), students.end(), generator); // Shuffle students to randomize order

    // Check if the number of students is divisible by the team size
    if (students.size() % teamSize != 0) {
        std::cerr << "Number of students is not divisible by the team size." << std::endl;
        return {};
    }

    int totalTeams = students.size() / teamSize;
    for (auto& student : students) {
        if (!student.assigned) {
            std::vector<Student> team;
            student.assigned = true;
            team.push_back(student);

            for (auto& otherStudent : students) {
                if (team.size() < teamSize && !otherStudent.assigned && !isInUnwantedList(student, otherStudent.username)) {
                    otherStudent.assigned = true;
                    team.push_back(otherStudent);
                }
            }
            projectTeams.push_back(team);
        }
    }

    return projectTeams;
}

// Function to compute scores for each team
std::vector<std::array<int, 3>> computeTeamScores(const std::vector<std::vector<Student>>& teams) {
    std::vector<std::array<int, 3>> scores;

    for (const auto& team : teams) {
        int progScore = 0, debugScore = 0, algoScore = 0;
        for (const auto& member : team) {
            progScore += static_cast<int>(member.programmingSkill);
            debugScore += static_cast<int>(member.debuggingSkill);
            algoScore += static_cast<int>(member.algorithmSkill);
        }
        scores.push_back({progScore, debugScore, algoScore});
    }

    return scores;
}

// Function to display team scores on the console
void displayTeamScores(const std::vector<std::vector<Student>>& teams, const std::vector<std::array<int, 3>>& scores) {
    std::cout << "Team Scores:\n";
    for (size_t i = 0; i < teams.size(); ++i) {
        const auto& score = scores[i];
        std::cout << "Team " << i + 1 << ": Programming " << score[0] << ", Debugging " << score[1] << ", Algorithms " << score[2] << '\n';
    }
}

// Function to save team results to a CSV file
void saveTeamResults(const std::string& filename, const std::vector<std::vector<Student>>& teams, const std::vector<std::array<int, 3>>& scores) {
    std::ofstream outFile(filename);
    outFile << "Team number,Student usernames,Combined scores\n";
    for (size_t i = 0; i < teams.size(); ++i) {
        outFile << "Team " << i + 1 << ",";
        for (size_t j = 0; j < teams[i].size(); ++j) {
            outFile << teams[i][j].username;
            if (j < teams[i].size() - 1) {
                outFile << ";";
            }
        }
        auto score = scores[i];
        outFile << "," << score[0] << ";" << score[1] << ";" << score[2] << "\n";
    }
}
