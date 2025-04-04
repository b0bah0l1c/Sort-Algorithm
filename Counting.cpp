#include <iostream>
#include <algorithm> // For std::max and std::min

void countingSort(int arr[], int n) {
    // Tìm giá trị lớn nhất và nhỏ nhất trong mảng
    int maxElement = *std::max_element(arr, arr + n);
    int minElement = *std::min_element(arr, arr + n);
    int range = maxElement - minElement + 1;

    // Tạo mảng đếm (count array)
    int* count = new int[range](); // Khởi tạo mảng đếm với giá trị 0

    // Lưu tần số xuất hiện của từng phần tử
    for (int i = 0; i < n; i++) {
        count[arr[i] - minElement]++;
    }

    // Biến đổi mảng đếm thành mảng tích lũy
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Tạo mảng tạm để lưu các phần tử đã sắp xếp
    int* output = new int[n];

    // Sắp xếp phần tử vào mảng tạm dựa vào mảng đếm
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    // Sao chép mảng tạm trở lại mảng ban đầu
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] count;
    delete[] output;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    countingSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
