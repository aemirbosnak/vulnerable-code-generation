//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define RANGE 1000

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int buckets[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    // Find the maximum and minimum values in the array
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range of values
    int range = max - min + 1;

    // Initialize all buckets to empty
    for (int i = 0; i < MAX_SIZE; i++) {
        buckets[i] = -1;
    }

    // Place each element in its respective bucket
    for (int i = 0; i < size; i++) {
        int index = (arr[i] - min) / range;
        if (buckets[index] == -1) {
            buckets[index] = i;
        } else {
            int j = buckets[index];
            while (j < i) {
                j = (j + 1) % MAX_SIZE;
            }
            buckets[j] = i;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int j = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= -1) {
            arr[j++] = arr[buckets[i]];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generateRandomNumbers(arr, size);

    printf("Original array:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}