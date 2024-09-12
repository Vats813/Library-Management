#pragma once
#include<string>
class Grade{
private:
    std::string Student_ID;
    std::string Course_Code;
    std::string Grade_;
public:
    Grade(std::string& SID, std::string& SCode, std::string& SGrade);

    const std::string& get_SID();
    const std::string& get_Code();
    const std::string& get_Grade();

    void set_SID(std::string& SID);
    void set_Code(std::string& SCode);
    void set_Grade(std::string& SGrade);

    void print_Grade();
};