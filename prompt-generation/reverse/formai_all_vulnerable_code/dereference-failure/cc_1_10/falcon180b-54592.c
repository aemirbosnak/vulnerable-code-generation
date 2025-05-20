//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 1000

int *arr;

void initialize_array() {
    arr = (int *)malloc(MAX_SIZE * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 10000;
    }
}

void print_array() {
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort() {
    int *buckets[BUCKET_SIZE];

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        int bucket_idx = arr[i] / (MAX_SIZE / BUCKET_SIZE);
        buckets[bucket_idx][bucket_idx * BUCKET_SIZE + arr[i] % (MAX_SIZE / BUCKET_SIZE)] = arr[i];
    }

    int idx = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE / BUCKET_SIZE; j++) {
            if (buckets[i][j]!= 0) {
                arr[idx++] = buckets[i][j];
            }
        }
    }
}

int main() {
    initialize_array();
    printf("Before Sorting: \n");
    print_array();
    bucket_sort();
    printf("After Sorting: \n");
    print_array();

    return 0;
}