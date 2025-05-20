//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000

// Function to generate random numbers between 0 and 100
int generateRandomNumber() {
    return rand() % 101;
}

// Function to swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array based on the pivot element
int partition(int arr[], int low, int high, int pivot) {
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
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
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int range = max - min + 1;
    int *bucket = (int *)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) {
        bucket[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = arr[i] - min;
        bucket[index]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[j] = i + min;
            j++;
            bucket[i]--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = generateRandomNumber();
    }
    printf("Original array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);
    return 0;
}