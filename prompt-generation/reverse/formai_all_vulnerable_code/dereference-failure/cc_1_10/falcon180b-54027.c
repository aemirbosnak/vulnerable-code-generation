//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 1000
#define BUCKET_SIZE 10

int *array;
int size;

void initialize() {
    srand(time(NULL));
    size = rand() % MAX_SIZE + 1;
    array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
}

void print_array() {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bucket_sort(int *array, int size) {
    int *buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / (MAX_VALUE / BUCKET_SIZE);
        buckets[bucket_index] = (int *)realloc(buckets[bucket_index], (size + 1) * sizeof(int));
        buckets[bucket_index][size] = array[i];
        size++;
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < size; j++) {
            array[index] = buckets[i][j];
            index++;
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    initialize();
    print_array();
    bucket_sort(array, size);
    print_array();

    return 0;
}