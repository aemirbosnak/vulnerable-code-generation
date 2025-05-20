//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

// Function to generate a random number within a given range
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int max_val) {
    int i, j, k;
    int* buckets[MAX_SIZE];

    // Initialize all buckets to NULL
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Place each element in the appropriate bucket
    for (i = 0; i < n; i++) {
        int bucket_index = rand_range(0, MAX_SIZE - 1);
        if (buckets[bucket_index] == NULL) {
            buckets[bucket_index] = malloc(sizeof(int));
        }
        int* bucket = buckets[bucket_index];
        int num_elems = 0;
        while (bucket!= NULL && num_elems < max_val) {
            if (*(bucket + num_elems) == arr[i]) {
                // Element already in bucket, do nothing
            } else {
                swap(bucket + num_elems, bucket + num_elems + 1);
                swap(arr + i, arr + i + 1);
            }
            num_elems++;
            bucket++;
        }
    }

    // Copy elements back into original array
    for (i = 0; i < n; i++) {
        int bucket_index = rand_range(0, MAX_SIZE - 1);
        int* bucket = buckets[bucket_index];
        while (*(bucket + 0)!= arr[i]) {
            bucket++;
        }
        swap(arr + i, bucket + 0);
    }
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int i, max_val;

    // Find maximum value in array
    max_val = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    // Partition the array into buckets
    partition(arr, n, max_val);
}

// Function to print the sorted array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int i, n;
    srand(time(NULL));

    // Prompt user for array size
    printf("Enter array size: ");
    scanf("%d", &n);

    // Prompt user for array elements
    int arr[n];
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform bucket sort
    bucket_sort(arr, n);

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}