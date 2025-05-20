//FormAI DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter %d elements: ", n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("Original Array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    // Dynamic memory allocation
    int *newArr;
    newArr = (int*) calloc(n, sizeof(int));
    
    // Copying elements from original array to dynamic array in reverse order
    for(int i=n-1, j=0; i>=0; i--, j++){
        *(newArr + j) = arr[i];
    }
    
    printf("\n\nReversed Array using Dynamic Memory Allocation: ");
    for(int i=0; i<n; i++){
        printf("%d ", *(newArr +i));
    }
    
    // Sorting dynamic array using bubble sort algorithm
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(*(newArr+j) > *(newArr+j+1)){
                int temp = *(newArr+j);
                *(newArr+j) = *(newArr+j+1);
                *(newArr+j+1) = temp;
            }
        }
    }
    
    printf("\n\nSorted Array using Dynamic Memory Allocation: ");
    for(int i=0; i<n; i++){
        printf("%d ", *(newArr +i));
    }
    
    // Deallocating memory
    free(newArr);
    newArr = NULL;
    
    return 0;
}