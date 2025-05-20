//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int array[], int length) {
  int max_value = array[0];
  int min_value = array[0];
  for (int i = 1; i < length; i++) {
    if (max_value < array[i]) {
      max_value = array[i];
    }
    if (min_value > array[i]) {
      min_value = array[i];
    }
  }
  
  int bucket_size = (max_value - min_value) / 5 + 1;
  int **buckets = malloc(bucket_size * sizeof(int *));

  for (int i = 0; i < bucket_size; i++) {
    buckets[i] = malloc(length * sizeof(int));
  }

  int *bucket_lengths = calloc(bucket_size, sizeof(int));

  for (int i = 0; i < length; i++) {
    int bucket_index = (array[i] - min_value) / 5;
    buckets[bucket_index][bucket_lengths[bucket_index]] = array[i];
    bucket_lengths[bucket_index]++;
  }

  int index = 0;

  for (int i = 0; i < bucket_size; i++) {
    int *bucket = buckets[i];
    int bucket_length = bucket_lengths[i];
    for (int j = 0; j < bucket_length; j++) {
      array[index] = bucket[j];
      index++;
    }
    free(bucket);
  }

  free(buckets);
  free(bucket_lengths);
}

int main() {
  int array[] = {22, 45, 12, 8, 10, 6, 72, 81, 33, 19};
  int length = sizeof(array) / sizeof(*array);
  
  printf("Unsorted Array : \n");
  for(int i=0;i<length;i++)
  printf("%d ", array[i]);
  
  bucket_sort(array, length);
  
  printf("\n\nSorted Array : \n");
  for(int i=0;i<length;i++)
  printf("%d ", array[i]);
  
  return 0;
}