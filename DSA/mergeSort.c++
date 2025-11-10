#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return; 
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the two halves
    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    while (j <= right) {
        temp.push_back(arr[j++]);
    }
    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
}

void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);
        mergeSort(arr, left, right);
    }
}

void printArray(vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {38, 27, 43, 3, 9, 82, 10};
    cout << "Unsorted array : " << endl;
    printArray(data);
    mergeSortRecursive(data, 0, data.size() - 1);
    cout << "Sorted array : " << endl;
    printArray(data);
    return 0;
}