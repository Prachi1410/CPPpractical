#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// User-defined manipulator for alignment
void printAligned(const string &s, int width) {
    cout << setw(width) << left << s;
}

int main() {
    ifstream file("student_data.txt");
    if (!file) { cerr << "Error: Could not open file!" << endl;
     return 1; }


    // Header
    printAligned("Name", 20); printAligned("Marks", 10); printAligned("Grade", 10); cout << endl;

    string name;
    int marks; char grade;
    while (getline(file, name, ',') && file >> marks >> grade) {
        printAligned(name, 20); printAligned(to_string(marks), 10); printAligned(string(1, grade), 10); cout << endl;
        file.ignore();  // Ignore the comma
    }

    return 0;
}

