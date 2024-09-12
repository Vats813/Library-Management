Student Database Management System (SDBMS).

Overview:
The Student Database Management System (SDBMS) is a console-based application developed in C++ that allows for the efficient management of student data, courses, and grades. 
The system supports operations like adding, updating, deleting, and searching for records related to students, courses, and grades. 
It also supports SQL queries for calculating student CGPA and reports on student enrollment by major.
It is designed to provide a simple yet effective way to organize and retrieve information for educational institutions.

Features:
1. Add Student Records: Input student details such as name, ID number, major, and academic year.
2. Add Courses: Store course information, including course code, name, and instructor.
3. Assign Grades: Record and manage student grades for different courses.
4. Update Records: Modify existing records for students, courses, or grades.
5. Delete Records: Safely remove student, course, or grade data when necessary.
6. Search Functionality: Quickly find students, courses, or grades based on key attributes.
7. View All Records: Display all student, course, or grade records stored in the system.
8. CGPA Calculator: Quickly calculate the CGPA of a student, given their grade records.

Entities:
1. Students:
      * Name: Full name of the student.
      * ID_Number: Unique identification number for each student.
      * Major: The student's field of study.
      * Year: The student's academic year (e.g., Freshman, Sophomore).

2. Courses:
      * Course_Code: Unique code identifying the course.
      * Name: Name of the course.
      * Credits: The number of credits assigned to the course.
      * Instructor: The name of the instructor teaching the course.

3. Grades:
      * Student_ID: The ID number of the student.
      * Course_Code: The code of the course the grade is assigned to.
      * Grade: The student's grade in the course.

Technologies Used:
* Programming Language: C++
* Data Storage: File system using text or binary files to store data persistently.
* File Handling: Implements C++ file I/O operations to read from and write to files for student, course, and grade information.

How to Run:

Prerequisites:\
A C++ compiler (e.g., GCC or MSVC)

Steps to Run the Program:
1. Clone the repository to your local machine.
```
git clone https://github.com/yourusername/sdbms.git
```
2. Navigate to the project directory.
```
cd sdbms
```
3. Compile the C++ source code.
```
g++ -o sdbms main.cpp
```
4. Run the compiled program.
```
./sdbms
```
File Structure: 
1. main.cpp: Contains the main logic of the program.
2. student.h: Header file for the Student class, containing attributes and methods for student management.
3. student.cpp: Implements the functionality of the Student class.
4. course.h: Header file for the Course class, containing attributes and methods for course management.
5. course.cpp: Implements the functionality of the Course class.
6. grade.h: Header file for the Grade class, containing attributes and methods for grade management.
7. grade.cpp: Implements the functionality of the Grade class.
8. data.txt: Stores student, course, and grade information (if using text files for storage).
   
How It Works:
1. Adding a Student: Prompts the user to enter a student's details (name, ID number, major, and year) and saves them to the database.
2. Adding a Course: Allows input of a course code, name, and instructor to the system.
3. Assigning Grades: Enter a student's ID, the course code, and their grade to record academic performance.
4. Updating Records: Modify existing student, course, or grade details.
5. Deleting Records: Remove student, course, or grade records when necessary.
6. Search Function: Lookup students, courses, or grades by their attributes (e.g., student ID, course code).
7. View All Records: Displays all records.
8. CGPA Calculator: Calculates the CGPA of a student, given their Student ID. 
   
Future Enhancements
1. Implement efficient sorting algorithms to display records in a particular order.
2. Add validation for input fields (e.g., ensuring unique course codes, student IDs).
3. Develop a GUI version for a better user experience.
4. Allow for more complex queries (e.g., view all students in a specific course).
5. Implement the database using B-trees.
