//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function for bucket sort
void bucket_sort(int arr[], int n) {
    // Define variables
    int i, j;
    int min_val = arr[0], max_val = arr[0];
    int bucket_size = 5; // Size of each bucket
    int num_buckets;
    int *bucket; // Pointer to the buckets
    
    // Find max and min values in array
    for (i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    
    // Calculate the number of buckets needed
    num_buckets = (max_val - min_val) / bucket_size + 1;
    
    // Allocate memory for the buckets
    bucket = (int *)malloc(num_buckets * sizeof(int));
    
    // Initialize the buckets as empty
    for (i = 0; i < num_buckets; i++) {
        bucket[i] = 0;
    }
    
    // Insert elements into the appropriate buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val) / bucket_size; // Calculate the index of the bucket
        bucket[j]++; // Increment the count of the bucket
    }
    
    // Sort the elements in each bucket
    for (i = 0, j = 0; i < num_buckets; i++) {
        while (bucket[i] > 0) { // While the bucket is not empty
            arr[j++] = i * bucket_size + min_val; // Add the elements back to the original array
            bucket[i]--; // Decrement the count of the bucket
        }
    }
    
    // Free the memory
    free(bucket);
}

// Function to print the array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver function
int main() {
    int arr[] = {45, 23, 64, 78, 5, 90, 34, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    print_array(arr, n);
    
    bucket_sort(arr, n);
    
    printf("Sorted array: ");
    print_array(arr, n);
    
    return 0;
}