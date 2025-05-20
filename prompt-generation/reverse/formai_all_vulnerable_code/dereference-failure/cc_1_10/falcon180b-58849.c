//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define RANGE 1000

// Function to generate random numbers
void generateRandomNumbers(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n, int bucket_size) {
    int *bucket[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / bucket_size) * bucket_size;
        if (bucket[index] == NULL) {
            bucket[index] = (int *) malloc(sizeof(int));
        }
        int *temp = (int *) realloc(bucket[index], sizeof(int) * (1 + (int) bucket[index]));
        temp[0] = arr[i];
        bucket[index] = temp;
    }
    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (int j = 0; j < (int) bucket[i]; j++) {
                arr[index++] = bucket[i][j];
            }
        }
    }
}

// Function to print the sorted array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, bucket_size;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the bucket size: ");
    scanf("%d", &bucket_size);
    int arr[n];
    generateRandomNumbers(arr, n);
    printf("Unsorted array:\n");
    printArray(arr, n);
    bucketSort(arr, n, bucket_size);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}