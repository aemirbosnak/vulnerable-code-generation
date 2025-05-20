//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Bucket Sort implementation
void bucketSort(float arr[], int n) 
{ 
    // Create an array of n lists, each list represents a bucket
    int i, j; 
    float val; 
    int buck_num = n; 
    float** bucket = (float**) malloc(sizeof(float*) * buck_num); 

    // Initialize the buckets with null pointers 
    for (i = 0; i < buck_num; ++i) 
    { 
        bucket[i] = NULL; 
    } 

    // Assign elements to the proper bucket list 
    for (i = 0; i < n; ++i) 
    { 
        int idx = (int)(arr[i] * buck_num); 
        bucket[idx] = (float*)realloc(bucket[idx], sizeof(float) * (idx+1));
        bucket[idx][idx] = arr[i]; 
    } 

    // Sort each bucket list individually 
    for (i = 0; i < buck_num; ++i) 
    { 
        // insertion sort is used for simplicity 
        for (j = 1; j < (i+1); ++j) 
        { 
            val = bucket[i][j]; 
            int k = j - 1; 
            while (k >= 0 && bucket[i][k] > val) 
            { 
                bucket[i][k+1] = bucket[i][k]; 
                k--; 
            } 
            bucket[i][k+1] = val; 
        } 
    } 

    // Gather all the sorted elements into one array 
    int idx = 0; 
    for (i = 0; i < buck_num; ++i) 
    { 
        for (j = 0; bucket[i] && j < (i+1); ++j) 
        { 
            arr[idx++] = bucket[i][j]; 
        } 
    } 

    // Free the memory of the buckets 
    for (i = 0; i < buck_num; ++i) 
    { 
        free(bucket[i]); 
    } 

    free(bucket); 
} 

// Driver program to test the function 
int main() 
{ 
    float arr[] = {0.12, 0.28, 0.06, 0.45, 0.38, 0.35}; 
    int n = sizeof(arr)/sizeof(float); 

    printf("Unsorted Array:\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%.2f ", arr[i]); 
    } 

    // Call the Bucket Sort function 
    bucketSort(arr, n); 

    printf("\nSorted Array:\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf("%.2f ", arr[i]); 
    } 

    return 0; 
}