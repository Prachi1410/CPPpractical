#include <iostream>
#include <cstring>
#include <stdexcept>  // Include this for throwing exceptions

using namespace std;

const int MAX_TRANSACTIONS = 100;

class BankAccount {
private:
    char ownerName[50];
    double balance;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

    // Log function call when an error occurs
    void logError(const string& functionName, const string& errorMessage) {
        cout << "false Error in function [" << functionName << "]: " << errorMessage << endl;
        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = "ERROR in " + functionName + ": " + errorMessage;
        }
    }

public:
    BankAccount(const char* name, double initialBalance = 0.0) {
        strncpy(ownerName, name, sizeof(ownerName));
        ownerName[sizeof(ownerName) - 1] = '\0';
        balance = (initialBalance >= 0.0) ? initialBalance : 0.0;
        transactionCount = 0;
        if (initialBalance > 0.0)
            transactionHistory[transactionCount++] = "Account opened with balance: " + to_string(initialBalance);
    }

    void deposit(double amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Attempted to deposit non-positive amount.");
            }
            balance += amount;
            if (transactionCount < MAX_TRANSACTIONS) {
                transactionHistory[transactionCount++] = "Deposited: " + to_string(amount);
            }
        } catch (const invalid_argument& e) {
            logError("deposit", e.what());
        }
    }

    void withdraw(double amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Attempted to withdraw non-positive amount.");
            }
            if (amount > balance) {
                throw runtime_error("Insufficient funds.");
            }
            balance -= amount;
            if (transactionCount < MAX_TRANSACTIONS) {
                transactionHistory[transactionCount++] = "Withdrew: " + to_string(amount);
            }
        } catch (const invalid_argument& e) {
            logError("withdraw", e.what());
        } catch (const runtime_error& e) {
            logError("withdraw", e.what());
        }
    }

    void printAccountSummary() const {
        cout << "\n--- Account Summary ---\n";
        cout << "Owner: " << ownerName << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    void printTransactionHistory() const {
        cout << "\n--- Transaction History ---\n";
        if (transactionCount == 0) {
            cout << "No transactions recorded.\n";
        } else {
            for (int i = 0; i < transactionCount; ++i) {
                cout << i + 1 << ". " << transactionHistory[i] << endl;
            }
        }
    }
};

int main() {
    BankAccount account("John Doe", 500.0);

    account.deposit(250.0);
    account.withdraw(100.0);
    account.withdraw(800.0);    // Error: insufficient funds
    account.deposit(-50.0);     // Error: invalid deposit
    account.withdraw(0);        // Error: invalid withdrawal

    account.printAccountSummary();
    account.printTransactionHistory();

    return 0;
}

