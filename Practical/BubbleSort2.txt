#include <iostream>
using namespace std;

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;

        // Last i elements are already in place, so we reduce the range each time
        for (int j = 0; j < n-i-1; j++) {
            // If the element is greater than the next element, swap them
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // If no two elements were swapped, the array is sorted
        if (!swapped)
            break;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  // Sample array
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);  // Call Bubble Sort

    cout << "Sorted array: ";
    printArray(arr, n);  // Print the sorted array

    return 0;
}
