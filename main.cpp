#include <iostream>
using namespace std;

// Struct of courses

struct Course {
    string name;
    string code;
    int creditHours;
};

// Struct for courses of student degree
struct StudentCourse {
    string courseCode;
    float degree;
};

// Struct of student
struct Student {
    string name;
    string id;
    string group;
    int level;
    float gpa;
    StudentCourse courses[5];  // limit 5 courses
};

Student students[120];
Course courses[12];
int studentCount = 0;
int courseCount = 0;

// start programm
void printGinfo() {
    cout << "You logged in " << endl;
        cout << " " << endl;

}




// student mangement task 2 by...
void addStudent() {
    if (studentCount >= 120) {
        cout << "Maximum number of students reached.\n";
        return;
    }

    Student newStudent;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    cout << "Enter student ID: ";
    getline(cin, newStudent.id);

    cout << "Enter group: ";
    getline(cin, newStudent.group);

    cout << "Enter level (1-4): ";
    cin >> newStudent.level;

    cout << "Enter GPA: ";
    cin >> newStudent.gpa;

    students[studentCount++] = newStudent;

    cout << "Student added successfully!\n";
}

void updateStudent() {
    string id;
    cout << "Enter student ID to update: ";
    cin.ignore();
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            found = true;

            cout << "Current name: " << students[i].name << endl;
            cout << "Enter new name (or press enter to keep): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) students[i].name = newName;

            cout << "Current group: " << students[i].group << endl;
            cout << "Enter new group (or press enter to keep): ";
            string newGroup;
            getline(cin, newGroup);
            if (!newGroup.empty()) students[i].group = newGroup;

            cout << "Current level: " << students[i].level << endl;
            cout << "Enter new level (or -1 to keep): ";
            int newLevel;
            cin >> newLevel;
            if (newLevel != -1) students[i].level = newLevel;

            cout << "Current GPA: " << students[i].gpa << endl;
            cout << "Enter new GPA (or -1 to keep): ";
            float newGPA;
            cin >> newGPA;
            if (newGPA != -1) students[i].gpa = newGPA;

            cout << "Student updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void deleteStudent() {
    string id;
    cout << "Enter student ID to delete: ";
    cin.ignore();
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            found = true;

            for (int j = i; j < studentCount - 1; ++j) {
                students[j] = students[j + 1];
            }

            studentCount--;
            cout << "Student deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}


// student mangement task 2 by...


// courses mangement task 3 by ....

void addCourse() {
    if (courseCount >= 12) {
        cout << "Maximum number of courses reached.\n";
        return;
    }

    Course newCourse;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, newCourse.name);

    cout << "Enter course code: ";
    getline(cin, newCourse.code);

    cout << "Enter credit hours: ";
    cin >> newCourse.creditHours;

    courses[courseCount++] = newCourse;

    cout << "Course added successfully!\n";
}

void updateCourse() {
    string code;
    cout << "Enter course code to update: ";
    cin.ignore();
    getline(cin, code);

    bool found = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].code == code) {
            found = true;

            cout << "Current course name: " << courses[i].name << endl;
            cout << "Enter new course name (or press enter to keep): ";
            string newName;
            getline(cin, newName);
            if (!newName.empty()) courses[i].name = newName;

            cout << "Current credit hours: " << courses[i].creditHours << endl;
            cout << "Enter new credit hours (or -1 to keep): ";
            int newCreditHours;
            cin >> newCreditHours;
            if (newCreditHours != -1) courses[i].creditHours = newCreditHours;

            cout << "Course updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Course not found.\n";
    }
}

void deleteCourse() {
    string code;
    cout << "Enter course code to delete: ";
    cin.ignore();
    getline(cin, code);

    bool found = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].code == code) {
            found = true;

            for (int j = i; j < courseCount - 1; ++j) {
                courses[j] = courses[j + 1];
            }

            courseCount--;
            cout << "Course deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Course not found.\n";
    }
}

// courses mangement task 3 by ....


// searching and data show task 4 by ...
void displayAllStudents() {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }

    cout << "List of all students:\n";
    for (int i = 0; i < studentCount; ++i) {
        cout << "Name: " << students[i].name << ", ID: " << students[i].id
             << ", Level: " << students[i].level << ", GPA: " << students[i].gpa << endl;
    }
}

void displayMaxDegreeStudent() {
    if (studentCount == 0 || courseCount == 0) {
        cout << "No students or courses available.\n";
        return;
    }

    for (int i = 0; i < courseCount; ++i) {
        float maxDegree = -1;
        int maxIndex = -1;

        for (int j = 0; j < studentCount; ++j) {
            for (int k = 0; k < 5; ++k) {
                if (students[j].courses[k].courseCode == courses[i].code) {
                    if (students[j].courses[k].degree > maxDegree) {
                        maxDegree = students[j].courses[k].degree;
                        maxIndex = j;
                    }
                }
            }
        }

        if (maxIndex != -1) {
            cout << "Student with highest degree in " << courses[i].name << " is "
                 << students[maxIndex].name << " with degree " << maxDegree << endl;
        } else {
            cout << "No student found for course: " << courses[i].name << endl;
        }
    }
}

