//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define MAX and MIN to set the range of the numbers that will be sorted
#define MAX 1000
#define MIN 0

// Define the bucket size and number of buckets
#define BUCKET_SIZE 10
#define BUCKET_NUM ((MAX - MIN) / BUCKET_SIZE + 1)

// Function to generate a random array of size "size"
int *generate_array(int size)
{
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % (MAX + 1 - MIN) + MIN;
    return arr;
}

// Function to print an array
void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform bucket sort
void bucket_sort(int *arr, int size)
{
    // Create an array of buckets
    int buckets[BUCKET_NUM][BUCKET_SIZE] = {0};

    // Place each element of the array into the correct bucket
    for (int i = 0; i < size; i++)
    {
        int bucket_index = (arr[i] - MIN) / BUCKET_SIZE;
        for (int j = 0; j < BUCKET_SIZE; j++)
        {
            if (buckets[bucket_index][j] == 0)
            {
                buckets[bucket_index][j] = arr[i];
                break;
            }
        }
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 1; j < BUCKET_SIZE; j++)
        {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < BUCKET_SIZE; j++)
        {
            if (buckets[i][j] != 0)
            {
                arr[index] = buckets[i][j];
                index++;
            }
        }
    }
}

// Main function to test the implementation
int main()
{
    // Generate a random array of 100 integers
    int *arr = generate_array(100);

    // Print the unsorted array
    printf("Unsorted array:\n");
    print_array(arr, 100);

    // Sort the array using bucket sort
    bucket_sort(arr, 100);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, 100);

    // Free the memory allocated for the array
    free(arr);

    return 0;
}