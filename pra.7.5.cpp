#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Struct to hold student data
struct Student {
    string name;
    double marks;
    double tuitionFee;
};

// User-defined manipulator for currency formatting
ostream& currency(ostream& os) {
    return os << "₹"; // Change to '$', '€', etc. as needed
}

int main() {
    // Sample student data
    vector<Student> students = {
        {"prachi", 89.456, 50000.75},
        {"aarti", 92.1, 48000.5},
        {"dipen", 76.0, 51000.0},
        {"mikshu", 84.99, 47000.25}
    };

    // Header
    cout << left << setw(20) << "Name"
         << right << setw(10) << "Marks"
         << right << setw(20) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

    // Display each student's data with formatting
    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << right << fixed << setprecision(2) << setw(10) << s.marks
             << right << setw(10) << currency << fixed << setprecision(2) << s.tuitionFee
             << endl;
    }

    return 0;
}

