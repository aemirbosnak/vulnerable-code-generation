//FormAI DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate an array of random numbers
int* generate_array(int size){
  int* arr = (int*) malloc(size * sizeof(int));
  for(int i = 0; i < size; i++){
    arr[i] = rand() % 100;
  }
  return arr;
}

// function to print the elements in an array
void print_array(int* arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// function to implement binary search
int binary_search(int* arr, int start, int end, int target){
  int mid;
  while(start <= end){
    mid = (start + end) / 2;
    if(arr[mid] == target){
      return mid;
    }else if(arr[mid] > target){
      end = mid - 1;
    }else{
      start = mid + 1;
    }
  }
  return -1;
}

// main function to demonstrate the searching algorithm
int main(){
  // generate an array of random numbers
  srand(time(NULL));
  int size = 10;
  int* arr = generate_array(size);
 
  // print the original array
  printf("Original Array: ");
  print_array(arr, size);

  // sort the array using bubble sort
  for(int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - i - 1; j++){
      if(arr[j] > arr[j + 1]){
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // print the sorted array
  printf("Sorted Array: ");
  print_array(arr, size);

  // search for a target element
  int target = 50;
  int index = binary_search(arr, 0, size - 1, target);

  // print the result of the search
  if(index == -1){
    printf("Element %d not found!\n", target);
  }else{
    printf("Element %d found at index %d\n", target, index);
  }

  // free memory
  free(arr);

  return 0;
}