#include <stdio.h>
#include <limits.h>

    typedef struct {
        int max;
        int min;
}MinMax;

MinMax findMinMax(int arr[], int low, int high) {
 MinMax result, leftResult, rightResult;

 if (low == high) {
    result.max = arr[low];
    result.min = arr[low];
    return result;
 }

 if (high == low + 1) {
    if (arr[low] > arr[high]) {
        result.max = arr[low];
        result.min = arr[high];
    } else {
        result.max = arr[high];
        result.min = arr[low];
    }
 return result;
 }

 int mid = (low + high) / 2;

 leftResult = findMinMax(arr, low, mid);
 rightResult = findMinMax(arr, mid + 1, high);

 result.max = (leftResult.max > rightResult.max) ? leftResult.max : rightResult.max;
 result.min = (leftResult.min < rightResult.min) ? leftResult.min : rightResult.min;
 return result;
}

void printMinMax(MinMax result) {
 printf("Maximum value: %d\n", result.max);
 printf("Minimum value: %d\n", result.min);
}

int main() {
 int arr[] = {12, 3, 5, 7, 19, 1, 6};
 int n = sizeof(arr) / sizeof(arr[0]);
 MinMax result = findMinMax(arr, 0, n - 1);
 printMinMax(result);
 return 0;
}
