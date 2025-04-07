#include <iostream>

void sift(int arr[], int left, int right) {
    int i = left;
    int j = 2 * i + 1;
    int x = arr[i];

    while(j <= right) {
        while(j < right && arr[j] < arr[j + 1]) j++;
        if(x >= a[i]) break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }

    arr[i] = x;
}

void heapSort(int arr[], int n) {
    for (int left = n / 2 - 1; left >= 0; left--) {
        heapify(arr, left, n - 1);
    }

    // Extract elements from heap one by one
    for (int right = n - 1; right > 0; i--) {
        int temp = arr[0];
        arr[right] = arr[0];
        arr[0] = temp;

        sift(arr, 0, right - 1);
    }
}

int main() {
    int arr[] = {2, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    heapSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
