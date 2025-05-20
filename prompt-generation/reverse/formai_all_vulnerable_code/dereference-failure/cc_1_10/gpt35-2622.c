//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>

// Define function to sort elements using bucket sort
void bucket_sort(int array[], int size)
{
    // Declare variables
    int i, j;
    int min_val = array[0], max_val = array[0];

    // Find minimum and maximum values in the array
    for (i = 1; i < size; ++i) 
    {
        if (array[i] < min_val) 
        {
            min_val = array[i];
        } 
        else if (array[i] > max_val) 
        {
            max_val = array[i];
        }
    }

    // Create buckets
    int bucket_count = max_val - min_val + 1;
    int *buckets = malloc(bucket_count * sizeof(int));

    // Initialize buckets to 0
    for (i = 0; i < bucket_count; ++i) 
    {
        buckets[i] = 0;
    }

    // Fill buckets
    for (i = 0; i < size; ++i) 
    {
        buckets[array[i] - min_val]++;
    }

    // Sort input array using buckets
    for (i = 0, j = 0; j < bucket_count; ++j) 
    {
        while (buckets[j]-- > 0) 
        {
            array[i++] = j + min_val;
        }
    }

    // Free the memory used for buckets
    free(buckets);
}

int main()
{
    // Declare variables
    int i, size;
    int array[100];

    // Prompt for input size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Fill array with values
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; ++i)
    {
        scanf("%d", &array[i]);
    }

    // Sort array using bucket sort
    bucket_sort(array, size);

    // Print sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }

    return 0;
}