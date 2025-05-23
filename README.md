# project-SYSTEM-LEARNING-SCHOOL-SLS-C-

In collaboration with the students of the Faculty of Computer Science and Artificial Intelligence at Sphinx University 

# Faculty Data Management System

This is a simple C++ console-based application designed to manage student and course data for a faculty system. It allows users to add, update, delete, and search for students and courses, as well as assign grades and view academic information.

## Features

### 1. Student Management
- Add a new student
- Update existing student details
- Delete a student by ID
- Display all students
- Display students categorized by academic level (1 to 4)
- Search for students by ID or name

### 2. Course Management
- Add a new course
- Update existing course details
- Delete a course by code
- Search for courses by code or name

### 3. Course Assignment
- Assign up to 5 courses per student
- Assign grades for each course

### 4. Performance Display
- Display the student with the highest grade in each course

## Data Structures Used
- `struct Student`: Represents a student with fields such as name, ID, group, level, GPA, and enrolled courses.
- `struct Course`: Represents a course with fields such as name, code, and credit hours.
- `struct StudentCourse`: Represents a student's course enrollment and grade.

## Limitations
- Maximum of 120 students
- Maximum of 12 courses
- Each student can enroll in up to 5 courses only

## How to Run
1. Compile the program using a C++ compiler (like g++, clang, or an IDE like Code::Blocks or Visual Studio).
2. Run the executable.
3. Follow the on-screen menu to manage students and courses.

## Sample Menu
