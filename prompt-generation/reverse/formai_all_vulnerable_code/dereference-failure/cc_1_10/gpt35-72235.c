//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10000000 // Size of the array
#define MAX_NUM 1000 // Maximum random number


// Function to generate random number between 0 and MAX_NUM
int random_num() {
  return rand() % MAX_NUM;
}


// Function to print the array
void print_array(int* arr) {
  for(int i=0; i<SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}


// Function to sort the array
void sort_array(int* arr) {
  int i, j, temp;

  for(i=0; i<SIZE-1; i++) {
    for(j=0; j<SIZE-1-i; j++) {
      if(arr[j] > arr[j+1]) {
        // swap arr[j] and arr[j+1]
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}


int main() {
  int i, *arr = malloc(sizeof(int) * SIZE);

  // Initialize the array with random numbers
  srand((unsigned int) time(NULL));
  for(i=0; i<SIZE; i++) {
    arr[i] = random_num();
  }

  printf("Array before sorting:\n");
  print_array(arr);

  sort_array(arr);

  printf("Array after sorting:\n");
  print_array(arr);

  free(arr);

  return 0;
}