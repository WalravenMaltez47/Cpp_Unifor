#include <iostream>
#include <vector>

// Function to merge two subarrays arr[start..mid] and arr[mid+1..end]
void merge(std::vector<int>& arr, int start, int mid, int end) {
    int start2 = mid + 1;
    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2]) {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {
        // If element 1 is in right place
        if (arr[start] <= arr[start2]) {
            start++;
        } else {
            int value = arr[start2];
            int index = start2;

            // Shift all elements between element 1
            // and element 2 in right direction
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}

// Recursive merge sort function
void mergeSort(std::vector<int>& arr, int start, int end) {
    if (start < end) {
        // Find the middle point
        int mid = start + (end - start) / 2;

        // Sort first and second halves
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the sorted halves
        merge(arr, start, mid, end);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();

    std::cout << "Array before sorting: \n";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    mergeSort(arr, 0, arr_size - 1);

    std::cout << "Array after sorting: \n";
    for (int i = 0; i < arr_size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}