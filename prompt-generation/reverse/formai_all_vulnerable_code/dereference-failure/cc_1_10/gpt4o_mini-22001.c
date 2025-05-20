//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two arrays elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to implement merge
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Function to implement merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to generate random numbers
void generateRandomNumbers(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
}

int main() {
    srand(time(0)); // Seed for randomness
    int size = 100; // Set size of the array
    int *arr = (int *)malloc(size * sizeof(int));

    // Generation of random numbers
    generateRandomNumbers(arr, size);

    printf("Unsorted array: \n");
    printArray(arr, size);

    printf("Sorting using Bubble Sort...\n");
    bubbleSort(arr, size);
    printf("Sorted array (Bubble Sort): \n");
    printArray(arr, size);

    // Generate another set of random numbers
    generateRandomNumbers(arr, size);

    printf("Unsorted array for Merge Sort: \n");
    printArray(arr, size);

    printf("Sorting using Merge Sort...\n");
    mergeSort(arr, 0, size - 1);
    printf("Sorted array (Merge Sort): \n");
    printArray(arr, size);

    free(arr); // Clean up the allocated memory
    return 0;
}