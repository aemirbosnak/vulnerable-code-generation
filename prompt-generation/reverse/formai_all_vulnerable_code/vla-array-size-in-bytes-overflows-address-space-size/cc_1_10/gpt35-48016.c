//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Function to perform bucket sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    int i, j;
    int bucket[n];
    for (i = 0; i < n; i++)
    {
        bucket[i] = 0;
    }

    // Fill the buckets with elements
    for (i = 0; i < n; i++)
    {
        int index = n * arr[i];
        bucket[index]++;
    }

    // Sort the elements in the buckets
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bucket[i]; j++)
        {
            printf("%f ", (float)i / n);
        }
    }
}

int main()
{
    int n, i;
    float* arr;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Allocate memory for array of size n
    arr = (float*)malloc(n * sizeof(float));

    // Get the array elements from the user
    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    // Call the bucket sort function on the array
    printf("The sorted array is: ");
    bucketSort(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}