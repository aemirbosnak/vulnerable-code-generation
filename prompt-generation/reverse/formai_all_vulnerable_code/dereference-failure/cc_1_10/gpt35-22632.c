//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to print the array 
void print_array(int *arr, int size) 
{ 
    for (int i = 0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Function to find the maximum value in the array 
int find_max(int *arr, int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) 
    { 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    return max;
}

// Bucket sort implementation function 
void bucketSort(int *arr, int size) 
{ 
    int max = find_max(arr, size);
    int bucket_count[BUCKET_SIZE] = {0}; 
    int *bucket[BUCKET_SIZE]; 
  
    // Create empty buckets 
    for (int i = 0; i < BUCKET_SIZE; i++) 
        bucket[i] = (int*)malloc(size * sizeof(int)); 
    
    // Put the elements in the appropriate bucket 
    for (int i = 0; i < size; i++) 
    { 
        int bucket_index = (BUCKET_SIZE * arr[i])/ (max + 1); 
        bucket[bucket_index][bucket_count[bucket_index]] = arr[i]; 
        bucket_count[bucket_index]++; 
    } 

    // Sort each bucket using insertion sort 
    for (int i = 0; i < BUCKET_SIZE; i++) 
    { 
        for (int j = 0; j < bucket_count[i]; j++) 
        { 
            int k = j - 1; 
            int bucket_value = bucket[i][j]; 
            while (k >= 0 && bucket[i][k] > bucket_value) 
            { 
                bucket[i][k + 1] = bucket[i][k]; 
                k--; 
            } 
            bucket[i][k + 1] = bucket_value; 
        } 
    } 

    // Concatenate sorted buckets into output array
    int index = 0; 
    for (int i = 0; i < BUCKET_SIZE; i++) 
    { 
        for (int j = 0; j < bucket_count[i]; j++) 
        { 
            arr[index] = bucket[i][j]; 
            index++; 
        } 
    } 

    // Free up dynamic memory allocated for buckets 
    for (int i = 0; i < BUCKET_SIZE; i++) 
        free(bucket[i]);  
} 

int main() 
{ 
    int size, i;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the array elements: ");
    for(i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    print_array(arr, size);
    
    bucketSort(arr, size);
    
    printf("Sorted array: ");
    print_array(arr, size); 

    return 0; 
}