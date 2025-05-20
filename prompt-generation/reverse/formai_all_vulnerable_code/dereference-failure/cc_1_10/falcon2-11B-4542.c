//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
  return *(int*)a - *(int*)b;
}

void swap(void * a, void * b) {
  int * x = a;
  int * y = b;
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bucketSort(int * arr, int n) {
  int max_val = 0;
  int max_index = 0;
  int bucket_size = 100;
  int * buckets = (int*)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    max_val = (arr[i] > max_val)? arr[i] : max_val;
    max_index = i;
  }
  for (int i = 0; i < n; i++) {
    buckets[i] = 0;
  }
  for (int i = 0; i < max_val; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] >= i) {
        buckets[arr[j] - i]++;
      }
    }
  }
  for (int i = 0; i < max_val; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (buckets[i] > 0) {
        buckets[i]--;
        count++;
        arr[j] = i;
        swap(&arr[j], &arr[count]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {12, 3, 8, 1, 2, 8, 5, 1, 9, 4, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  bucketSort(arr, n);
  return 0;
}