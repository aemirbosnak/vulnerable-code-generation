//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 100000
#define THREAD_COUNT 8

typedef struct {
    int* array;
    int start;
    int end;
} SortArgs;

void merge(int* array, int start, int mid, int end) {
    int i, j, k;
    int left_size = mid - start + 1;
    int right_size = end - mid;

    int* left = (int*)malloc(left_size * sizeof(int));
    int* right = (int*)malloc(right_size * sizeof(int));

    for (i = 0; i < left_size; i++)
        left[i] = array[start + i];
    for (j = 0; j < right_size; j++)
        right[j] = array[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = start; 

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

void* sort(void* args) {
    SortArgs* sortArgs = (SortArgs*)args;
    int* array = sortArgs->array;
    int start = sortArgs->start;
    int end = sortArgs->end;

    if (start < end) {
        int mid = (start + end) / 2;
        sortArgs->start = start;
        sortArgs->end = mid;
        sort(args);
        sortArgs->start = mid + 1;
        sortArgs->end = end;
        sort(args);
        merge(array, start, mid, end);
    }

    return NULL;
}

void benchmark_sort(int* array) {
    pthread_t threads[THREAD_COUNT];
    SortArgs sortArgs[THREAD_COUNT];

    // Split the array into chunks and create threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        sortArgs[i].array = array;
        sortArgs[i].start = (i * ARRAY_SIZE / THREAD_COUNT);
        sortArgs[i].end = ((i + 1) * ARRAY_SIZE / THREAD_COUNT) - 1;
        pthread_create(&threads[i], NULL, sort, &sortArgs[i]);
    }

    // Join the threads
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge the sorted chunks
    for (int i = 0; i < THREAD_COUNT - 1; i++) {
        merge(array, (i * ARRAY_SIZE / THREAD_COUNT), ((i + 1) * ARRAY_SIZE / THREAD_COUNT) - 1, ((i + 2) * ARRAY_SIZE / THREAD_COUNT) - 1);
    }
}

int main() {
    int* array = (int*)malloc(ARRAY_SIZE * sizeof(int));
    srand(time(NULL));

    // Fill the array with random integers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000;
    }

    clock_t start, end;
    start = clock();

    benchmark_sort(array);

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array: \n");
    for (int i = 0; i < 100; i++) { // Print just the first 100 elements
        printf("%d ", array[i]);
    }
    printf("\nTime taken to sort the array: %f seconds\n", time_taken);

    free(array);
    return 0;
}