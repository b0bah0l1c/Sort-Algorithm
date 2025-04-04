#include <iostream>

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left, j = right + 1;

    while(true) {
        while(++i <= right && arr[i] < pivot);
        while(--j >= left && arr[j] > pivot);
        if(i >= j) break;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[left];
    arr[left] = arr[j];

    return j;
}

void quickSort(int arr[], int n, int left, int right) {
    if(left < right) {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1):
        quickSort(arr, p + 1, right);
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
