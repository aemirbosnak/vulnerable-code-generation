//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int min_element(int arr[], int n) {
 int min = arr[0];
 for (int i = 1; i < n; i++) {
 if (arr[i] < min) {
 min = arr[i];
 }
 }
 return min;
}
int partition(int arr[], int low, int high) {
 int pivot = arr[high];
 int i = (low - 1);
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] <= pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 int temp1 = arr[i + 1];
 arr[i + 1] = arr[high];
 arr[high] = temp1;
 return (i + 1);
}
void quick_sort(int arr[], int low, int high) {
 if (low < high) {
 int pi = partition(arr, low, high);
 quick_sort(arr, low, pi - 1);
 quick_sort(arr, pi + 1, high);
 }
}
int main() {
 int arr[MAX];
 int n;
 printf("Enter the number of elements: ");
 scanf("%d", &n);
 printf("Enter the elements: ");
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
 }
 quick_sort(arr, 0, n - 1);
 printf("\nSorted array: ");
 for (int i = 0; i < n; i++) {
 printf("%d ", arr[i]);
 }
 printf("\nMinimum element is: %d\n", min_element(arr, n));
 return 0;
}