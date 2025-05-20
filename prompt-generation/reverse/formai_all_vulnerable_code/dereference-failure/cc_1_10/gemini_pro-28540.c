//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

// Swap two elements
#define SWAP(a, b) do { typeof(a) temp = a; a = b; b = temp; } while(0)

// Custom assert macro
#define ASSERT(expr, msg) do { if(!(expr)) { fprintf(stderr, "%s: Assertion failed at %s:%d\n", msg, __FILE__, __LINE__); abort(); } } while(0)

// Bucket sort implementation
void bucket_sort(int *arr, int n, int num_buckets) {
    // Create n empty buckets
    int **buckets = (int**)malloc(sizeof(int*) * num_buckets);
    for(int i=0; i<num_buckets; i++) buckets[i] = (int*)malloc(sizeof(int) * n);

    // Initialize bucket sizes to zero
    int *bucket_sizes = (int*)malloc(sizeof(int) * num_buckets);
    for(int i=0; i<num_buckets; i++) bucket_sizes[i] = 0;

    // Distribute elements into buckets
    int max = INT_MIN, min = INT_MAX;
    for(int i=0; i<n; i++) {
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }
    for(int i=0; i<n; i++) {
        int bucket_index = (num_buckets * (arr[i] - min) / (max - min));
        buckets[bucket_index][bucket_sizes[bucket_index]++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for(int i=0; i<num_buckets; i++) {
        for(int j=1; j<bucket_sizes[i]; j++) {
            int key = buckets[i][j];
            int k = j-1;
            while(k>=0 && buckets[i][k] > key) {
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    // Collect sorted elements from buckets
    int index = 0;
    for(int i=0; i<num_buckets; i++) {
        for(int j=0; j<bucket_sizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_sizes);
}

// Print array
void print_array(int *arr, int n) {
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Test bucket sort
int main() {
    int arr[] = {4, 2, 1, 5, 3, 9, 7, 6, 8};
    int n = sizeof(arr) / sizeof(int);

    bucket_sort(arr, n, 4);
    print_array(arr, n);

    return 0;
}