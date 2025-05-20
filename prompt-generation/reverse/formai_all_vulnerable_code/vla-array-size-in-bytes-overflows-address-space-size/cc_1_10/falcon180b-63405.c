//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 10000

// Function to generate random numbers between 0 and RANGE-1
void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE; // Generate random number between 0 and RANGE-1
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int *bucket[MAX_SIZE]; // Create an array of pointers to hold the buckets
    int count[MAX_SIZE] = {0}; // Create an array to keep track of the number of elements in each bucket

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / RANGE; // Calculate the index of the bucket based on the value of the element
        bucket[bucketIndex] = (int*)realloc(bucket[bucketIndex], (count[bucketIndex] + 1) * sizeof(int)); // Allocate memory for the bucket if it doesn't exist, or resize the bucket if it does
        bucket[bucketIndex][count[bucketIndex]] = arr[i]; // Add the element to the appropriate bucket
        count[bucketIndex]++; // Increment the number of elements in the bucket
    }

    int index = 0; // Index for the sorted array
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) { // Check if the bucket exists
            for (int j = 0; j < count[i]; j++) {
                arr[index] = bucket[i][j]; // Add the elements from the bucket to the sorted array
                index++;
            }
            free(bucket[i]); // Free the memory allocated for the bucket
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generateRandomNumbers(arr, size); // Generate random numbers for the array

    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size); // Sort the array using bucket sort

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}