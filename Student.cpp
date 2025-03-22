#include "Student.h"

void Student::Add_Score(const std::string& course) {
    auto it = Courses.find(course);
    if (it == Courses.end()) {
        std::cout << "The subject " << course << " is not found for " << Name << "!\n";
    } else {
         std::cout << "Enter "<< course <<"'s score for "<<Name<<"->";
        double score;
        while (!(std::cin >> score)) {
            std::cout << "Invalid input! Enter marks again -> ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        it->second = score;
    }
}
double Student::Total_Marks() const {
    Marks = 0;
    for (const auto& sub : Courses) {
        Marks += sub.second;
    }
    return Marks;
}

void Student::Add_Score(const std::string& course, double mar) {
    Courses[course] = mar;
}
std::string Student::Get_Level(){
    double mark=Total_Marks();
    if(mark<=300){
        return "B.E";
    }else if(mark<=449){
        return "A.E";
    }else if(mark<=700){
        return "M.E";
    }else{
        return "E.E";
    }
}