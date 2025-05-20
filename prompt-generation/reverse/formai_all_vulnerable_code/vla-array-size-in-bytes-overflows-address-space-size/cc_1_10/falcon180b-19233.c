//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 100

int arr[MAX];

void generateArray(int arr[], int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % RANGE;
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int n) {
    int buckets[RANGE];
    for(int i = 0; i < RANGE; i++) {
        buckets[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int bucket = arr[i] / (RANGE / n);
        buckets[bucket]++;
    }

    int index = 0;
    for(int i = 0; i < RANGE; i++) {
        for(int j = 0; j < buckets[i]; j++) {
            arr[index++] = i * (RANGE / n) + j * (RANGE / n / n);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    generateArray(arr, n);
    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}