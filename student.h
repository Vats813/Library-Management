#pragma once
#include<string>
class Student{
private:
    std::string Name;
    std::string ID_Number;
    std::string Major;
    std::string Year;
public:
    Student(std::string& SID_Number, std::string& SName, std::string& SMajor, std::string& SYear);

    const std::string& get_Num();
    const std::string& get_Name();
    const std::string& get_Major();
    const std::string& get_Year();

    void set_Num(std::string& SID_Number);
    void set_Name(std::string& SName);
    void set_Major(std::string& SMajor);
    void set_Year(std::string& SYear);

    void print_Student();
};