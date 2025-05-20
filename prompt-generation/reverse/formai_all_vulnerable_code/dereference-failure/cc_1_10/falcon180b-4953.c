//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the last element as pivot
int partition(int arr[], int n, int pivot) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;
    int* bucket = (int*) malloc(range * sizeof(int));
    for (int i = 0; i < range; i++)
        bucket[i] = 0;
    for (int i = 0; i < n; i++)
        bucket[arr[i] - min]++;
    for (int i = 0; i < range; i++) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[j + i * range] = i + min;
        }
    }
    free(bucket);
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*) malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bucketSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}