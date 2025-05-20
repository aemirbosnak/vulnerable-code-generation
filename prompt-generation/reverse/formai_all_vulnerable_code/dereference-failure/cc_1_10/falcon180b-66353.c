//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define NUM_BUCKETS 100
#define MIN_VALUE -10000
#define MAX_VALUE 10000

int *generate_random_array(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
    return array;
}

void bucket_sort(int *array, int size) {
    int **buckets = (int **)malloc(NUM_BUCKETS * sizeof(int *));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = (array[i] - MIN_VALUE) * NUM_BUCKETS / (MAX_VALUE - MIN_VALUE);
        buckets[bucket_index][i % NUM_BUCKETS] = array[i];
    }

    int current_index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < size / NUM_BUCKETS; j++) {
            if (buckets[i][j]!= 0) {
                array[current_index++] = buckets[i][j];
            }
        }
        for (int j = size / NUM_BUCKETS; j < size; j++) {
            if (buckets[i][j]!= 0) {
                array[current_index++] = buckets[i][j];
            }
        }
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int *array = generate_random_array(size);

    printf("Before sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    bucket_sort(array, size);

    printf("After sorting:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}