#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include"student.cpp"
#include"course.cpp"
#include"grade.cpp"
bool sortbyid(Student& a, Student& b){
    return a.get_Num() < b.get_Num();
}
bool sortbycode(Course& a, Course& b){
    return a.get_Code() < b.get_Code();
}
bool sortbyidG(Grade& a, Grade& b){
    return a.get_SID() < b.get_SID();
}
int binarySearchStudent(std::vector<Student>& students, std::string& ID_Num) {
    int low = 0;
    int high = students.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (students[mid].get_Num() == ID_Num) {
            return mid; 
        } else if (students[mid].get_Num() < ID_Num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}
void searchStudent(std::vector<Student> &students, std::string &ID_Num, const bool& update){
    int a = binarySearchStudent(students, ID_Num);
    if(a==-1){
        std::cout<<"Student not found.\n";
    }else if(update == false){
        students[a].print_Student();
    }else{
        std::cout<<"Field to be updated: \n1. Student ID\n2. Student Name\n3. Student Major\n4. Student Year\n";
        int ch;
        std::cin>>ch;
        std::string reset;
        getline(std::cin, reset);
        switch(ch){
            case 1:
                students[a].set_Num(reset);
                std::cout<<"Student ID updated\n";
                break;
            case 2:
                students[a].set_Name(reset);
                std::cout<<"Student Name updated\n";
                break;
            case 3:
                students[a].set_Major(reset);
                std::cout<<"Student Major updated\n";
                break;
            case 4:
                students[a].set_Year(reset);
                std::cout<<"Student Year updated\n";
                break;
            default:
                std::cout<<"Invalid argument! Returning.\n";
        }
    }
}
int binarySearchCourse(std::vector<Course>& courses, std::string& CCode) {
    int low = 0;
    int high = courses.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (courses[mid].get_Code() == CCode) {
            return mid; 
        } else if (courses[mid].get_Code() < CCode) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; 
}
void searchCourse(std::vector<Course> & courses, std::string &CCode, const bool& update){
    int a = binarySearchCourse(courses, CCode);
    if(a==-1){
        std::cout<<"Course not found.\n";
    }else if(update == false){
        courses[a].print_Course();
    }else{
        std::cout<<"Field to be updated: \n1. Course Code\n2. Course Name\n3. Course Credits\n4. Course Instructor\n";
        int ch;
        std::cin>>ch;
        std::string reset;
        getline(std::cin, reset);
        switch(ch){
            case 1:
                courses[a].set_Code(reset);
                std::cout<<"Course Code updated\n";
                break;
            case 2:
                courses[a].set_Name(reset);
                std::cout<<"Course Name updated\n";
                break;
            case 3:
                int reset1 = std::stoi(reset);
                courses[a].set_Credits(reset1);
                std::cout<<"Course Credits updated\n";
                break;
            case 4:
                courses[a].set_Instructor(reset);
                std::cout<<"Course Instructor updated\n";
                break;
            default:
                std::cout<<"Invalid argument! Returning.\n";
        }
    }
}
int binarySearchGrade(std::vector<Grade>& grades, std::string& ID_Num, std::string& CCode) {
    int low = 0;
    int high = grades.size() - 1;
    int flag = 0;
    int mid = low + (high - low) / 2;

    while (low <= high) {
        if (grades[mid].get_SID() == ID_Num) {
            flag = 1;
            break;
        } else if (grades[mid].get_SID() < ID_Num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = low + (high - low)/2 ; 
    }

    if(flag==1){
        while(grades[mid].get_SID() == ID_Num){
            if(grades[mid].get_Code() == CCode){
                return mid;
            }else{
                mid++;
            }
        }
        return -1;
    }else{
        return -1;
    }
}
void searchGrade(std::vector<Grade> &grades, std::string &ID_Num, std::string &CCode, const bool& update){
    int a = binarySearchGrade(grades, ID_Num, CCode);
    if(a==-1){
        std::cout<<"Grade not found.\n";
    }else if(update == false){
        grades[a].print_Grade();
    }else{
        std::cout<<"Field to be updated: \n1. Student ID\n2. Course Code\n3. Grade\n";
        int ch;
        std::cin>>ch;
        std::string reset;
        getline(std::cin, reset);
        switch(ch){
            case 1:
                grades[a].set_SID(reset);
                std::cout<<"Student ID updated\n";
                break;
            case 2:
                grades[a].set_Code(reset);
                std::cout<<"Course Code updated\n";
                break;
            case 3:
                grades[a].set_Grade(reset);
                std::cout<<"Grade updated\n";
                break;
            default:
                std::cout<<"Invalid argument! Returning.\n";
        }
    }
}
void deleteStudent(std::vector<Student>& students, std::string& ID_Num){
    int a = binarySearchStudent(students, ID_Num);
    if(a!=-1){
        students.erase(students.begin() + a);
        std::cout<<"Student deleted\n";
    }else{
        std::cout<<"Student not found\n";
    }
}
void deleteCourse(std::vector<Course>& courses, std::string& CCode){
    int a = binarySearchCourse(courses, CCode);
    if(a!=-1){
        courses.erase(courses.begin() + a);
        std::cout<<"Course deleted\n";
    }else{
        std::cout<<"Course not found\n";
    }
}
void deleteGrade(std::vector<Grade>& grades, std::string& ID_Num, std::string& CCode){
    int a = binarySearchGrade(grades, ID_Num, CCode);
    if(a!=-1){
        grades.erase(grades.begin() + a);
        std::cout<<"Grade deleted\n";
    }else{
        std::cout<<"Grade not found\n";
    }
}
void saveStudentsToFile(std::vector<Student>& students, const std::string& filename) {
    std::ofstream file(filename);
    for (Student& student : students) {
        file << student.get_Num() << "," << student.get_Name() << "," << student.get_Major() << "," << student.get_Year() << "\n";
    }
    file.close();
}
void saveCoursesToFile(std::vector<Course>& courses, const std::string& filename) {
    std::ofstream file(filename);
    for (Course& course : courses) {
        file << course.get_Code() << "," << course.get_Name() << "," << course.get_Credits()<< "," << course.get_Instructor() << "\n";
    }
    file.close();
}
void saveGradesToFile(std::vector<Grade>& grades, const std::string& filename) {
    
    std::ofstream file(filename);
    for (Grade& grade: grades) {
        file << grade.get_SID() << "," << grade.get_Code() << "," << grade.get_Grade()<< "\n";
    }
    file.close();
}
void loadStudentsFromFile(std::vector<Student>& students, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string ID, Name, Major, Year;
        std::getline(ss, ID, ',');
        std::getline(ss, Name, ',');
        std::getline(ss, Major, ',');
        std::getline(ss, Year);

        students.emplace_back(ID, Name, Major, Year);
    }
    file.close();
}
void loadCoursesFromFile(std::vector<Course>& courses, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string Code, Name, Credits, Instructor;
        std::getline(ss, Code, ',');
        std::getline(ss, Name, ',');
        std::getline(ss, Credits, ',');
        std::getline(ss, Instructor, ',');
        int credits = std::stoi(Credits);

        courses.emplace_back(Code, Name, credits, Instructor);
    }
    file.close();
}
void loadGradesFromFile(std::vector<Grade>& grades, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string SID, Code, Grade;
        std::getline(ss, SID, ',');
        std::getline(ss, Code, ',');
        std::getline(ss, Grade);

        grades.emplace_back(SID, Code, Grade);
    }
    file.close();
}
void addStudent(std::vector<Student>& students) {
    Student newStudent = inputStudent();
    students.push_back(newStudent);
}
void addCourse(std::vector<Course>& courses) {
    Course newCourse = inputCourse();
    courses.push_back(newCourse);
}
void addGrade(std::vector<Grade>& grades) {
    Grade newGrade = inputGrade();
    grades.push_back(newGrade);
}
void displayAllStudents(std::vector<Student>& students) {
std::cout<<std::setw(10)<<std::left<<"Student ID"<<std::setw(30)<<std::left<<"Student Name"<<std::setw(30)<<std::left<<"Major"<<std::setw(12)<<std::left<<"Year"<<'\n';
    for (Student& student : students) {
        student.print_Student();
    }
}
void displayAllCourses(std::vector<Course>& courses) {
std::cout<<std::setw(12)<<std::left<<"Course Code"<<std::setw(30)<<std::left<<"Course Name"<<std::setw(10)<<std::left<<"Credits"<<std::setw(30)<<std::left<<"Course Instructor"<<'\n';
    for (Course& course : courses) {
        course.print_Course();
    }
}
void displayAllGrades(std::vector<Grade>& grades) {
std::cout<<std::setw(12)<<std::left<<"Student ID"<<std::setw(12)<<std::left<<"Course Code"<<std::setw(5)<<std::left<<"Grade"<<'\n';
    for (Grade& grade : grades) {
        grade.print_Grade();
    }
}
int main(){
    std::vector<Student> students;
    std::vector<Course> courses;
    std::vector<Grade> grades;
    loadStudentsFromFile(students, "students.txt");
    loadCoursesFromFile(courses, "courses.txt");
    loadGradesFromFile(grades, "grades.txt");
    int choice;
    int subch;
    do {
        std::cout<<"\n1. Add to a Database\n2. Update a Database\n3. Search a Database\n4. Delete from a Database.\n5. Display a Database\n6. Save and Exit\n";
        std::cin>>choice;
        if(choice == 5){
            std::cout<<"\n1. Student Database\n2. Course Database\n3. Grade Database\n";
            std::cin>>subch;
            switch(subch){
                case 1:
                    displayAllStudents(students);
                case 2:
                    displayAllCourses(courses);
                case 3:
                    displayAllGrades(grades);
            }
        }else if(choice == 6){
            saveStudentsToFile(students, "students.txt");
            saveCoursesToFile(courses, "courses.txt");
            saveGradesToFile(grades, "grades.txt");
            std::cout << "Data saved. Exiting...\n";
            break;
        }else if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
            std::cout<<"\n1. Student Database\n2. Course Database\n3. Grade Database\n";
            std::cin>>subch;
            std::string ID_Num;
            std::string CCode;
            switch(choice){
                case 1:
                    switch(subch){
                        case 1:
                            addStudent(students);
                            std::sort(students.begin(), students.end(), sortbyid);
                            break;
                        case 2:
                            addCourse(courses);
                            std::sort(courses.begin(), courses.end(), sortbycode);
                            break;
                        case 3:
                            addGrade(grades);
                            std::sort(grades.begin(), grades.end(), sortbyidG);
                            break;
                        default:
                            std::cout<<"Invalid choice!\n";
                            break;
                    }
                case 2:
                    switch(subch){
                        case 1:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            searchStudent(students, ID_Num, true);
                            std::sort(students.begin(), students.end(), sortbyid);
                            break;
                        case 2:
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            searchCourse(courses, CCode, true);
                            std::sort(courses.begin(), courses.end(), sortbycode);
                            break;
                        case 3:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            searchGrade(grades, ID_Num, CCode, true);
                            std::sort(grades.begin(), grades.end(), sortbyidG);
                            break;
                        default:
                            std::cout<<"Invalid choice!\n";
                            break;
                    }
                case 3:
                    switch(subch){
                        case 1:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            searchStudent(students, ID_Num, false);
                            break;
                        case 2:
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            searchCourse(courses, CCode, false);
                            break;
                        case 3:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            searchGrade(grades, ID_Num, CCode, false);
                            break;
                        default:
                            std::cout<<"Invalid choice!\n";
                            break;
                    }
                case 4:
                    switch(subch){
                        case 1:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            deleteStudent(students, ID_Num);
                            break;
                        case 2:
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            deleteCourse(courses, CCode);
                            break;
                        case 3:
                            std::cout<<"Enter Student ID:\n";
                            getline(std::cin, ID_Num);
                            std::cout<<"Enter Course Code:\n";
                            getline(std::cin, CCode);
                            deleteGrade(grades, ID_Num, CCode);
                            break;
                        default:
                            std::cout<<"Invalid choice!\n";
                            break;
                    }
            }   
        }else{
            std::cout<<"Invalid Choice!\n";
        }
    } while (choice != 6);
}