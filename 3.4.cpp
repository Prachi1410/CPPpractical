 #include <iostream>
using namespace std;

template <typename T>
void print(const T* arr, int size, int i = 0) {
    if (i == size) return;
    cout << arr[i] << " ";
    print(arr, size, i + 1);
}

template <typename T>
T findMax(const T* arr, int size, int i = 0, T maxVal = T()) {
    if (i == 0) maxVal = arr[0];
    if (i == size) return maxVal;
    return findMax(arr, size, i + 1, arr[i] > maxVal ? arr[i] : maxVal);
}

template <typename T>
void reverse(T* arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverse(arr, start + 1, end - 1);
}

int main() {
    int a[] = {3, 1, 4, 1, 5};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Original: ";
    print(a, n);

    cout << "\nMax: " << findMax(a, n);

    reverse(a, 0, n - 1);
    cout << "\nReversed: ";
    print(a, n);

    return 0;
    }
