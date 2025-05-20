//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to compress the given integer array
void compressArray(int *arr, int n) {
  
  // sort the array in non-decreasing order
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  
  // create a new compressed array of half the size of original array
  int *compressedArr = (int*) calloc(n/2, sizeof(int));
  
  // initialize the compressed array with zeros
  for (int i = 0; i < n/2; i++) {
    compressedArr[i] = 0;
  }
  
  // compute the compressed array
  int count = 0;
  int currNum = arr[0];
  for (int i = 0; i < n; i++) {
    if (currNum == arr[i]) {
      count++;
    }
    else {
      compressedArr[currNum-1] = count;
      count = 1;
      currNum = arr[i];
    }
  }
  compressedArr[currNum-1] = count;
  
  // print the compressed array
  printf("Compressed Array:\n");
  for (int i = 0; i < n/2; i++) {
    if (compressedArr[i] != 0) {
      printf("%d %d\n", i+1, compressedArr[i]);
    }
  }
  
  // free the memory allocated for compressed array
  free(compressedArr);
}

// Main function
int main() {
  int arr[] = {1, 2, 2, 2, 3, 3, 4, 5, 5, 5, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original Array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  compressArray(arr, n);
  return 0; 
}