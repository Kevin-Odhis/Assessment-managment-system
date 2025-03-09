#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

struct Subjects {
    std::string Subject;
    std::string Short_Name;
    Subjects(const std::string& sub, const std::string& shortName) : Subject(sub), Short_Name(shortName) {}
};
#endif