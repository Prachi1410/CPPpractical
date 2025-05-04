#include <iostream>
#include <vector>

using namespace std;

// Simple bubble sort implementation
void manualSort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

// Function to remove duplicates from sorted vector
vector<int> removeDuplicates(const vector<int>& sortedVec) {
    vector<int> uniqueVec;
    for (size_t i = 0; i < sortedVec.size(); ++i) {
        if (i == 0 || sortedVec[i] != sortedVec[i - 1]) {
            uniqueVec.push_back(sortedVec[i]);
        }
    }
    return uniqueVec;
}

int main() {
    vector<int> transactionIDs;
    int id;

    cout << "Enter transaction IDs (end with -1):\n";
    while (cin >> id && id != -1) {
        transactionIDs.push_back(id);
    }

    // Manually sort the vector
    manualSort(transactionIDs);

    // Remove duplicates manually
    vector<int> uniqueIDs = removeDuplicates(transactionIDs);

    // Display result
    cout << "\nUnique Transaction IDs (Sorted):\n";
    for (size_t i = 0; i < uniqueIDs.size(); ++i) {
        cout << uniqueIDs[i] << " ";
    }
    cout << endl;

    return 0;
}

