#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper function to get the digit at a specific position
int getDigit(int num, int pos) {
    int divisor = 1;
    for (int i = 0; i < pos; i++) {
        divisor *= 10;
    }
    return (num / divisor) % 10;
}

// Helper function to get the number of digits in the maximum number
int getMaxDigits(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int maxNum = *max_element(arr.begin(), arr.end());
    int digits = 0;
    while (maxNum != 0) {
        maxNum /= 10;
        digits++;
    }
    return digits;
}

// MSD Radix Sort recursive function
void MSD_radixSort(vector<int>& arr, int left, int right, int digitPos) {
    if (left >= right || digitPos < 0) return;

    // Create 10 buckets (0-9)
    vector<vector<int>> buckets(10);

    // Distribute elements into buckets based on current digit
    for (int i = left; i <= right; i++) {
        int digit = getDigit(arr[i], digitPos);
        buckets[digit].push_back(arr[i]);
    }

    // Collect elements from buckets back into original array
    int index = left;
    for (auto& bucket : buckets) {
        for (int num : bucket) {
            arr[index++] = num;
        }
    }

    // Recursively sort each bucket with next digit position
    int start = left;
    for (auto& bucket : buckets) {
        if (!bucket.empty()) {
            int end = start + bucket.size() - 1;
            MSD_radixSort(arr, start, end, digitPos - 1);
            start = end + 1;
        }
    }
}

// Wrapper function for MSD Radix Sort
void MSD_radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxDigits = getMaxDigits(arr);
    MSD_radixSort(arr, 0, arr.size() - 1, maxDigits - 1);
}

// Main function to test the implementation
int main() {
    vector<int> arr = {329, 457, 657, 839, 436, 720, 355, 1000, 42, 7};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    MSD_radixSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}