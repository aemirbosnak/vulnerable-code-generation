//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define NUM_BUCKETS 10

// Function to get the digit at a specified position from the right
int get_digit(int number, int position) {
    return (number / position) % 10;
}

// Bucket Sort implementation
void bucket_sort(int *arr, int n) {
    // Create buckets
    int **buckets = (int **)malloc(NUM_BUCKETS * sizeof(int *));
    int *bucket_sizes = (int *)malloc(NUM_BUCKETS * sizeof(int));
    
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *)malloc(n * sizeof(int));
        bucket_sizes[i] = 0;
    }

    // Find the maximum value to determine the number of passes
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    
    // Sort numbers based on each digit
    for (int position = 1; max_value / position > 0; position *= 10) {
        // Clear bucket sizes
        for (int i = 0; i < NUM_BUCKETS; i++) {
            bucket_sizes[i] = 0;
        }

        // Distribute the numbers into buckets
        for (int i = 0; i < n; i++) {
            int bucket_index = get_digit(arr[i], position);
            buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
            bucket_sizes[bucket_index]++;
        }

        // Collect the numbers from buckets
        int index = 0;
        for (int i = 0; i < NUM_BUCKETS; i++) {
            for (int j = 0; j < bucket_sizes[i]; j++) {
                arr[index++] = buckets[i][j];
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

// Utility function to print an array
void print_array(int *arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Utility function to generate random integers
void generate_random_array(int *arr, int n, int max_value) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % max_value;
    }
}

int main() {
    int n;
    int max_value = 100;

    printf("Enter the number of elements for bucket sort: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));

    // Generate random numbers
    generate_random_array(arr, n, max_value);
    printf("Original Array: ");
    print_array(arr, n);

    // Sort the array using bucket sort
    bucket_sort(arr, n);
    printf("Sorted Array: ");
    print_array(arr, n);

    // Free the allocated array
    free(arr);

    return 0;
}