//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recoverData(char **arr, int size) {
  int i, j, k, l, count = 0;
  for (i = 0; i < size; i++) {
    for (j = i; j < size && arr[j] != '\0'; j++) {
      for (k = j; k < size && arr[k] != '\0'; k++) {
        for (l = k; l < size && arr[l] != '\0'; l++) {
          if (arr[i] == arr[j] && arr[i] == arr[k] && arr[i] == arr[l]) {
            count++;
          }
        }
      }
    }
  }
  printf("Number of repeated triplets: %d\n", count);
}

int main() {
  char **arr = NULL;
  int size = 0;

  // Allocate memory for the array
  arr = (char **)malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    arr[i] = (char *)malloc(100 * sizeof(char));
  }

  // Get the size of the array
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Get the data for the array
  printf("Enter the data for the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%s", arr[i]);
  }

  // Recover the data
  recoverData(arr, size);

  // Free the memory
  for (int i = 0; i < 10; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}