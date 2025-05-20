//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define BUCKET_SIZE 100

int *create_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
    return arr;
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int **buckets = (int **)malloc(BUCKET_SIZE * sizeof(int *));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / (MAX_SIZE / BUCKET_SIZE);
        buckets[bucket_index][i % BUCKET_SIZE] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < size / BUCKET_SIZE; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    srand(time(NULL));

    int size = MAX_SIZE;
    int *arr = create_array(size);
    print_array(arr, size);

    bucket_sort(arr, size);
    print_array(arr, size);

    free(arr);
    return 0;
}