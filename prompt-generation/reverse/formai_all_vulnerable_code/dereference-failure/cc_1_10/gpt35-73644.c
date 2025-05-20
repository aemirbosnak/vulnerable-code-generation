//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
 
// Defining maximum number of elements that can fit into each bucket
#define MAX_ELE 100
 
// Defining maximum range of values
#define MAX_VAL 1000
 
// Function to sort elements using bucket sort algorithm
void bucket_sort(int arr[], int n)
{
    int i, j, k;
    
    // Create n empty buckets
    int bucket[MAX_ELE];
 
    // Initializing all the buckets with 0
    for (i = 0; i < MAX_ELE; ++i)
        bucket[i] = 0;
 
    // Increment the value of bucket[i] for every element in arr[i]
    for (i = 0; i < n; ++i)
        ++bucket[arr[i]];
 
    // Performing insertion sort on every bucket
    for (i = 0, j = 0; j < MAX_ELE; ++j)
        for (k = bucket[j]; k > 0; --k)
            arr[i++] = j;
}
 
int main()
{
    int i, size;
    
    // Getting size of array from user
    printf("\nEnter size of array: ");
    scanf("%d", &size);
    
    // Dynamic memory allocation for array
    int *arr = (int *) malloc(size * sizeof(int));
    
    // Filling array with random values from range 0 to 999
    for (i = 0; i < size; ++i)
        arr[i] = rand() % MAX_VAL;
 
    // Sorting the array using Bucket Sort algorithm
    bucket_sort(arr, size);
 
    // Printing sorted array
    printf("\nSorted Array:\n");
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
 
    printf("\n");
    
    // Freeing dynamically allocated memory
    free(arr);
    
    return 0;
}