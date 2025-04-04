#include <iostream>
using namespace std;

void B_I_Sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  // Start from 1, as 0th element is already sorted
        int key = arr[i];
        int l = 0, r = i - 1;  // Corrected l to start from 0

        // Binary Search to find the insertion point
        while (l <= r) {
            int m = l + (r - l) / 2; // Prevents integer overflow

            if (arr[m] > key)
                r = m - 1;
            else
                l = m + 1;
        }

        // Shift elements to make space for key
        for (int j = i - 1; j >= l; j--)
            arr[j + 1] = arr[j];

        arr[l] = key;  // Place key at its correct position
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    B_I_Sort(arr, n);
    printArray(arr, n);

    return 0;
}
