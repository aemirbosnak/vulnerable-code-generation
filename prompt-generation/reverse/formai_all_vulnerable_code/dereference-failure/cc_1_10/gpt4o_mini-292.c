//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 250  // Maximum height (in cm) we want to consider
#define BUCKET_SIZE 10  // Size of each bucket (height range)

typedef struct Bucket {
    int *heights; // Array to hold heights
    int count;    // Number of heights in this bucket
} Bucket;

// Function to create a new bucket
Bucket* createBucket() {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->heights = (int *)malloc(BUCKET_SIZE * sizeof(int));
    bucket->count = 0;
    return bucket;
}

// Function to free the memory of the bucket
void freeBucket(Bucket *bucket) {
    free(bucket->heights);
    free(bucket);
}

// Function to perform bucket sort on heights
void bucketSort(int *heights, int n) {
    int bucketCount = MAX_HEIGHT / BUCKET_SIZE;
    Bucket **buckets = (Bucket **)malloc(bucketCount * sizeof(Bucket *));
    
    // Initialize buckets
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = createBucket();
    }

    // Distribute the heights into buckets
    for (int i = 0; i < n; i++) {
        int index = heights[i] / BUCKET_SIZE;
        if (buckets[index]->count < BUCKET_SIZE) {
            buckets[index]->heights[buckets[index]->count++] = heights[i];
        }
    }

    // Sort individual buckets and place them back into the original array
    int k = 0;
    for (int i = 0; i < bucketCount; i++) {
        // Simple insertion sort within each bucket
        for (int j = 0; j < buckets[i]->count; j++) {
            for (int l = j + 1; l < buckets[i]->count; l++) {
                if (buckets[i]->heights[l] < buckets[i]->heights[j]) {
                    int temp = buckets[i]->heights[j];
                    buckets[i]->heights[j] = buckets[i]->heights[l];
                    buckets[i]->heights[l] = temp;
                }
            }
        }

        // Place sorted bucket into the original array
        for (int j = 0; j < buckets[i]->count; j++) {
            heights[k++] = buckets[i]->heights[j];
        }
    }

    // Free the memory of the buckets
    for (int i = 0; i < bucketCount; i++) {
        freeBucket(buckets[i]);
    }
    free(buckets);
}

// Function to print the heights
void printHeights(int *heights, int n) {
    printf("Sorted Heights:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", heights[i]);
    }
    printf("\n");
}

int main() {
    int heights[] = {180, 175, 160, 165, 170, 189, 203, 210, 155, 182, 190, 145, 168, 177, 166};
    int n = sizeof(heights) / sizeof(heights[0]);

    printf("Original Heights:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", heights[i]);
    }
    printf("\n\n");

    bucketSort(heights, n);
    printHeights(heights, n);

    return 0;
}