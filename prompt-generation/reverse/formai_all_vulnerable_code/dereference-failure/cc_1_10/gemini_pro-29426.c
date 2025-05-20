//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Custom data type for holding elements in the bucket
typedef struct BucketElement {
    int value;
    struct BucketElement *next;
} BucketElement;

// Custom data type for representing a bucket
typedef struct Bucket {
    BucketElement *head;
    BucketElement *tail;
} Bucket;

// Function to create a new bucket
Bucket *createBucket() {
    Bucket *bucket = malloc(sizeof(Bucket));
    bucket->head = NULL;
    bucket->tail = NULL;
    return bucket;
}

// Function to insert an element into a bucket
void insertIntoBucket(Bucket *bucket, int value) {
    BucketElement *newElement = malloc(sizeof(BucketElement));
    newElement->value = value;
    newElement->next = NULL;

    // If the bucket is empty, set the head and tail to the new element
    if (bucket->head == NULL) {
        bucket->head = newElement;
        bucket->tail = newElement;
    } else {
        // Otherwise, add the new element to the tail of the bucket
        bucket->tail->next = newElement;
        bucket->tail = newElement;
    }
}

// Function to sort an array using bucket sort
void bucketSort(int *array, int size) {
    // Create an array of buckets
    Bucket *buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i] = createBucket();
    }

    // Distribute the elements of the array into the buckets
    for (int i = 0; i < size; i++) {
        insertIntoBucket(buckets[array[i] % 10], array[i]);
    }

    // Merge the buckets back into the array
    int index = 0;
    for (int i = 0; i < 10; i++) {
        BucketElement *current = buckets[i]->head;
        while (current != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
    }

    // Free the buckets
    for (int i = 0; i < 10; i++) {
        free(buckets[i]);
    }
}

// Main function
int main() {
    // Initialize an array of integers
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(array) / sizeof(array[0]);

    // Sort the array using bucket sort
    bucketSort(array, size);

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}