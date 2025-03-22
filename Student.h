#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <unordered_map>
#include <iostream>
#include <cctype>

class Student {
private:
    std::string Name;
    std::string Grade;
    mutable double Marks{};
    std::unordered_map<std::string, double> Courses;
public:
    Student(const std::string& name, const std::string& grade) : Name(name), Grade(grade) {}
    void Add_Grade(const std::string& grade) { Grade = grade; }
    void Add_Subject(const std::string& sub) { Courses[sub] = 0; }
    double Total_Marks() const;
    void Add_Name(const std::string& name) { Name = name; }
    std::string Get_Name() const { return Name; }
    void Add_Score(const std::string& course);
    void Add_Score(const std::string& course, double mar);
    std::unordered_map<std::string, double> Get_Subjects() const { return Courses; }
    std::string Get_Level();
};
#endif