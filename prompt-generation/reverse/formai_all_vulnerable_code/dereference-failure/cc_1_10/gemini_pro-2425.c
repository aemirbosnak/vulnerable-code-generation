//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10
#define MAX_SIZE 100

typedef struct bucket {
    int size;
    int *data;
} bucket;

bucket buckets[MAX_BUCKETS];

void add_to_bucket(int value) {
    int bucket_index = value / 10; // Assuming we have 10 buckets, each of size 10
    if (bucket_index >= MAX_BUCKETS) {
        printf("Error: Bucket index %d out of range (0-%d)\n", bucket_index, MAX_BUCKETS - 1);
        return;
    }
    if (buckets[bucket_index].size >= MAX_SIZE) {
        printf("Error: Bucket %d is full (max size %d)\n", bucket_index, MAX_SIZE);
        return;
    }
    buckets[bucket_index].data[buckets[bucket_index].size++] = value;
}

void sort_bucket(bucket *b) {
    int i, j;
    for (i = 0; i < b->size; i++) {
        for (j = i + 1; j < b->size; j++) {
            if (b->data[i] > b->data[j]) {
                int temp = b->data[i];
                b->data[i] = b->data[j];
                b->data[j] = temp;
            }
        }
    }
}

void print_buckets() {
    int i, j;
    for (i = 0; i < MAX_BUCKETS; i++) {
        printf("Bucket %d: ", i);
        for (j = 0; j < buckets[i].size; j++) {
            printf("%d ", buckets[i].data[j]);
        }
        printf("\n");
    }
}

int main() {
    int i, arr[100];

    // Create buckets
    for (i = 0; i < MAX_BUCKETS; i++) {
        buckets[i].size = 0;
        buckets[i].data = malloc(sizeof(int) * MAX_SIZE);
    }

    // Randomly generate 100 numbers and add them to buckets
    for (i = 0; i < 100; i++) {
        arr[i] = rand() % 100;
        add_to_bucket(arr[i]);
    }

    // Sort each bucket
    for (i = 0; i < MAX_BUCKETS; i++) {
        sort_bucket(&buckets[i]);
    }

    // Print the sorted buckets
    print_buckets();

    // Don't forget to free the memory allocated for the buckets
    for (i = 0; i < MAX_BUCKETS; i++) {
        free(buckets[i].data);
    }

    return 0;
}