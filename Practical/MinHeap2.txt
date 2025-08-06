#include <stdio.h>
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}
void minHeapify(int arr[], int n, int i) {
 int smallest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < n && arr[left] < arr[smallest])
 smallest = left;
 if (right < n && arr[right] < arr[smallest])
 smallest = right;
 if (smallest != i) {
 swap(&arr[i], &arr[smallest]);
 minHeapify(arr, n, smallest);
 }
}
void heapSortMin(int arr[], int n) {
 for (int i = n / 2 - 1; i >= 0; i--)
 minHeapify(arr, n, i);
 for (int i = n - 1; i > 0; i--) {
 swap(&arr[0], &arr[i]);
 minHeapify(arr, i, 0);
 }
}
void printArray(int arr[], int n) {
 for (int i = 0; i < n; i++)
 printf("%d ", arr[i]);
 printf("\n");
}
int main() {
 int arr[] = {12, 11, 13, 5, 6, 7};
 int n = sizeof(arr) / sizeof(arr[0]);
 printf("Original array: ");
 printArray(arr, n);
 heapSortMin(arr, n);
 printf("Sorted array using Min Heap Sort: ");
 printArray(arr, n);
 return 0;
}
