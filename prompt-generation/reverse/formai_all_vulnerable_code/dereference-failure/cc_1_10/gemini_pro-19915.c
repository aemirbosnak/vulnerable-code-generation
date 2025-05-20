//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// A bucket can hold a bunch of numbers
typedef struct bucket {
    int *numbers;
    int size;
    int capacity;
} bucket;

// A stable sort that sorts numbers into buckets
void bucket_sort(int *numbers, int size) {
    // Create an array of buckets
    bucket *buckets = malloc(sizeof(bucket) * size);

    // Initialize all buckets
    for (int i = 0; i < size; i++) {
        buckets[i].numbers = malloc(sizeof(int) * size);
        buckets[i].size = 0;
        buckets[i].capacity = size;
    }

    // Put each number into a bucket
    for (int i = 0; i < size; i++) {
        int bucket_index = numbers[i] / size;
        bucket *bucket = &buckets[bucket_index];

        // If the bucket is full, double its capacity
        if (bucket->size >= bucket->capacity) {
            bucket->capacity *= 2;
            bucket->numbers = realloc(bucket->numbers, sizeof(int) * bucket->capacity);
        }

        // Add the number to the bucket
        bucket->numbers[bucket->size++] = numbers[i];
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < size; i++) {
        bucket *bucket = &buckets[i];

        for (int j = 1; j < bucket->size; j++) {
            int key = bucket->numbers[j];
            int k = j - 1;

            while (k >= 0 && bucket->numbers[k] > key) {
                bucket->numbers[k + 1] = bucket->numbers[k];
                k--;
            }

            bucket->numbers[k + 1] = key;
        }
    }

    // Copy the numbers back into the original array
    int index = 0;
    for (int i = 0; i < size; i++) {
        bucket *bucket = &buckets[i];

        for (int j = 0; j < bucket->size; j++) {
            numbers[index++] = bucket->numbers[j];
        }
    }

    // Free the buckets
    for (int i = 0; i < size; i++) {
        free(buckets[i].numbers);
    }
    free(buckets);
}

int main() {
    // Create an array of numbers
    int numbers[] = {3, 1, 4, 2, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Sort the numbers using bucket sort
    bucket_sort(numbers, size);

    // Print the sorted numbers
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}