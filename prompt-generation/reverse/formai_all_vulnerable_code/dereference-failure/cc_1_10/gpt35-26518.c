//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quicksort(int arr[], int left, int right) {
  int i, j, pivot;

  if (left < right) {
    pivot = left;
    i = left;
    j = right;

    while (i < j) {
      while (arr[i] <= arr[pivot] && i <= right)
        i++;

      while (arr[j] > arr[pivot])
        j--;

      if (i < j) {
        swap(&arr[i], &arr[j]);
      }
    }

    swap(&arr[pivot], &arr[j]);
    quicksort(arr, left, j - 1);
    quicksort(arr, j + 1, right);
  }
}

int main() {
  int arr[] = {5, 4, 6, 8, 1, 3, 2, 7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i;
  
  printf("Before sorting: ");
  
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  quicksort(arr, 0, n - 1);
  
  printf("\nAfter sorting: ");
  
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}