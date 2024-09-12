#include<iostream>
#include"course.h"
#include<string>
#include<iomanip>
Course::Course(std::string& SCode, std::string& SName, int& SCredits, std::string& SInstructor){
    Code = SCode;
    Name = SName;
    Credits = SCredits;
    Instructor = SInstructor;
}
Course inputCourse(){
    std::string SCode, SName, SInstructor;
    int SCredits;
    std::cout<<"Enter Course Code: ";
    std::getline(std::cin, SCode);
    std::cout<<"Enter Course Name: ";
    std::getline(std::cin, SName);
    std::cout<<"Enter Number of Credits: ";
    std::cin>>SCredits;
    std::cout<<"Enter Course Instructor: ";
    std::getline(std::cin, SInstructor);
    return Course(SCode, SName, SCredits, SInstructor); 
}
const std::string& Course::get_Code(){
    return Code;
}
const std::string& Course::get_Name(){
    return Name;
}
const int& Course::get_Credits(){
    return Credits;
}
const std::string& Course::get_Instructor(){
    return Instructor;
}
void Course::set_Code(std::string& SCode){
    Code = SCode;
}
void Course::set_Name(std::string& SName){
    Name = SName;
}
void Course::set_Credits(int& SCredits){
    Credits = SCredits;
}
void Course::set_Instructor(std::string& SInstructor){
    Instructor = SInstructor;
}
void Course::print_Course(){
    std::cout<<std::setw(12)<<std::left<<Code<<std::setw(30)<<std::left<<Name<<std::setw(10)<<std::left<<Credits<<std::setw(30)<<std::left<<Instructor<<'\n';
}