//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>

#define ARRAY_SIZE 1000000
#define THREAD_COUNT 8

typedef struct {
    int *array;
    int start;
    int end;
} ThreadData;

void *sort_section(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int *array = data->array;
    int start = data->start;
    int end = data->end;

    // Simple Bubble Sort for demonstration purposes
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start) - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return NULL;
}

void merge(int *array, int start, int mid, int end) {
    int left_size = mid - start + 1;
    int right_size = end - mid;

    int *left = malloc(left_size * sizeof(int));
    int *right = malloc(right_size * sizeof(int));

    memcpy(left, &array[start], left_size * sizeof(int));
    memcpy(right, &array[mid + 1], right_size * sizeof(int));

    int i = 0, j = 0, k = start;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k++] = left[i++];
        } else {
            array[k++] = right[j++];
        }
    }

    while (i < left_size) {
        array[k++] = left[i++];
    }

    while (j < right_size) {
        array[k++] = right[j++];
    }

    free(left);
    free(right);
}

void merge_sort(int *array, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main() {
    srand(time(NULL));
    int *array = malloc(ARRAY_SIZE * sizeof(int));

    // Populate the array with random numbers
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000; // Numbers between 0 and 9999
    }

    pthread_t threads[THREAD_COUNT];
    ThreadData thread_data[THREAD_COUNT];
    int section_size = ARRAY_SIZE / THREAD_COUNT;

    // Multi-threaded sorting
    for (int i = 0; i < THREAD_COUNT; i++) {
        thread_data[i].array = array;
        thread_data[i].start = i * section_size;
        thread_data[i].end = (i == THREAD_COUNT - 1) ? ARRAY_SIZE : (i + 1) * section_size;
        pthread_create(&threads[i], NULL, sort_section, (void *)&thread_data[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    // Merge sorted sections
    for (int i = 1; i < THREAD_COUNT; i++) {
        merge(array, 0, (i * section_size) - 1, (i == THREAD_COUNT - 1) ? ARRAY_SIZE - 1 : (i + 1) * section_size - 1);
    }

    // Output sorted array (you may want to save this to a file if too large)
    // For demonstration, we print the first 10 sorted elements
    printf("Sorted Array (first 10 elements): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}