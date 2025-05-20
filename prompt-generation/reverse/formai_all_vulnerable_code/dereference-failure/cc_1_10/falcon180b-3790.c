//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int *bucket[MAX_SIZE];
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int count[MAX_SIZE] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] - min) / range]++;
    }

    int index = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < count[i]; j++) {
            bucket[i][j] = arr[index];
            index++;
        }
    }

    index = 0;

    for (int i = 0; i < size; i++) {
        arr[i] = bucket[arr[i] - min][index];
        index++;
    }
}

int main() {
    int arr[] = {5, 3, 8, 2, 1, 6, 4, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sorting:\n");
    printArray(arr, size);

    bucketSort(arr, size);

    printf("After Sorting:\n");
    printArray(arr, size);

    return 0;
}