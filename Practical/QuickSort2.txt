#include <iostream>
using namespace std;

// Function to partition the array into two sub-arrays based on the pivot
int partition(int arr[], int low, int high) {
    // Choose the pivot element (using the last element)
    int pivot = arr[high];
    int i = (low - 1);  // Index of the smaller element

    // Rearrange the array: all elements smaller than pivot are on the left
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element with the element at index i + 1 to place it in the correct position
    swap(arr[i + 1], arr[high]);
    return (i + 1);  // Return the index of the pivot element
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the two sub-arrays
        quickSort(arr, low, pi - 1);  // Left of pivot
        quickSort(arr, pi + 1, high); // Right of pivot
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
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Call Quick Sort

    cout << "Sorted array: ";
    printArray(arr, n);  // Print the sorted array

    return 0;
}
