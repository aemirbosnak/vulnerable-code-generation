//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

// Function to sort the array using bucket sort
void bucketSort(int arr[], int size) {
    int maxValue = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    int bucketSize = maxValue / size;
    int *buckets[size];
    for (int i = 0; i < size; i++) {
        buckets[i] = (int *)malloc(bucketSize * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / bucketSize;
        int bucketPosition = 0;
        while (bucketPosition < bucketSize && buckets[bucketIndex][bucketPosition]!= 0) {
            bucketPosition++;
        }
        buckets[bucketIndex][bucketPosition] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < bucketSize; j++) {
            if (buckets[i][j]!= 0) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(buckets[i]);
    }
}

// Function to print the sorted array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    int arr[size];

    if (size > 0 && size <= MAX_SIZE) {
        printf("Enter the elements of the array:\n");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }

        generateRandomNumbers(arr, size);
        printf("Random array:\n");
        printArray(arr, size);

        bucketSort(arr, size);
        printf("Sorted array:\n");
        printArray(arr, size);
    } else {
        printf("Invalid array size.\n");
    }

    return 0;
}