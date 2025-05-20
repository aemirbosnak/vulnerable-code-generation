//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define a function to sort an array using bucket sort
void bucketSort(int array[], int n)
{

    // Create the bucket array and initialize all elements to 0
    int *bucket = calloc(n, sizeof(int));
    if (bucket == NULL)
    {
        printf("Error: unable to allocate memory\n");
        exit(1);
    }

    // Fill the bucket array with the frequency of each element in the input array
    for (int i = 0; i < n; i++)
    {
        bucket[array[i]]++;
    }

    // Create the sorted array
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucket[i]; j++)
        {
            array[index++] = i;
        }
    }

    // Free the bucket array
    free(bucket);
}

int main()
{
    // Declare an array of integers to be sorted
    int array[] = {5, 2, 8, 3, 0, 10, 7};

    // Calculate the number of elements in the array
    int n = sizeof(array) / sizeof(int);

    // Call the bucketSort function to sort the array
    bucketSort(array, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}