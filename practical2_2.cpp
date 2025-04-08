#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int roll;
    string name;
    float marks1, marks2, marks3;

public:

    Student() {
        roll = 2460;
        name = "niyati";
        marks1 = marks2 = marks3 = 60.0;
    }


    Student(int r, string n, float m1, float m2, float m3) {
        roll = r;
        name = n;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }


    float getAverage() {
        return (marks1 + marks2 + marks3) / 3;
    }


    void display() {
        cout << "Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Average: " << getAverage() << endl;
    }
};

int main() {

    Student s1;
    cout << "Student 1 ():" << endl;
    s1.display();

    cout << endl;

    Student s2(101, "hetal", 85, 90, 88);
    cout << "Student 2 ():" << endl;
    s2.display();

    return 0;
}
