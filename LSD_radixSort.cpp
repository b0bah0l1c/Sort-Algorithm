#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm số lớn nhất trong mảng
int findMax(const vector<int>& arr) {
    int maxNum = arr[0];
    for(int num : arr) {
        if(num > maxNum) {
            maxNum = num;
        }
    }
    return maxNum;
}

// Hàm lấy chữ số thứ k (từ phải sang, bắt đầu từ 0)
int digit(int num, int k) {
    while (k--) {
        num /= 10;
        if (num == 0) return 0;
    }
    return num % 10;
}

// Hàm đếm số chữ số của một số
int cntDigit(int num) {
    if (num == 0) return 1;
    int digits = 0;
    while (num != 0) {
        num /= 10;
        digits++;
    }
    return digits;
}

// Hàm sắp xếp theo chữ số thứ k
void sort(vector<int>& arr, int k) {
    vector<int> output(arr.size());
    int count[10] = {0};
    
    for(int num : arr) count[digit(num, k)]++;
    for(int i = 1; i < 10; i++) count[i] += count[i - 1];
    for(int i = arr.size() - 1; i >= 0; i--) {
        int j = digit(arr[i], k);
        output[--count[j]] = arr[i];
    }
    arr = output;
}

// Hàm sắp xếp Radix Sort
void LSD_radixSort(vector<int>& arr) {
    if(arr.empty()) return;
    int d = cntDigit(findMax(arr));
    for(int k = 0; k < d; k++) sort(arr, k);
}

// Hàm main để kiểm tra
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    cout << "Mang truoc khi sap xep: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    LSD_radixSort(arr);
    
    cout << "Mang sau khi sap xep: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}