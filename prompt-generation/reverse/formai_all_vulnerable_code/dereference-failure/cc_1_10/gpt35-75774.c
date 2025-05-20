//FormAI DATASET v1.0 Category: Benchmarking ; Style: beginner-friendly
#include <stdio.h>  // Included for printf() function
#include <stdlib.h>  // Included for malloc() and free() functions
#include <time.h>    // Included for clock() function
 
#define ARR_SIZE 10000000 // Size of array
 
int main()
{
    int *arr;  // Pointer to array
    int i, sum = 0;
    clock_t start_time, end_time;  // Variables for calculating time
 
    // Dynamic memory allocation
    arr = (int *)malloc(ARR_SIZE * sizeof(int));
    
    // Initialize array with random numbers between 0 and 99
    for (i = 0; i < ARR_SIZE; i++)
    {
        arr[i] = rand() % 100;
    }
 
    // Benchmarking linear search
    printf("Linear Search: \n");
    start_time = clock();  // Starting time
    for (i = 0; i < ARR_SIZE; i++)
    {
        if (arr[i] == 50)  // Searching for number 50
        {
            sum = i;
            break;
        }
    }
    end_time = clock();  // Ending time
    printf("Time taken for Linear Search : %ld\n", end_time - start_time);
 
    // Benchmarking binary search
    printf("Binary Search: \n");
    start_time = clock();  // Starting time
    int low = 0, high = ARR_SIZE - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == 50)  // Searching for number 50
        {
            sum = mid;
            break;
        } 
        else if (arr[mid] > 50)
        {
            high = mid - 1;
        } 
        else
        {
            low = mid + 1;
        }
    }
    end_time = clock();  // Ending time
    printf("Time taken for Binary Search : %ld\n", end_time - start_time);
 
    // Free allocated memory
    free(arr);
 
    return 0;
}