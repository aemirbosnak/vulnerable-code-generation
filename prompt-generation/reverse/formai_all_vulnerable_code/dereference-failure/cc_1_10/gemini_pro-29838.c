//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: lively
// Let's create a sprightly bucket sort that's brimming with zest!

#include <stdio.h>
#include <stdlib.h>

// Our trusty bucket brigade, ready to sort the masses!
typedef struct {
    int capacity;
    int* items;
    int size;
} Bucket;

// Let's conjure up a new bucket, ready for the sorting soiree!
Bucket* createBucket(int capacity) {
    Bucket* bucket = malloc(sizeof(Bucket));
    bucket->capacity = capacity;
    bucket->size = 0;
    bucket->items = malloc(sizeof(int) * bucket->capacity);
    return bucket;
}

// Insert an item into the eager bucket, but only if there's room!
void insertIntoBucket(Bucket* bucket, int item) {
    if (bucket->size == bucket->capacity) {
        printf("Oh dear, the bucket's overflowing!\n");
        return;
    }
    bucket->items[bucket->size++] = item;
}

// Let's sort the items within each bucket, keeping it neat and tidy!
void sortBucket(Bucket* bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = i + 1; j < bucket->size; j++) {
            if (bucket->items[i] > bucket->items[j]) {
                int temp = bucket->items[i];
                bucket->items[i] = bucket->items[j];
                bucket->items[j] = temp;
            }
        }
    }
}

// Now, let's pour the sorted buckets back into a single, sparkling array!
int* bucketSort(int* array, int size) {
    
    // Discover the maximum element, our beacon of maximum value!
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    
    // Create an army of buckets, ready for their sorting duties!
    int numBuckets = max + 1;
    Bucket** buckets = malloc(sizeof(Bucket*) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = createBucket(size);
    }

    // Distribute the array's elements into their designated buckets.
    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets[array[i]], array[i]);
    }
    
    // Sort the items within each bucket, ensuring internal harmony!
    for (int i = 0; i < numBuckets; i++) {
        sortBucket(buckets[i]);
    }

    // Gather the sorted buckets into a single, gleaming array.
    int* sortedArray = malloc(sizeof(int) * size);
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            sortedArray[index++] = buckets[i]->items[j];
        }
    }

    // Free the buckets, their duty now complete!
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]->items);
        free(buckets[i]);
    }
    free(buckets);

    // Behold, the sorted array, radiant with order and grace!
    return sortedArray;
}

// Let's test our sprightly bucket sort, shall we?
int main() {
    // Create an array of numbers, brimming with disorder!
    int array[] = {5, 3, 1, 2, 4};
    int size = sizeof(array) / sizeof(int);

    // Perform the magical bucket sort, transforming chaos into order!
    int* sortedArray = bucketSort(array, size);

    // Display the sorted array, a testament to our sorting prowess!
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");

    // Free the memory allocated for the sorted array, bidding it farewell!
    free(sortedArray);

    return 0;
}