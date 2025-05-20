//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the minimum and maximum values in an array
void findMinMax(int arr[], int size, int* min, int* max) {
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int size) {
    int max = arr[0], min = arr[0];
    findMinMax(arr, size, &min, &max);

    // Create empty buckets
    int* buckets[max - min + 1];
    for (int i = 0; i < max - min + 1; i++) {
        buckets[i] = NULL;
    }

    // Place elements in buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = (arr[i] - min) / (max - min) * (max - min + 1);
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = malloc(sizeof(int));
        }
        int* bucket = buckets[bucketIndex];
        int j = 0;
        while (bucket[j]!= -1) {
            j++;
        }
        bucket[j] = arr[i];
    }

    // Concatenate buckets back into array
    int index = 0;
    for (int i = 0; i < max - min + 1; i++) {
        int* bucket = buckets[i];
        while (bucket[index]!= -1) {
            arr[index++] = bucket[index];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}