void displayStudentsByLevel() {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }

    cout << "Students by academic level:\n";
    for (int level = 1; level <= 4; ++level) {
        cout << "\nLevel " << level << ":\n";
        bool found = false;

        for (int i = 0; i < studentCount; ++i) {
            if (students[i].level == level) {
                cout << "Name: " << students[i].name << ", ID: " << students[i].id
                     << ", GPA: " << students[i].gpa << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No students found for level " << level << ".\n";
        }
    }
}

void searchStudentByIDorName() {
    string searchTerm;
    cout << "Enter student ID or name to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == searchTerm || students[i].name == searchTerm) {
            cout << "Student found: " << students[i].name << ", ID: " << students[i].id
                 << ", Level: " << students[i].level << ", GPA: " << students[i].gpa << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

void searchCourseByCodeOrName() {
    string searchTerm;
    cout << "Enter course code or name to search: ";
    cin.ignore();
    getline(cin, searchTerm);

    bool found = false;
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].code == searchTerm || courses[i].name == searchTerm) {
            found = true;
            cout << "Course found: " << courses[i].name << ", Code: " << courses[i].code
                 << ", Credit Hours: " << courses[i].creditHours << endl;

            cout << "Students enrolled in this course:\n";
            for (int j = 0; j < studentCount; ++j) {
                for (int k = 0; k < 5; ++k) {
                    if (students[j].courses[k].courseCode == courses[i].code) {
                        cout << "Student: " << students[j].name << ", Degree: "
                             << students[j].courses[k].degree << endl;
                    }
                }
            }
            break;
        }
    }

    if (!found) {
        cout << "Course not found.\n";
    }
}

// searching and data show task 4 by ...


// assignment courses for student task 5 by ...
void assignCoursesToStudent() {
    string id;
    cout << "Enter student ID to assign courses: ";
    cin.ignore();
    getline(cin, id);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].id == id) {
            found = true;
            cout << "Assigning courses to " << students[i].name << " (ID: " << students[i].id << ")\n";

            int numCourses;
            cout << "Enter number of courses to assign (up to 5): ";
            cin >> numCourses;
            if (numCourses > 5) numCourses = 5;

            for (int j = 0; j < courseCount; ++j) {
                cout << j + 1 << ". " << courses[j].name << " (Code: " << courses[j].code << ")\n";
            }

            for (int j = 0; j < numCourses; ++j) {
                int courseIndex;
                cout << "Enter course number to assign (1 to " << courseCount << "): ";
                cin >> courseIndex;

                if (courseIndex >= 1 && courseIndex <= courseCount) {
                    students[i].courses[j].courseCode = courses[courseIndex - 1].code;
                    cout << "Enter grade for " << courses[courseIndex - 1].name << ": ";
                    cin >> students[i].courses[j].degree;
                }
                else {
                    cout << "Invalid course number.\n";
                }
            }
            cout << "Courses assigned successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Student not found.\n";
    }
}

// assignment courses for student task 5 by ...

int main() {

    printGinfo();  // call start


    // task 1 compared code function by ...

     int choice;
    do {
        cout << "    " << endl;
        cout << "==== Faculty Management System ====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Add Course" << endl;
        cout << "5. Update Course" << endl;
        cout << "6. Delete Course" << endl;
        cout << "7. Assign Course and Degree to Student" << endl;
        cout << "8. Display All Students" << endl;
        cout << "9. Display Student with Max Degree in Each Course" << endl;
        cout << "10. Display Students by Level" << endl;
        cout << "11. Search Student by ID or Name" << endl;
        cout << "12. Search Course by Name or Code" << endl;
        cout << "0. Exit" << endl;
        cout << "===================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "    " << endl;


        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                addCourse();
                break;
            case 5:
                updateCourse();
                break;
            case 6:
                deleteCourse();
                break;
            case 7:
                assignCoursesToStudent();
                break;
            case 8:
                displayAllStudents();
                break;
            case 9:
                displayMaxDegreeStudent();
                break;
            case 10:
                displayStudentsByLevel();
                break;
            case 11:
                searchStudentByIDorName();
                break;
            case 12:
                searchCourseByCodeOrName();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                break;
        }
    } while (choice != 0);

    // task 1 compared code function by ...



    return 0;
}

/// ennnnnnnnnnnnnnd
