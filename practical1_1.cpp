include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNumber, double initialBalance) {
        accountHolder = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << " Insufficient funds:" << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal amount:" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
    }

    void checkBalance() {
        cout << "Account Balance: " << balance << endl;
    }

    void displayAccountDetails()  {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        checkBalance();
    }
};

int main() {
    BankAccount account1("prachi", 1001, 500.0);

    account1.displayAccountDetails();
    account1.deposit(150.0);
    account1.withdraw(200.0);
    account1.withdraw(600.0);
    account1.checkBalance();

    return 0;
}
