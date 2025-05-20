//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort 
void bubbleSort(int arr[], int n){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    
    printf("Welcome to the Bubble Sort program!\n\n");

    // Get size of the array
    int size;
    printf("Please enter the size of the array: ");
    scanf("%d", &size);

    // Create the array of numbers
    int arr[size];

    // Get the numbers for our array
    for(int i=0; i<size; i++){
        printf("Enter a number: ");
        scanf("%d", &arr[i]);
    }

    // Bubble sort the array
    bubbleSort(arr, size);

    // Print out the sorted array
    printf("\nHere is your sorted array:\n");
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nThank you for using the Bubble Sort program!\n");

    return 0;
}