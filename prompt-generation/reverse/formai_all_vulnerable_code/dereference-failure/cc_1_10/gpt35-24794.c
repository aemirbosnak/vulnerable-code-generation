//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 1000

/* QuickSort implementation */
void quicksort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];
 
  // partition
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
  }
 
  // recursive
  if (left < j)
        quicksort(arr, left, j);
  if (i < right)
        quicksort(arr, i, right);
}

int main() {
    srand(time(NULL));

    // allocate an array of MAX_N integers
    int *arr = malloc(sizeof(int) * MAX_N);

    // fill the array with random numbers between 0 and 999
    for (int i = 0; i < MAX_N; i++) {
        arr[i] = rand() % 1000;
    }

    // sort the array with QuickSort
    quicksort(arr, 0, MAX_N - 1);

    // print the sorted array
    for (int i = 0; i < MAX_N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free the allocated memory
    free(arr);

    return 0;
}