#include "School.h"

char menu();
void Exam_Management();

int main() {
    Exam_Management();
    return 0;
}

char menu() {
    std::cout << "Press:\n1. Register student\n2. Add subjects\n3. Add marks\n4. Save to file\n5. To upload from file\n"
    "6. To view students\n0. Exit\n-> ";
    char op;
    while (!(std::cin >> op)) {
        std::cout << "Invalid input, try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }
    return op;
}
void Exam_Management() {
    School grade8;
    bool running = true;
    while (running) {

        char op = menu();
        switch (op) {
            case '1': {
                std::string name, grade;
                std::cout << "Enter full name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter grade: ";
                std::cin >> grade;
                grade8.Add_Student(name, grade);
                break;
            }
            case '2': {
                std::string sub, s_sub;
                std::cout << "Enter subject: ";
                std::cin >> sub;
                std::cout << "Enter short name: ";
                std::cin >> s_sub;
                grade8.Add_School_Subjects(sub, s_sub);
                break;
            }
            case '3': {
                grade8.Assign_subjects_to_learners();
                grade8.Display_Subjects();
                std::string name;
                std::cout << "Enter subject short name: ";
                std::cin >> name;
                for(auto&ch:name){
                    ch=std::toupper(ch);
                }
                grade8.Add_Scores_For_Student(name);
                break;
            }
            case '4':
            {
                std::string filename;
                std::cout<<"Enter the name of the file to save:->";
                std::cin.ignore();
                std::getline(std::cin,filename);
                std::cout<<"saving to file "<<filename<<"\n";
                grade8.Write_File(filename);
                std::cout<<"Data saved to file successfully\n";
                break;
            }
            case '0':
                running = false;
                break;
            case '5':
                grade8.Read_File();
                break;
            case '6':
                grade8.Display_Students();
                break;
            default:
                std::cout << "Invalid option, try again.\n";
        }
    }
} 