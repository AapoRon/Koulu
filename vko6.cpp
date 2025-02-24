
#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



// Define Student class

class Student {

public:

    string name;

    int age;



    Student(string n, int a) : name(n), age(a) {}



    void printStudentInfo() const {

        cout << "Name: " << name << ", Age: " << age << endl;

    }

};



// Function to print all students

void printAllStudents(const vector<Student>& studentList) {

    for (const auto& student : studentList) {

        student.printStudentInfo();

    }

}



int main() {

    int selection = 0;

    vector<Student> studentList;



    do {

        cout << endl;

        cout << "Select" << endl;

        cout << "Add students = 0" << endl;

        cout << "Print all students = 1" << endl;

        cout << "Sort and print students according to Name = 2" << endl;

        cout << "Sort and print students according to Age = 3" << endl;

        cout << "Find and print student = 4" << endl;

        cout << "Exit = 5" << endl;

        cin >> selection;



        switch (selection) {

        case 0: {

            string name;

            int age;

            cout << "Enter student name: ";

            cin >> name;

            cout << "Enter student age: ";

            cin >> age;

            studentList.emplace_back(name, age);

            break;

        }



        case 1:

            if (studentList.empty()) {

                cout << "No students in the list." << endl;

            } else {

                printAllStudents(studentList);

            }

            break;



        case 2:

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {

                return a.name < b.name;

            });

            cout << "Students sorted by name:\n";

            printAllStudents(studentList);

            break;



        case 3:

            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {

                return a.age < b.age;

            });

            cout << "Students sorted by age:\n";

            printAllStudents(studentList);

            break;



        case 4: {

            string searchName;

            cout << "Enter student name to find: ";

            cin >> searchName;

            auto it = find_if(studentList.begin(), studentList.end(), [&](const Student& s) {

                return s.name == searchName;

            });



            if (it != studentList.end()) {

                it->printStudentInfo();

            } else {

                cout << "Student not found." << endl;

            }

            break;

        }



        case 5:

            cout << "Exiting..." << endl;

            break;



        default:

            cout << "Wrong selection, try again." << endl;

            break;

        }

    } while (selection != 5);



    return 0;

}
