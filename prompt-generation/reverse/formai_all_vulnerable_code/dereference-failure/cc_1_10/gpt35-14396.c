//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define a structure for each bucket in the array
struct bucket
{
    int count;
    int* value;
};

void bucket_sort(int* array, int size)
{
    // Find the minimum and maximum values in the array
    int min_val = array[0];
    int max_val = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min_val) {
            min_val = array[i];
        }
        else if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    // Calculate the range and size of the buckets
    int range = max_val - min_val + 1;
    int num_buckets = 10;
    int bucket_size = (range + num_buckets - 1) / num_buckets;

    // Create an array of buckets and initialize them
    struct bucket* buckets = malloc(sizeof(struct bucket) * num_buckets);
    for (int i = 0; i < num_buckets; i++) {
        buckets[i].count = 0;
        buckets[i].value = malloc(sizeof(int) * bucket_size);
    }

    // Place each value in its corresponding bucket
    for (int i = 0; i < size; i++) {
        int bucket_index = (array[i] - min_val) / bucket_size;
        if (bucket_index < 0) {
            bucket_index = 0; // In case the smallest element is negative
        }
        if (bucket_index >= num_buckets) {
            bucket_index = num_buckets - 1; // In case the largest element is at or above the range
        }
        buckets[bucket_index].value[buckets[bucket_index].count++] = array[i];
    }

    // Sort each bucket using a simple insertion sort
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 1; j < buckets[i].count; j++) {
            int temp = buckets[i].value[j];
            int k = j - 1;
            while (k >= 0 && buckets[i].value[k] > temp) {
                buckets[i].value[k + 1] = buckets[i].value[k];
                k--;
            }
            buckets[i].value[k + 1] = temp;
        }
    }

    // Concatenate the sorted buckets back into the original array
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].value[j];
        }
        free(buckets[i].value);
    }

    // Free the bucket array
    free(buckets);
}

int main()
{
    // Generate a random array of integers
    int size = 20;
    int* array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucket_sort(array, size);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the array
    free(array);

    return 0;
}