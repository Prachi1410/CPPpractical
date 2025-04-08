#include <iostream>
#include <string>
using namespace std;

// Recursive function to print strings in reverse
void printReverse(string arr[], int n) {
    if (n == 0) ;
    cout << arr[n - 1] << endl;
    printReverse(arr, n - 1);
    return ;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    string arr[100];
    cin.ignore(); // clear newline from buffer

    cout << "Enter " << n << " strings:"<<endl;
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    cout << "Strings in reverse order (using recursion):"<<endl;
    printReverse(arr, n);

    return 0;
}
