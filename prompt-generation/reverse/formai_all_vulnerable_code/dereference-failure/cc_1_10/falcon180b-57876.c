//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_RANGE 100

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void destroy_bucket(Bucket *b) {
    free(b->arr);
}

int get_index(int val, int range) {
    return val / range;
}

void insert_element(Bucket *b, int val) {
    int index = get_index(val, MAX_RANGE);
    if (b->arr[index] == -1) {
        b->arr[index] = val;
    }
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        if (b->arr[i]!= -1) {
            printf("%d ", b->arr[i]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int size = rand() % MAX_SIZE + 1;
    int range = rand() % MAX_RANGE + 1;

    Bucket *bucket = malloc(sizeof(Bucket));
    init_bucket(bucket, size);

    int *arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % range;
    }

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < size; i++) {
        insert_element(bucket, arr[i]);
    }

    printf("Bucket after inserting elements:\n");
    print_bucket(bucket);

    int *sorted_arr = malloc(size * sizeof(int));
    int j = 0;
    for (int i = 0; i < bucket->size; i++) {
        if (bucket->arr[i]!= -1) {
            for (int k = 0; k < bucket->arr[i]; k++) {
                sorted_arr[j++] = i * MAX_RANGE + k;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    destroy_bucket(bucket);
    free(arr);
    free(sorted_arr);

    return 0;
}