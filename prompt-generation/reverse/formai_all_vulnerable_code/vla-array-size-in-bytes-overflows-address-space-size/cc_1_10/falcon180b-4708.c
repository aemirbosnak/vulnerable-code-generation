//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the maximum element in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = findMax(arr, n);
    int range = max / n;
    int* bucket[n];
    for (int i = 0; i < n; i++) {
        bucket[i] = (int*)malloc(sizeof(int) * range);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int index = arr[j] / range * n + i;
            bucket[index] = (int*)realloc(bucket[index], sizeof(int) * (j + 1));
            bucket[index][j] = arr[j];
        }
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = bucket[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        free(bucket[i]);
    }
}

// Function to generate a random array of integers
void generateArray(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    generateArray(arr, n);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}