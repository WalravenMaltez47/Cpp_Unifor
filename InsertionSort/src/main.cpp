#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& arr) {
    int n = arr.size();

    for(int j = 0; j < n; j++) {
        int key = arr[j];
        int i = j - 1;

        while(i >= 0 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }

        arr[i + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {4,3,2,1};
    
    InsertionSort(arr);
    // 4, 4, 2, 1
    // 3, 4, 2, 1

    // 3, 4, 4, 1
    // 3, 3, 4, 1
    // 2, 3, 4, 1

    // 2, 3, 4, 4
    // 2, 3, 3, 4
    // 2, 2, 3, 4
   //* 1, 2, 3, 4 *

    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}