//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in an array
int findMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
  // Create n empty buckets
  int **buckets = malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = malloc(sizeof(int) * n);
  }

  // Find the maximum value in the array
  int max = findMax(arr, n);

  // Create a hash table to store the number of elements in each bucket
  int *hashTable = calloc(max + 1, sizeof(int));

  // Insert the elements of the array into the buckets
  for (int i = 0; i < n; i++) {
    int bucketIndex = arr[i] * n / (max + 1);
    hashTable[arr[i]]++;
    buckets[bucketIndex][hashTable[arr[i]]] = arr[i];
  }

  // Sort the elements in each bucket using insertion sort
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < hashTable[i]; j++) {
      for (int k = j + 1; k < hashTable[i]; k++) {
        if (buckets[i][k] < buckets[i][j]) {
          int temp = buckets[i][k];
          buckets[i][k] = buckets[i][j];
          buckets[i][j] = temp;
        }
      }
    }
  }

  // Concatenate the sorted buckets into the original array
  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < hashTable[i]; j++) {
      arr[index++] = buckets[i][j];
    }
  }

  // Free the memory allocated for the buckets and the hash table
  for (int i = 0; i < n; i++) {
    free(buckets[i]);
  }
  free(buckets);
  free(hashTable);
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  // Get the size of the array
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);

  // Get the elements of the array
  int arr[n];
  printf("Enter the elements of the array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Sort the array using bucket sort
  bucketSort(arr, n);

  // Print the sorted array
  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}