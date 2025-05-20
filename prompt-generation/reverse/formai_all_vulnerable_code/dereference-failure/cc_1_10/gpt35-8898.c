//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n) {
  /* Identify the number of buckets needed */
  int max_value = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] > max_value) {
      max_value = array[i];
    }
  }
  max_value++;
  int* bucket = (int*) calloc(max_value, sizeof(int));
  for (int i = 0; i < n; i++) {
    bucket[array[i]]++;
  }

  /* Sort the items in each bucket */
  int current = 0;
  for (int i = 0; i < max_value; i++) {
    for (int j = 0; j < bucket[i]; j++) {
      array[current++] = i;
    }
  }

  /* Free memory */
  free(bucket);
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int array[n];
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i+1);
    scanf("%d", &array[i]);
  }

  printf("\nBefore sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }

  bucketSort(array, n);

  printf("\nAfter sorting: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}