#include "skill_level.hpp"

// Convert a string representation of skill level to an enum value
SkillLevel skillLevelFromString(const std::string& skillStr) {
    if (skillStr == "Beginner") {
        return SkillLevel::Beginner;
    } else if (skillStr == "Intermediate") {
        return SkillLevel::Intermediate;
    } else {
        return SkillLevel::Advanced;
    }
}
