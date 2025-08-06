#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // prevents overflow

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // not found
}

int main() {
    int arr[] = {2, 4, 6, 10, 15, 20, 28};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 15;

    int result = binarySearchIterative(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
