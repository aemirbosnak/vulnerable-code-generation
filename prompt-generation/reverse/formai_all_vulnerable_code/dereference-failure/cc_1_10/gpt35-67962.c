//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include<stdio.h>
#include<stdlib.h>

int main(){
  // Dynamic memory allocation
  int size;
  printf("Enter the size of the integer array: ");
  scanf("%d", &size);
  int* arr = (int*)malloc(size * sizeof(int));
  if(arr==NULL){ // Checking for allocation failure
    printf("Memory allocation failed\n");
    exit(0); // Terminating program
  }

  // Filling array with random values
  for(int i=0; i<size; i++){
    *(arr+i) = rand()%100 + 1;
  }

  // Displaying the array
  printf("The integer array is: ");
  for(int i=0; i<size; i++){
    printf("%d ", *(arr+i));
  }
  printf("\n");

  // Reallocating memory
  int new_size;
  printf("Enter the new size of the integer array: ");
  scanf("%d", &new_size);
  int* new_arr = (int*)realloc(arr, new_size * sizeof(int));
  if(new_arr==NULL){ // Checking for allocation failure
    printf("Memory reallocation failed\n");
    exit(0); // Terminating program
  }

  // Filling remaining size with random values
  for(int i=size; i<new_size; i++){
    *(new_arr+i) = rand()%100 + 1;
  }

  // Displaying the new array
  printf("The new integer array is: ");
  for(int i=0; i<new_size; i++){
    printf("%d ", *(new_arr+i));
  }
  printf("\n");

  free(new_arr); // Freeing the allocated memory
  return 0;
}