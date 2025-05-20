//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10
#define MAX_NUM 1000.0

void bucketSort(float arr[], int n);
void insertionSort(float arr[], int n);
void printArray(float arr[], int n);

int main() {
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    
    printf("Enter the elements (between 0 and %.2f):\n", MAX_NUM);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    free(arr);
    return 0;
}

void bucketSort(float arr[], int n) {
    // Create an array of buckets
    int bucketCount = (int)(MAX_NUM / BUCKET_SIZE) + 1;
    float **buckets = (float **)malloc(bucketCount * sizeof(float *));
    int *bucketSizes = (int *)malloc(bucketCount * sizeof(int));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = (float *)malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] / BUCKET_SIZE);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Sort each bucket and gather the result
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketSizes[i] > 0) {
            insertionSort(buckets[i], bucketSizes[i]);
            for (int j = 0; j < bucketSizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free memory used by buckets
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}