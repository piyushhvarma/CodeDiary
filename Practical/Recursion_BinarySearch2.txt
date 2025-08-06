#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high)
        return -1; // base case: not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target);
    else
        return binarySearchRecursive(arr, low, mid - 1, target);
}

int main() {
    int arr[] = {2, 4, 6, 10, 15, 20, 28};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    int result = binarySearchRecursive(arr, 0, size - 1, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
