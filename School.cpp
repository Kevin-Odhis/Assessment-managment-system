#include"School.h"

void School::Display_Subjects()const{
    if(subjects.empty()){

    }else{
        size_t n{1};
        for(const auto& item:subjects){
            std::cout<<n<<". "<<item.Subject<<"- "<<item.Short_Name<<"\n";
        }
        ++n;
    }
}
void School::Read_File(){
        std::fstream myfile("Mid-Term 1 Result.csv",std::ios::in);
        if(myfile.is_open()){
            std::string line;
            myfile>>line;
            std::stringstream ss(line);
            std::string name;
            std::getline(ss,name,',');//skip name
            while(std::getline(ss,name,',')){
                if(!name.empty()){
                    subjects.emplace_back(name,name);
                }
            }
            std::string line2;
            while(std::getline(myfile,line2)){
                std::stringstream ss_line(line2);
                std::string name;
                std::getline(ss_line,name,',');
                if(!(name.empty())){
                    Students.emplace_back(std::make_shared<Student>(name,"GRADE 8"));
                
                auto learner=Students.back();
                
                for(auto& sub:subjects){
                    std::string score;
                    std::getline(ss_line,score,',');
                    if(!score.empty()){
                        double mark=std::stod(score);
                        if(mark<=100){//ignore total marks
                            learner->Add_Score(sub.Short_Name,mark);
                        }
                    }
                }
              }
            }
            myfile.close();
            std::cout<<"Data read from the file successfully\n";
    
        }else{
            std::cout<<"Opening file Error!\n";
        }
    
    }
    void School::Display_Students()const{
        if(Students.empty()){
            std::cout<<"No students to be displayed\n";
        }else{
            size_t n{1};
            for(const auto& stud:Students){
                std::cout<<n<<". "<<stud->Get_Name()<<"-> Total marks: "<<stud->Total_Marks()<<"\n";
                ++n;
            }
        }
    }
    void School::Add_Scores_For_Student(const std::string& sub){
        for(const auto& learner:Students){
            learner->Add_Score(sub);
        }
    
    }
    void School::Add_Student(const std::string& name, const std::string& grade){
        Students.emplace_back(std::make_shared<Student>(name,grade));
    
    }
    void School::Add_School_Subjects(const std::string& subj,const std::string& s_sub){
        subjects.emplace_back(subj,s_sub);
    
    }
    void School::Assign_subjects_to_learners(){
        for(const auto& item:subjects){
            for(auto &learner:Students){
                auto sub=learner->Get_Subjects();
                auto it=sub.find(item.Short_Name);
                if(it==sub.end()){//Checking if the subject is already added or not
                    learner->Add_Subject(item.Short_Name);
                }else{
                    //Do nothing
                }
                
            }
        }
    }
    
    void School::Write_File(){
        std::fstream myfile("Mid-Term 1 Result.csv",std::ios::out);
        if(myfile.is_open()){
            myfile<<"NAME"<<",";
            for(const auto& item:subjects){
                myfile<<item.Short_Name<<",";
            }
            myfile<<"TOTAL"<<","<<"\n";
            for(const auto& stude:Students){
                myfile<<stude->Get_Name()<<",";
                for(const auto& sub:stude->Get_Subjects()){
                    myfile<<sub.second<<",";
                }
                myfile<<stude->Total_Marks()<<","<<"\n";
            }
            myfile.close();
        }else{
            std::cout<<"Error! file did not open properly\n";
        }
    }