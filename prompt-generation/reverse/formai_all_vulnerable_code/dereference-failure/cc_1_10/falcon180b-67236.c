//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

// Helper function to swap two elements
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Helper function to partition the array
int partition(int arr[], int low, int high, int pivot) {
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to implement bucket sort
void bucketSort(int arr[], int size) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        int index = arr[i] - min;
        if (bucket[index] == -1) {
            bucket[index] = i;
        } else {
            int j = bucket[index];
            while (j < i) {
                j += range;
            }
            bucket[j] = i;
        }
    }
    int *output = (int *)malloc(size * sizeof(int));
    int outIndex = 0;
    for (int i = 0; i < range; i++) {
        int j = bucket[i];
        while (j!= -1) {
            output[outIndex++] = arr[j];
            j += range;
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    free(bucket);
    free(output);
}

// Main function to test the bucket sort
int main() {
    srand(time(NULL));
    int size = rand() % 100 + 1;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }
    printf("Original array: ");
    printArray(arr, size);
    bucketSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    free(arr);
    return 0;
}