//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = malloc(size * sizeof(int));
    b->size = size;
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_bucket(Bucket *b, int value) {
    int i = 0;
    while (i < b->size && b->arr[i]!= value) {
        i++;
    }
    b->arr[i] = value;
}

void sort_bucket(Bucket *b) {
    int i = 0;
    while (i < b->size) {
        int j = 0;
        while (j < b->size && b->arr[j] < b->arr[i]) {
            j++;
        }
        if (j < b->size) {
            int temp = b->arr[i];
            b->arr[i] = b->arr[j];
            b->arr[j] = temp;
            i++;
        } else {
            i++;
        }
    }
}

void print_bucket(Bucket *b) {
    int i = 0;
    while (i < b->size) {
        printf("%d ", b->arr[i]);
        i++;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size = rand() % MAX_SIZE + 1;
    int *arr = malloc(size * sizeof(int));
    int i = 0;
    while (i < size) {
        arr[i] = rand() % MAX_SIZE + 1;
        i++;
    }
    printf("Before Sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Bucket *b = malloc(sizeof(Bucket));
    init_bucket(b, MAX_SIZE);
    for (i = 0; i < size; i++) {
        insert_bucket(b, arr[i]);
    }
    sort_bucket(b);
    printf("After Sorting:\n");
    for (i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
    free_bucket(b);
    free(arr);
    return 0;
}