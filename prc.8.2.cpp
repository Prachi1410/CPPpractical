#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string word;
    map<string, int> freq;

    cout << "Enter words (type END to finish):" << endl;

    while (cin >> word) {
        if (word == "END") break;
        ++freq[word]; // map keeps words sorted automatically
    }

    cout << "\nWord Frequency:\n";
    for (auto it = freq.begin(); it != freq.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}

