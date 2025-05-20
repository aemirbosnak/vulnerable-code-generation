//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VALUE 100
#define BUCKET_COUNT 10

// A surreal fish that swims in the swirling waters of buckets
typedef struct Fish {
    int value;
    struct Fish* next;
} Fish;

// The bucket where fishes frolic and play
typedef struct Bucket {
    Fish* head;
} Bucket;

// A dance of buckets that spins our numbers into place
void initializeBuckets(Bucket* buckets) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].head = NULL;
    }
}

// A magical journey as fish swims to their destined bucket
int getBucketIndex(int value) {
    return value / (MAX_VALUE / BUCKET_COUNT);
}

// The ever-evolving song that resides in the fish's fin
void insertFish(Bucket* bucket, int value) {
    Fish* newFish = (Fish*)malloc(sizeof(Fish));
    newFish->value = value;
    newFish->next = NULL;

    if (bucket->head == NULL) {
        bucket->head = newFish;
    } else {
        Fish* current = bucket->head;
        Fish* previous = NULL;
        while (current != NULL && current->value < value) {
            previous = current;
            current = current->next;
        }
        if (previous == NULL) {
            newFish->next = bucket->head;
            bucket->head = newFish;
        } else {
            newFish->next = current;
            previous->next = newFish;
        }
    }
}

// The mystical ritual where fish are released back to the ocean of numbers
void collectFishes(Bucket* buckets, int* array, int* size) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Fish* current = buckets[i].head;
        while (current != NULL) {
            array[(*size)++] = current->value;
            Fish* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// The grand symphony of bucket sorting
void bucketSort(int* array, int length) {
    Bucket buckets[BUCKET_COUNT];
    initializeBuckets(buckets);

    // Plunge the fishes into their enchanting buckets
    for (int i = 0; i < length; i++) {
        int index = getBucketIndex(array[i]);
        insertFish(&buckets[index], array[i]);
    }

    // Release the enchanted fishes into the swirling waters,
    // Creating an ordered stream that cascades down the numbers
    int index = 0;
    int size = 0;
    collectFishes(buckets, array, &size);
}

// An absurdity captured in an explosion of colors, a glimpse into the chaotic scene
int main() {
    srand((unsigned int)time(NULL));
    int length = rand() % 20 + 10; // Size between 10 and 30
    int* array = (int*)malloc(length * sizeof(int));

    // Splashes of colors as we create our chaotic array
    printf("Original chaotic array: ");
    for (int i = 0; i < length; i++) {
        array[i] = rand() % MAX_VALUE;
        printf("%d ", array[i]);
    }
    printf("\n");

    // The initiation of the bucket sort ceremony
    bucketSort(array, length);

    // Behold, as the hues meld together into a harmonized aurora of order
    printf("Sorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Casting away the shadows of memory
    free(array);
    return 0;
}