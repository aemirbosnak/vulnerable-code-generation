//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int A[], int n)
{
    // Find the maximum element in the array A
    int max = A[0];
    for(int i = 1; i < n; i++) 
    {
        if(A[i] > max) 
        {
            max = A[i];
        }
    }
    
    // Create an array of buckets
    int *buckets = malloc(max * sizeof(int));
    for(int i = 0; i < max; i++) 
    {
        buckets[i] = 0;
    }
    
    // Increment the corresponding bucket element for each array element
    for(int i = 0; i < n; i++) 
    {
        buckets[A[i]]++;
    }
    
    // Update the array A with the sorted elements from the buckets
    int p = 0;
    for(int i = 0; i < max; i++) 
    {
        for(int j = 0; j < buckets[i]; j++) 
        {
            A[p++] = i;
        }
    }
    
    free(buckets);
}

int main()
{
    int A[] = {29, 27, 24, 21, 19, 17, 15, 13, 11, 10, 9, 7, 5, 3, 1};
    int n = 15;
    
    printf("Original Array: [");
    for(int i = 0; i < n; i++) 
    {
        printf("%d, ", A[i]);
    }
    printf("]\n");
    
    bucketSort(A, n);
    
    printf("Sorted Array: [");
    for(int i = 0; i < n; i++) 
    {
        printf("%d, ", A[i]);
    }
    printf("]\n");
    
    return 0;
}