#include <iostream>

#include <iostream>

void BubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // Outer loop for passes
        for (int j = n - 1; j >= i; j--) { // Inner loop for adjacent comparisons
            if (arr[j] > arr[j + 1]) {
                // Swap if elements are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    BubbleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

