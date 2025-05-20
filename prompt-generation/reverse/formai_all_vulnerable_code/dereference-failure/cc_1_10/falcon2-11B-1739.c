//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to insert an element into its correct bucket
void insert(int* array, int* bucket, int bucket_size, int n) {
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] <= bucket[index]) {
            array[i] = bucket[index];
            bucket[index] = array[i];
            index++;
            if (index == bucket_size) {
                index = 0;
            }
        }
    }
}

// Function to merge two sorted arrays
void merge(int* array, int* a, int a_size, int* b, int b_size) {
    int index = 0;
    for (int i = 0; i < a_size + b_size; i++) {
        if (i < a_size && a[i] < b[i]) {
            array[i] = a[i];
        } else {
            array[i] = b[i];
        }
    }
}

// Function to bucket sort an array
void bucket_sort(int* array, int n) {
    // Initialize buckets
    int* bucket = malloc(n * sizeof(int));
    int bucket_size = n / 10;

    // Insert elements into buckets
    insert(array, bucket, bucket_size, n);

    // Merge sorted buckets back into array
    for (int i = 0; i < bucket_size; i++) {
        int* temp_array = malloc(bucket[i] * sizeof(int));
        for (int j = 0; j < bucket[i]; j++) {
            temp_array[j] = array[i * bucket_size + j];
        }
        merge(array, temp_array, bucket[i], array + i * bucket_size, bucket_size);
        free(temp_array);
    }

    // Free memory
    free(bucket);
}

// Function to print an array
void print_array(int* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = { 8, 3, 5, 2, 9, 1, 6, 4, 7 };
    int n = sizeof(array) / sizeof(array[0]);

    printf("Before sorting: ");
    print_array(array, n);

    bucket_sort(array, n);

    printf("After sorting: ");
    print_array(array, n);

    return 0;
}