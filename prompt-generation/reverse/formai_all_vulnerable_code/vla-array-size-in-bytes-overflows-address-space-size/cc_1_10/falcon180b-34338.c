//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
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

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));

    for (int i = 0; i < range; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++) {
        int index = (arr[i] - min) / (max - min) * range;
        bucket[index]++;
    }

    int k = 0;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[k] = i * (max - min) + min + j;
            k++;
        }
    }
}

// Function to generate random array
void generateArray(int arr[], int n) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % MAX;
    }
}

// Main function
int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    generateArray(arr, n);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}