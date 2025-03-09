#ifndef SCHOOL_H
#define SCHOOL_H
#include "Student.h"
#include "Subjects.h"
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>

class School {
private:
    std::vector<std::shared_ptr<Student>> Students;
    std::vector<Subjects> subjects;
public:
    void Add_Student(const std::string& name, const std::string& grade);
    void Add_School_Subjects(const std::string& subj, const std::string& s_sub);
    std::vector<Subjects> Get_Subjects() const { return subjects; }
    void Write_File();
    void Read_File();
    void Display_Students() const;
    void Add_Scores_For_Student(const std::string& sub);
    void Assign_subjects_to_learners();
    void Display_Subjects()const;
};
#endif