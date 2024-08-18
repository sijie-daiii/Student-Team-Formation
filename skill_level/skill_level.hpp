#ifndef SKILL_LEVEL_HPP
#define SKILL_LEVEL_HPP

#include <string>

// Enum to represent different skill levels
enum class SkillLevel { Beginner = 1, Intermediate, Advanced };

// Function to convert a string to a SkillLevel enum
SkillLevel skillLevelFromString(const std::string& skillStr);

#endif // SKILL_LEVEL_HPP
