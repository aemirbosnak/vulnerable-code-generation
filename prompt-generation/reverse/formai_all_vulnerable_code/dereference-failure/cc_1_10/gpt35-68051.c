//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int* arr, int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binary_search(int* arr, int left_bound, int right_bound, int element){
    if(left_bound <= right_bound){
        int mid = left_bound + (right_bound - left_bound)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(element > arr[mid]){
            return binary_search(arr, mid+1, right_bound, element);
        }else{
            return binary_search(arr, left_bound, mid-1, element);
        }
    }
    return -1;
}

int main(){
    // initialize array
    int arr_size = 10;

    // generate random seed
    srand(time(NULL));

    int* arr = malloc(sizeof(int) * arr_size);

    for(int i=0;i<arr_size;i++){
        // generate random number between 1 and 100
        arr[i] = (rand() % 100) + 1;
    }

    // sort the array
    for(int i=0;i<arr_size-1;i++){
        for(int j=0;j<(arr_size-i-1);j++){
            if(arr[j] > arr[j+1]){
                // swap them
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Generated and sorted array:\n");
    print_arr(arr, arr_size);

    int element_to_search = 33;
    int index = binary_search(arr, 0, arr_size-1, element_to_search);
    if(index == -1){
        printf("Element not found in array\n");
    }else{
        printf("Element %d found at index %d in array\n", element_to_search, index);
    }

    free(arr);

    return 0;
}