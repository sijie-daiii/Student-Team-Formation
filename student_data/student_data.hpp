#ifndef STUDENT_DATA_HPP
#define STUDENT_DATA_HPP

#include "../skill_level/skill_level.hpp"
#include <iostream>
#include <vector>
#include <string>

// Struct to represent a student with various attributes
struct Student {
    std::string username;
    SkillLevel programmingSkill;
    SkillLevel debuggingSkill;
    SkillLevel algorithmSkill;
    std::vector<std::string> unwantedList; // List of students this student does not want to work with
    std::vector<std::string> preferredList; // List of students this student prefers to work with
    bool assigned;
};

#endif // STUDENT_DATA_HPP
