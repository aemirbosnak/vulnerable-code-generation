//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to create an array of size n with random values
int* create_array(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

// Function to print an array of size n
void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to sort an array of size n using bucket sort
void bucket_sort(int* arr, int n) {
    // Create an array of buckets
    int buckets[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            buckets[i][j] = 0;
        }
    }

    // Distribute the elements of the array into the buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] / MAX_SIZE;
        int element_index = arr[i] % MAX_SIZE;
        buckets[bucket_index][element_index] += 1;
    }

    // Sort each bucket individually
    for (int i = 0; i < MAX_SIZE; i++) {
        int sorted_bucket[MAX_SIZE];
        int sorted_index = 0;
        for (int j = 0; j < MAX_SIZE; j++) {
            while (buckets[i][j] > 0) {
                sorted_bucket[sorted_index] = i * MAX_SIZE + j;
                sorted_index += 1;
                buckets[i][j] -= 1;
            }
        }
        // Copy the sorted bucket back into the array
        for (int j = 0; j < sorted_index; j++) {
            arr[j] = sorted_bucket[j];
        }
    }
}

int main() {
    // Create an array of size n with random values
    int n = 100;
    int* arr = create_array(n);

    // Print the unsorted array
    printf("Unsorted array: ");
    print_array(arr, n);

    // Sort the array using bucket sort
    bucket_sort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}