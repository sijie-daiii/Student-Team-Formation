#include "csv_operations/csv_operations.hpp"
#include "team_operations/team_operations.hpp"
#include "skill_level/skill_level.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int groupSize;
    string inputFile, outputFile;
    char userPreference;

    // Prompt user for input file, output file, team size, and preference for prioritizing student choices
    cout << "Enter the CSV file path: ";
    getline(cin, inputFile);
    cout << "Enter the output file path: ";
    getline(cin, outputFile);
    cout << "Enter team size (3 or 4): ";
    cin >> groupSize;
    cout << "Prioritize student preferences? (y/n): ";
    cin >> userPreference;

    // Load student data from the CSV file
    vector<Student> studentList = loadStudentData(inputFile);

    // Check if student data was successfully loaded
    if (studentList.empty()) {
        cerr << "Failed to load student data." << endl;
        return 1;
    }

    // Create project teams based on the loaded student data
    vector<vector<Student>> projectTeams = createTeams(studentList, groupSize);

    // Check if teams were successfully created
    if (projectTeams.empty()) {
        cerr << "Failed to create teams." << endl;
        return 1;
    }

    // Compute and display the team scores
    auto teamResults = computeTeamScores(projectTeams);
    displayTeamScores(projectTeams, teamResults);

    // Save the team results to the output file
    saveTeamResults(outputFile, projectTeams, teamResults);

    cout << "Results written to " << outputFile << endl;

    return 0;
}
