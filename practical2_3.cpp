#include <iostream>
#include <string>
using namespace std;

class BankAccount {

    string name;
    int accountNumber;
    float balance;

public:
    BankAccount() {
        name = "dipen";
        accountNumber = 0;
        balance = 0;
    }


    BankAccount(string n, int accNo, float bal) {
        name = n;
        accountNumber = accNo;
        balance = bal;
    }

    // Deposit amount
    void deposit(float amount) {
        balance += amount;
    }


    void withdraw(float amount) {
        if (amount > balance){
            cout << "Insufficient balance:" << endl;
            }
        else{
            balance -= amount;
            }
    }


    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {

    BankAccount acc1;
    acc1.display();

    BankAccount acc2("prachi", 1001, 5000);
    acc2.deposit(1000);
    acc2.withdraw(2000);
    acc2.display();

    return 0;
}
