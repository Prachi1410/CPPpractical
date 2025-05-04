#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_WORDS = 100;
const int MAX_WORD_LENGTH = 50;

int main() {
    char input[1000];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int freq[MAX_WORDS] = {0};
    int wordCount = 0;

    cout << "Enter a sentence or paragraph:\n";
    cin.getline(input, 1000);

    int i = 0;
    while (input[i] != '\0') {
        // Extract one word at a time
        char word[MAX_WORD_LENGTH] = {0};
        int j = 0;

        while (input[i] != '\0' && !isalnum(input[i])) i++;  // Skip non-alphanumeric

        while (input[i] != '\0' && isalnum(input[i]) && j < MAX_WORD_LENGTH - 1) {
            word[j++] = tolower(input[i++]);
        }
        word[j] = '\0';

        if (strlen(word) == 0) continue;

        // Check if word exists in list
        bool found = false;
        for (int k = 0; k < wordCount; ++k) {
            if (strcmp(words[k], word) == 0) {
                freq[k]++;
                found = true;
                break;
            }
        }

        // If not found, add to array
        if (!found && wordCount < MAX_WORDS) {
            strcpy(words[wordCount], word);
            freq[wordCount] = 1;
            wordCount++;
        }
    }

    // Print frequency table
    cout << "\nWord Frequency:\n";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << ": " << freq[i] << "\n";
    }

    return 0;
}


