//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to the C Bucket Sort Implementation program!\n");
  printf("This program will sort an array of integers in ascending order using the bucket sort algorithm. But we're gonna do it in a funny way!\n");

  printf("\nEnter the size of the array you want to sort: ");
  int size;
  scanf("%d", &size);

  if (size == 0) {
    printf("There's nothing to sort dummy!\n");
    return 0;
  }

  int min = 0, max = 0;
  printf("Enter the range of the values (min max) in the array: ");
  scanf("%d %d", &min, &max);

  int range = max - min + 1;

  printf("\nInitializing array...\n");
  int* arr = (int*) malloc(sizeof(int) * size);
  int* bucket = (int*) calloc(range, sizeof(int));

  srand(time(NULL));
  printf("Randomizing array...\n");
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % range + min;
    bucket[arr[i]-min]++;
  }

  printf("Sorting array...\n");
  int index = 0;
  for (int i = 0; i < range; i++) {
    while (bucket[i] > 0) {
      arr[index] = i + min;
      index++;
      bucket[i]--;
      printf("Working my magic...\n");
    }
  }

  printf("\nHere's your sorted array:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
    if (i % 10 == 9) {
      printf("\n"); // just to make it look nicer
    }
  }

  free(arr);
  free(bucket);

  printf("\nBye bye for now! Hope you had fun sorting your array with me! ;)\n");

  return 0;
}