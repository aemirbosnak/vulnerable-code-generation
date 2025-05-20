//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define RANGE 1000000

// Function to generate a random number within the given range
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform the bucket sort algorithm
void bucket_sort(int* arr, int n) {
    int* bucket = (int*) malloc(MAX_SIZE * sizeof(int));
    int range = RANGE / n;
    int i, j;

    // Initialize all elements in the array to 0
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = 0;
    }

    // Place elements into the appropriate bucket
    for (i = 0; i < n; i++) {
        int index = rand_num(0, RANGE - 1);
        bucket[index]++;
    }

    // Place elements back into the array
    for (i = 0; i < n; i++) {
        int index = rand_num(0, RANGE - 1);
        arr[i] = index;
    }

    // Sort the array using the bucket sort algorithm
    for (i = 0; i < n; i++) {
        int index = arr[i];
        swap(&arr[i], &arr[bucket[index]]);
        bucket[index]++;
    }

    free(bucket);
}

// Function to print an array
void print_array(int* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int* arr = (int*) malloc(MAX_SIZE * sizeof(int));
    int n;

    // Prompt the user for the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Generate a random array of integers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_num(0, MAX_SIZE);
    }

    // Print the original array
    printf("Original array:\n");
    print_array(arr, n);

    // Sort the array using the bucket sort algorithm
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    free(arr);
    return 0;
}