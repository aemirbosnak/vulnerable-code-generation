//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_BUCKET 10000

int main() {
  int i, j;
  int *arr;
  int *bucket;
  int n, max, min;
  int start, end;
  double start_time, end_time;

  srand(time(NULL));

  printf("Enter the number of elements: ");
  scanf("%d", &n);

  arr = (int *) malloc(n * sizeof(int));
  bucket = (int *) malloc(MAX_BUCKET * sizeof(int));

  printf("Enter the elements: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  max = arr[0];
  min = arr[0];

  for (i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  start_time = clock();

  for (i = 0; i < n; i++) {
    j = arr[i] * MAX_BUCKET / (max - min);
    bucket[j]++;
  }

  for (i = 0; i < MAX_BUCKET; i++) {
    bucket[i] += bucket[i - 1];
  }

  for (i = n - 1; i >= 0; i--) {
    j = arr[i] * MAX_BUCKET / (max - min);
    start = bucket[j] - 1;
    end = start - 1;
    while (bucket[end] < start) {
      end--;
    }
    arr[i] = bucket[start];
    bucket[start]--;
    bucket[end]++;
  }

  end_time = clock();

  printf("Sorted array: ");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("Time taken: %lf seconds\n", (double) (end_time - start_time) / CLOCKS_PER_SEC);

  free(arr);
  free(bucket);

  return 0;
}