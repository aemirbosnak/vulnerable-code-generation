//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to insert a value into a bucket
void bucket_insert(int *bucket, int value, int bucket_size) {
  int i;
  for (i = 0; i < bucket_size; i++) {
    if (bucket[i] == -1) {
      bucket[i] = value;
      return;
    }
  }
  printf("Bucket overflow!\n");
}

// Function to sort a bucket
void bucket_sort(int *bucket, int bucket_size) {
  int i, j;
  for (i = 0; i < bucket_size; i++) {
    for (j = i + 1; j < bucket_size; j++) {
      if (bucket[i] > bucket[j]) {
        int tmp = bucket[i];
        bucket[i] = bucket[j];
        bucket[j] = tmp;
      }
    }
  }
}

// Function to print a bucket
void bucket_print(int *bucket, int bucket_size) {
  int i;
  for (i = 0; i < bucket_size; i++) {
    if (bucket[i] != -1) {
      printf("%d ", bucket[i]);
    }
  }
  printf("\n");
}

// Main function
int main() {
  int n, i, j;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int *array = malloc(n * sizeof(int));
  printf("Enter the elements:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  // Create buckets
  int bucket_size = 10;
  int **buckets = malloc(bucket_size * sizeof(int *));
  for (i = 0; i < bucket_size; i++) {
    buckets[i] = malloc(n * sizeof(int));
    for (j = 0; j < n; j++) {
      buckets[i][j] = -1;
    }
  }

  // Insert elements into buckets
  for (i = 0; i < n; i++) {
    int bucket_index = array[i] / bucket_size;
    bucket_insert(buckets[bucket_index], array[i], n);
  }

  // Sort buckets
  for (i = 0; i < bucket_size; i++) {
    bucket_sort(buckets[i], n);
  }

  // Merge buckets
  int *sorted_array = malloc(n * sizeof(int));
  int sorted_index = 0;
  for (i = 0; i < bucket_size; i++) {
    for (j = 0; j < n; j++) {
      if (buckets[i][j] != -1) {
        sorted_array[sorted_index++] = buckets[i][j];
      }
    }
  }

  // Print the sorted array
  printf("Sorted array:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", sorted_array[i]);
  }
  printf("\n");

  // Free memory
  for (i = 0; i < bucket_size; i++) {
    free(buckets[i]);
  }
  free(buckets);
  free(array);
  free(sorted_array);

  return 0;
}