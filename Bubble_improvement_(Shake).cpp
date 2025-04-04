#include <iostream>
using namespace std;

void shakeSort(int arr[], int n) {
    bool swapped = true;
    int start = 0, end = n - 1;

    while (swapped) {
        swapped = false;

        // Forward pass (left to right)
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // If no swaps, array is sorted

        swapped = false;
        end--; // Reduce end boundary

        // Backward pass (right to left)
        for (int i = end - 1; i >= start; i--) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        start++; // Increase start boundary
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    shakeSort(arr, n);
    printArray(arr, n);

    return 0;
}
