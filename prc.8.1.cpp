#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int n;

    // Input sequence from user
    cout << "Enter numbers (end with -1): ";
    while (cin >> n && n != -1) {
        numbers.push_back(n);
    }

    // Display original sequence
    cout << "\nOriginal sequence:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // Manual reversal using iterators
    auto front = numbers.begin();
    auto back = numbers.end();
    --back; // Point to the last element

    while (front < back) {
        int temp = *front;
        *front = *back;
        *back = temp;
        ++front;
        --back;
    }

    // Display reversed sequence
    cout << "\nReversed sequence (manual iterator-based):\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}

