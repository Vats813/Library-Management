#pragma once
#include<string>
class Course{
private:
    std::string Code;
    std::string Name;
    int Credits;
    std::string Instructor;
public:
    Course(std::string& SCode, std::string& SName, int& SCredits, std::string& SInstructor);

    const std::string& get_Code();
    const std::string& get_Name();
    const int& get_Credits();
    const std::string& get_Instructor();

    void set_Code(std::string& SCode);
    void set_Name(std::string& SName);
    void set_Credits(int& SCredits);
    void set_Instructor(std::string& SInstructor);

    void print_Course();
};