//FormAI DATASET v1.0 Category: Sorting ; Style: complete
#include<stdio.h>
#include<stdlib.h>

// function to swap two numbers
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to perform selection sort
void selection_sort(int arr[], int n){
    int i, j, min_index;

    // loop through the array
    for(i=0; i<n-1; i++){
        // set the minimum index to current element
        min_index = i;

        // find the minimum element in the unsorted part of the array
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }

        // swap the minimum element with the current element
        swap(&arr[i], &arr[min_index]);
    }
}

int main(){
    int i, n, *arr;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // allocate memory for array
    arr = (int*)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    // perform selection sort
    selection_sort(arr, n);

    printf("The sorted array is: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}