#include <iostream>
using namespace std;

struct abc {
    int a, b;
    abc *n;

    void insertdata() {
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        n = NULL;
    }

    void displaydata() {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
    }
};

int main() {
    abc *B = NULL, *t;
    int ch;

menu:
    cout << "\n1. Insert\n2. Display\n3. Exit\nEnter choice: ";
    cin >> ch;

    switch (ch) {
        case 1: {
            abc *p = new abc;
            p->insertdata();

            if (B == NULL) {
                B = p;
            } else {
                t = B;
                while (t->n != NULL) {
                    t = t->n;
                }
                t->n = p;
            }
            break;
        }

        case 2: {
            if (B == NULL) {
                cout << "No data\n";
            } else {
                t = B;
                while (t != NULL) {
                    t->displaydata();
                    t = t->n;
                }
            }
            break;
        }

        case 3:
            return 0;

        default:
            cout << "Invalid choice\n";
    }

    goto menu;
    return 0;
}
