#include<iostream>
#include"student.h"
#include<string>
#include<iomanip>
Student::Student(std::string& SID_Number, std::string& SName, std::string& SMajor, std::string& SYear){
    ID_Number = SID_Number;
    Name = SName;
    Major = SMajor;
    Year = SYear;
}
Student inputStudent(){
    std::string SID_Number, SName, SMajor, SYear;
    std::cout<<"Enter Student ID: ";
    std::getline(std::cin, SID_Number);
    std::cout<<"Enter Student Name: ";
    std::getline(std::cin, SName);
    std::cout<<"Enter Student Major: ";
    std::getline(std::cin, SMajor);
    std::cout<<"Enter Student Year: ";
    std::getline(std::cin, SYear);
    return Student(SID_Number, SName, SMajor, SYear); 
}
const std::string& Student::get_Num(){
    return ID_Number;
}
const std::string& Student::get_Name(){
    return Name;
}
const std::string& Student::get_Major(){
    return Major;
}
const std::string& Student::get_Year(){
    return Year;
}
void Student::set_Num(std::string& SID_Number){
    ID_Number = SID_Number;
}
void Student::set_Name(std::string& SName){
    Name = SName;
}
void Student::set_Major(std::string& SMajor){
    Major = SMajor;
}
void Student::set_Year(std::string& SYear){
    Year = SYear;
}
void Student::print_Student(){
    std::cout<<std::setw(10)<<std::left<<ID_Number<<std::setw(30)<<std::left<<Name<<std::setw(30)<<std::left<<Major<<std::setw(12)<<std::left<<Year<<'\n';
}