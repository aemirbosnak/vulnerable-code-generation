//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define BUCKET_SIZE 10

typedef struct Bucket {
    int count;
    int *array;
} Bucket;

void initBucket(Bucket *b) {
    b->count = 0;
    b->array = (int *)malloc(MAX_SIZE * sizeof(int));
}

void destroyBucket(Bucket *b) {
    free(b->array);
    b->count = 0;
}

void insertIntoBucket(Bucket *b, int value) {
    b->array[b->count++] = value;
}

void sortBucket(Bucket *b) {
    for (int i = 0; i < b->count - 1; i++) {
        for (int j = i + 1; j < b->count; j++) {
            if (b->array[i] > b->array[j]) {
                int temp = b->array[i];
                b->array[i] = b->array[j];
                b->array[j] = temp;
            }
        }
    }
}

void bucketSort(int *array, int n) {
    Bucket buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        initBucket(&buckets[i]);
    }
    
    // Determine the range of input values
    int maxValue = array[0];
    int minValue = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxValue) maxValue = array[i];
        if (array[i] < minValue) minValue = array[i];
    }
    
    // Calculate the range and assign values to buckets
    float range = (float)(maxValue - minValue + 1) / BUCKET_SIZE;
    for (int i = 0; i < n; i++) {
        int index = (array[i] - minValue) / range;
        if (index >= BUCKET_SIZE) index = BUCKET_SIZE - 1; // Bound check
        insertIntoBucket(&buckets[index], array[i]);
    }

    // Sort each bucket and merge them back into the original array
    int arrayIndex = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        sortBucket(&buckets[i]);
        for (int j = 0; j < buckets[i].count; j++) {
            array[arrayIndex++] = buckets[i].array[j];
        }
        destroyBucket(&buckets[i]);
    }
}

int main() {
    printf("Cyberpunk Bucket Sort\n");
    printf("Loading the neon lights...\n");

    // Randomly generate data simulating a cyberpunk city
    int n = 100; // Size of the data
    int *data = (int *)malloc(n * sizeof(int));

    printf("Generating street data...\n");
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 1000; // Values from 0 to 999
        printf("Street cloud %d: %d\n", i + 1, data[i]); // Simulated street data
    }

    printf("Sorting the data...\n");
    bucketSort(data, n);

    printf("Data Sorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    free(data);
    return 0;
}