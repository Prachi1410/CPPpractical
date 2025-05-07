#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a new sorted array
int* mergeSortedArrays(int* a, int n, int* b, int m, int& size) {
    size = n + m;
    int* result = new int[size];

    int i = 0, j = 0, k = 0;

    // Merge elements from both arrays in sorted order
    while (i < n && j < m) {
        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    // Copy remaining elements from array a (if any)
    while (i < n)
        result[k++] = a[i++];

    // Copy remaining elements from array b (if any)
    while (j < m)
        result[k++] = b[j++];

    return result;
}

int main() {
    int n, m;

    // Input for first array
    cout << "Enter size of first array: ";
    cin >> n;
    int* a = new int[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Input for second array
    cout << "Enter size of second array: ";
    cin >> m;
    int* b = new int[m];
    cout << "Enter " << m << " sorted elements: ";
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // Merge process
    int mergedSize;
    int* merged = mergeSortedArrays(a, n, b, m, mergedSize);

    // Display result
    cout << "\nMerged Sorted Array: ";
    for (int i = 0; i < mergedSize; i++)
        cout << merged[i] << " ";
    cout << endl;

    // Free dynamically allocated memory
    delete[] a;
    delete[] b;
    delete[] merged;

    return 0;
}

