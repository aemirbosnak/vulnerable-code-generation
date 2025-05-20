//FormAI DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int* randomArray(int size){
    int* array = (int*) malloc(size*sizeof(int));
    for(int i=0; i<size; i++){
        array[i] = rand()%100;
    }
    return array;
}

int binarySearch(int* arr, int left, int right, int x) {
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == x)
         return mid;  
      if (arr[mid] < x)
         left = mid + 1;
      else
         right = mid - 1;
   }
   return -1;  
}

int main(){

    //Generating random array of size 50
    int* arr = randomArray(50);
    printf("Randomly generated array: ");
    for(int i=0; i<50; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Sorting the array using bubble sort
    for(int i=0; i<50; i++){
        for(int j=0; j<50-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(int i=0; i<50; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Searching user entered element using binary search
    printf("Enter an element to search: ");
    int x;
    scanf("%d", &x);
    int result = binarySearch(arr, 0, 50-1, x);
    if(result==-1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at index %d\n", result);
    }

    free(arr);
    return 0;
}