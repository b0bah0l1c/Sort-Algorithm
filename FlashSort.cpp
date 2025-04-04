#include <iostream>
#include <vector>

using namespace std;

void findMinMax(const vector<int>& arr, int& minVal, int& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
}

void flashSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    // Step 1: Find min and max values
    int minVal, maxVal;
    findMinMax(arr, minVal, maxVal);

    if (minVal == maxVal) return;  // Already sorted if all elements are the same

    // Step 2: Create classification table (bucket counts)
    int m = int(0.45 * n);  // Number of classification buckets
    vector<int> L(m, 0);    // Bucket counts

    // Compute the index function constant
    double c = (m - 1.0) / (maxVal - minVal);

    // Count elements per bucket
    for (int i = 0; i < n; i++) {
        int k = int(c * (arr[i] - minVal));
        L[k]++;
    }

    // Convert counts to indices
    for (int i = 1; i < m; i++) {
        L[i] += L[i - 1];
    }

    // Step 3: Flash Sort - Permutation
    int count = 0;
    int i = 0;
    while (count < n) {
        int k = int(c * (arr[i] - minVal));
        while (i >= L[k]) {
            i++;
            k = int(c * (arr[i] - minVal));
        }
        int value = arr[i];
        while (i != L[k]) {
            k = int(c * (value - minVal));
            int temp = arr[L[k] - 1];
            arr[L[k] - 1] = value;
            value = temp;
            L[k]--;
            count++;
        }
    }

    // Step 4: Final Insertion Sort for small partitions
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {23, 12, 1, 8, 34, 54, 2, 3, 78, 55};
    
    cout << "Original array:\n";
    printArray(arr);

    flashSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}
