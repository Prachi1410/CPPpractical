#include <iostream>
using namespace std;

class Employee {
public:
    string name;
    double basic, bonus;

    void AddData() {
        cout << "Name: ";
        cin >> name;
        cout << "Basic Salary: ";
        cin >> basic;
        cout << "Bonus (default 1200): ";
        cin >> bonus;
        if (bonus == 0) bonus = 1200;
    }

    double totalSalary() {
        return basic + bonus;
    }

    void display() {
        cout << name << " - Total Salary: " << totalSalary() << endl;
    }
};

double totalPayroll(Employee emp[], int n) {
    if (n == 0) return 0;
    return emp[n - 1].totalSalary() + totalPayroll(emp, n - 1);
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    Employee emp[100];
    for (int i = 0; i < n; i++){
     emp[i].AddData();}

    cout << "Employee Details:"<<endl;
    for (int i = 0; i < n; i++){
    emp[i].display();}

    cout << "Total Payroll: " << totalPayroll(emp, n) << endl;

    return 0;
    }
