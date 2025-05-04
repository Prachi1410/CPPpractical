#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struct to hold student records
struct Student {
    string name;
    int score;
};

// Manual sort: descending order (using bubble sort)
void sortByScore(vector<Student>& students) {
    for (size_t i = 0; i < students.size(); ++i) {
        for (size_t j = i + 1; j < students.size(); ++j) {
            if (students[i].score < students[j].score) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    vector<Student> students;
    string name;
    int score;

    cout << "Enter student name and score (end with 'done 0'):\n";
    while (cin >> name >> score) {
        if (name == "done") break;
        students.push_back({name, score});
    }

    // Sort manually without using <algorithm>
    sortByScore(students);

    // Display ranked students
    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << rank++ << ". " << it->name << " - " << it->score << endl;
    }

    return 0;
}

