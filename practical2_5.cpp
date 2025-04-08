#include <iostream>
#include <cmath>
#include<string>
using namespace std;

class Loan {
public:
    int loanID;
    string applicantName;
    float principal;
    float rate;
    int months;

    void setLoan(int id, string name, float p, float r, int m) {
        loanID = id;
        applicantName = name;
        principal = p;
        rate = r / (12 * 100);
        months = m;
    }

    float calculateEMI() {
        float emi = (principal * rate * pow(1 + rate, months)) / (pow(1 + rate, months) - 1);
        return emi;
    }

    void showDetails() {
        cout << "Loan ID: " << loanID <<endl;
        cout<< "Applicant: " << applicantName <<endl;
        cout<< "Loan Amount: " << principal <<endl;
         cout<< "EMI: " << calculateEMI() << endl;
    }
};

int main() {
    Loan loan;
    loan.setLoan(101, "parmar prachi", 500000, 8.5, 60);
    loan.showDetails();
    return 0;
}
