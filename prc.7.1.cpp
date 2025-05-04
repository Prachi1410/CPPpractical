#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A'); // Convert to lowercase manually
        }
    }
    return str;
}

int main() {
    char input[1000];
    char* words[100];
    int wordCount = 0;

    cout << "Enter a paragraph:\n";
    cin.getline(input, 1000);

    // Tokenize input into words using strtok
    char* token = strtok(input, " ,.!?\n\r\t");
    while (token) {
        // Dynamically allocate memory for each word
        words[wordCount] = new char[strlen(token) + 1];
        strcpy(words[wordCount], token);

        // Convert word to lowercase for case-insensitive comparison
        toLowerCase(words[wordCount]);

        wordCount++;
        token = strtok(nullptr, " ,.!?\n\r\t");
    }

    // Count word frequencies
    for (int i = 0; i < wordCount; i++) {
        if (words[i] == nullptr) continue;

        int count = 1;
        for (int j = i + 1; j < wordCount; j++) {
            if (words[i] && strcmp(words[i], words[j]) == 0) {
                count++;
                delete[] words[j];  // Free memory for duplicate words
                words[j] = nullptr;  // Mark duplicate as null
            }
        }

        cout << words[i] << ": " << count << endl;
        delete[] words[i];  // Free memory for the current word after counting
    }

    return 0;
}










