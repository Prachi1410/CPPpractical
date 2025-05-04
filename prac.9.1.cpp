#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to check if a string represents a valid number
bool isValidNumber(const string& str) {
    bool decimalSeen = false;
    int start = 0;

    if (str.empty()) return false;

    if (str[0] == '-' || str[0] == '+') start = 1;

    for (int i = start; i < str.length(); ++i) {
        if (str[i] == '.') {
            if (decimalSeen) return false;
            decimalSeen = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

// Function to read a valid double input
double getValidDouble(const string& prompt) {
    string input;
    double value;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (isValidNumber(input)) {
            value = stod(input);
            return value;
        } else {
            cout << " Invalid input. Please enter a numeric value.\n";
        }
    }
}

int main() {
    cout << "=== Loan-to-Income Ratio Calculator ===\n";

    double loanAmount = getValidDouble("Enter loan amount: ");

    double annualIncome;
    while (true) {
        annualIncome = getValidDouble("Enter annual income: ");
        if (annualIncome == 0.0) {
            cout << "false Annual income cannot be zero. Please enter a non-zero value.\n";
        } else {
            break;
        }
    }

    double ratio = loanAmount / annualIncome;
    cout << "\ntrue Loan-to-Income Ratio: " << ratio << endl;

    // Optional interpretation
    if (ratio > 0.5)
        cout << "  High ratio. Consider improving your income or requesting a smaller loan.\n";
    else
        cout << " Ratio looks acceptable.\n";

    return 0;
}

