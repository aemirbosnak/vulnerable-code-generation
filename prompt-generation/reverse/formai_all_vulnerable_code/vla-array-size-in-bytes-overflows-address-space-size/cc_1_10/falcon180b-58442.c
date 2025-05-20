//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int *buckets[MAX_SIZE];
    int bucketSize = MAX_SIZE / size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (arr[i] <= j * bucketSize) {
                buckets[j%MAX_SIZE] = realloc(buckets[j%MAX_SIZE], sizeof(int)*(1+countBuckets(buckets[j%MAX_SIZE], j*bucketSize)));
                buckets[j%MAX_SIZE][countBuckets(buckets[j%MAX_SIZE], j*bucketSize)] = arr[i];
                break;
            }
        }
    }

    int index = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < countBuckets(buckets[i], i*bucketSize); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int countBuckets(int *bucket, int start) {
    int count = 0;
    while (bucket[count]!= -1 && bucket[count] <= start) {
        count++;
    }
    return count;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    generateArray(arr, size);
    printf("Original Array: ");
    printArray(arr, size);

    bucketSort(arr, size);
    printf("Sorted Array: ");
    printArray(arr, size);

    return 0;
}