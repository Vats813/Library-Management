#include<iostream>
#include"grade.h"
#include<string>
#include<iomanip>
Grade::Grade(std::string& SID, std::string& SCode, std::string& SGrade){
    Student_ID = SID;
    Course_Code = SCode;
    Grade_ = SGrade;
}
Grade inputGrade(){
    std::string SID, SCode, SGrade;
    std::cout<<"Enter Student ID: ";
    std::getline(std::cin, SID);
    std::cout<<"Enter Course Code: ";
    std::getline(std::cin, SCode);
    std::cout<<"Enter Grade: ";
    std::getline(std::cin, SGrade);
    return Grade(SID, SCode, SGrade); 
}
const std::string& Grade::get_SID(){
    return Student_ID;
}
const std::string& Grade::get_Code(){
    return Course_Code;
}
const std::string& Grade::get_Grade(){
    return Grade_;
}
void Grade::set_SID(std::string& SID){
    Student_ID = SID;
}
void Grade::set_Code(std::string& SCode){
    Course_Code = SCode;
}
void Grade::set_Grade(std::string& SGrade){
    Grade_ = SGrade;
}
void Grade::print_Grade(){
    std::cout<<std::setw(12)<<std::left<<Student_ID<<std::setw(12)<<std::left<<Course_Code<<std::setw(5)<<std::left<<Grade_<<'\n';
}