//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>

int main() {
    int size = 10;

    // Create a dynamic array of integers
    int *arr = (int*) malloc(size * sizeof(int));

    // Initialize the array with random numbers
    srand(time(0));
    for(int i=0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // Sort the array in ascending order using bubble sort algorithm
    int temp;
    for(int i=0; i < size - 1; i++) {
        for(int j=0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Reverse the sorted array
    int start = 0;
    int end = size - 1;
    while(start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    // Print the reversed array
    printf("\nReversed Array: ");
    for(int i=0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Find the sum and average of the original array
    int sum = 0;
    float avg;
    for(int i=0; i < size; i++) {
        sum += arr[i];
    }
    avg = (float) sum / size;
    printf("\nSum of Array: %d", sum);
    printf("\nAverage of Array: %.2f", avg);

    // Free the dynamic memory allocated for the array
    free(arr);

    return 0;
}