#include "csv_operations.hpp"
#include "../student_data/student_data.hpp"
#include "../skill_level/skill_level.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to load student data from a CSV file
std::vector<Student> loadStudentData(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    std::vector<std::vector<std::string>> csvContents;
    std::string row;

    // Read each row from the CSV file
    while (getline(inFile, row)) {
        std::vector<std::string> columns;
        std::stringstream ss(row);
        std::string data;
        // Split the row by commas and store the values in a vector
        while (getline(ss, data, ',')) {
            columns.push_back(data);
        }
        csvContents.push_back(columns);
    }

    inFile.close();

    // Remove header row if present
    if (!csvContents.empty()) {
        csvContents.erase(csvContents.begin());
    }

    // Convert the CSV data to a vector of Student objects
    return convertCSVToStudents(csvContents);
}

// Function to convert CSV data to a vector of Student objects
std::vector<Student> convertCSVToStudents(const std::vector<std::vector<std::string>>& csvData) {
    std::vector<Student> students;

    // Iterate through each row of CSV data
    for (const auto& row : csvData) {
        Student student;
        student.username = row[0];
        student.programmingSkill = skillLevelFromString(row[1]);
        student.debuggingSkill = skillLevelFromString(row[2]);
        student.algorithmSkill = skillLevelFromString(row[3]);

        // Parse the list of students the current student does not want to work with
        std::istringstream avoidStream(row[4]);
        std::string avoidStudent;
        while (std::getline(avoidStream, avoidStudent, ':')) {
            student.unwantedList.push_back(avoidStudent);
        }

        // Parse the list of students the current student prefers to work with
        std::istringstream preferStream(row[5]);
        std::string preferStudent;
        while (std::getline(preferStream, preferStudent, ':')) {
            student.preferredList.push_back(preferStudent);
        }

        student.assigned = false; // Initialize the assigned flag to false
        students.push_back(student);
    }

    return students;
}
