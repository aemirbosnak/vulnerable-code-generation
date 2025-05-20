//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
// Energized Bucket Sort Implementation
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_MAX_SIZE 100

// Structure definition for a bucket
typedef struct bucket
{
    int count;
    int* values;
} Bucket;

// Function for initializing a bucket
Bucket initializeBucket()
{
    Bucket bucket;
    bucket.count = 0;
    bucket.values = (int*) malloc(sizeof(int) * ARRAY_MAX_SIZE);
    return bucket;
}

// Function for printing the sorted array
void printArray(int* array, int size)
{
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Energize the program with music
void playMusic()
{
    printf("Playing energizing music...\n");
    // code to play music
}

// Main function for bucket sort
int main()
{
    printf("Energized Bucket Sort Starting...\n");
    
    // Input array
    int array[] = {15, 23, 13, 10, 99, 48, 76, 2, 44, 38};
    int size = sizeof(array) / sizeof(int);

    // The range of values within the array
    int min = 2;
    int max = 99;

    // Determine the range of each bucket
    float range = ((float) max - min) / (ARRAY_MAX_SIZE - 1);

    // Initialize the buckets
    Bucket* buckets = (Bucket*) malloc(sizeof(Bucket) * ARRAY_MAX_SIZE);
    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        buckets[i] = initializeBucket();
    }

    // Loop through the input array and distribute the values into the appropriate bucket
    for (int i = 0; i < size; i++)
    {
        int bucketIndex = ((float) array[i] - min) / range;
        if (bucketIndex >= ARRAY_MAX_SIZE)
        {
            bucketIndex = ARRAY_MAX_SIZE - 1;
        }
        buckets[bucketIndex].values[buckets[bucketIndex].count] = array[i];
        buckets[bucketIndex].count++;
    }

    // Sort the values within each bucket
    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        for (int j = 0; j < buckets[i].count; j++)
        {
            int temp = buckets[i].values[j];
            int k = j - 1;
            while (k >= 0 && buckets[i].values[k] > temp)
            {
                buckets[i].values[k + 1] = buckets[i].values[k];
                k--;
            }
            buckets[i].values[k + 1] = temp;
        }
    }

    // Merge the sorted values from each bucket back into the input array
    int index = 0;
    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        for (int j = 0; j < buckets[i].count; j++)
        {
            array[index++] = buckets[i].values[j];
        }
    }

    // Print the sorted array and play energizing music
    printArray(array, size);
    playMusic();

    // Free the memory
    for (int i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        free(buckets[i].values);
    }
    free(buckets);

    return 0;
}