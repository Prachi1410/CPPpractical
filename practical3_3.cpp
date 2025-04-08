#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    string accNo;
    string name;
    double balance;

    void create(string no, string n, double bal) {
        accNo = no;
        name = n;
        balance = bal;
    }

    void display() {
        cout << "Account No: "<< accNo <<endl;
        cout<< "Name: " << name << endl;
        cout<<" Balance: " << balance << endl;
    }
};

// Recursive function to display all accounts
void displayAccounts(Account acc[], int n) {
    if (n == 0) {
    displayAccounts(acc, n - 1);
    acc[n - 1].display();
    return ;}
}

// Recursive function to count accounts by name
int countByName(Account acc[], int n, string targetName) {
    if (n == 0){
        return 0; }
    if (acc[n - 1].name == targetName){
        countByName(acc, n - 1, targetName);
        return 1;
        }
    else{
         countByName(acc, n - 1, targetName);
         return 0 ;}
}

int main() {
    Account accounts[100];
    int total = 0;


    accounts[total++].create("p101", "Alice", 1500.50);
    accounts[total++].create("p202", "Bob", 3200.00);
    accounts[total++].create("p303", "Alice", 500.25);


    displayAccounts(accounts, total);

    string Name;
    cout << "Enter name to count: "<<endl;
    cin >> Name;

    int count = countByName(accounts, total, Name);
    cout << "Accounts with name " << Name << "': " << count << endl;

    return 0;
    }
