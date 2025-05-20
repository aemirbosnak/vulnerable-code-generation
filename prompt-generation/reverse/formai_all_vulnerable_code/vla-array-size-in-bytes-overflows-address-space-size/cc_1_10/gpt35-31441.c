//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int arr[], int n) {
  int i, j, temp;
  
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  int j, temp;
  
  for (j = low; j <= high-1; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  
  temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;
  
  return (i+1);
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
  }
}

int main() {
  int n, i;
  
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  
  int arr[n];
  
  srand(time(NULL));
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100;
  }
  
  clock_t start, end;
  
  start = clock();
  bubble_sort(arr, n);
  end = clock();
  
  printf("Time taken by Bubble Sort: %lf sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);
  
  start = clock();
  quick_sort(arr, 0, n-1);
  end = clock();
  
  printf("Time taken by Quick Sort: %lf sec\n", ((double)(end - start)) / CLOCKS_PER_SEC);
  
  return 0;
}