//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 1000000

typedef struct ThreadData {
    int *array;
    int start_index;
    int end_index;
} ThreadData;

void *sort_array(void *data) {
    ThreadData *thread_data = (ThreadData *) data;
    int *array = thread_data->array;
    int start = thread_data->start_index;
    int end = thread_data->end_index;
    int temp;

    for (int i = start; i < end; i++) {
        for (int j = i + 1; j < end; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    pthread_exit(NULL);
}

int *generate_random_array(int size) {
    int *array = malloc(sizeof(int) * size);

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % ARRAY_SIZE;
    }

    return array;
}

void print_array(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
}

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int *array = generate_random_array(ARRAY_SIZE);
    int chunk_size = ARRAY_SIZE / NUM_THREADS;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].array = array;
        thread_data[i].start_index = i * chunk_size;
        thread_data[i].end_index = (i + 1) * chunk_size;

        int result = pthread_create(&threads[i], NULL, sort_array, &thread_data[i]);
        if (result != 0) {
            printf("Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        int result = pthread_join(threads[i], NULL);
        if (result != 0) {
            printf("Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Merge sorted sub-arrays
    int *sorted_array = malloc(sizeof(int) * ARRAY_SIZE);
    int indexes[NUM_THREADS] = {0};
    int min_index, min_value;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        min_value = ARRAY_SIZE + 1;

        for (int j = 0; j < NUM_THREADS; j++) {
            if (indexes[j] < (j + 1) * chunk_size && array[indexes[j]] < min_value) {
                min_index = j;
                min_value = array[indexes[j]];
            }
        }

        sorted_array[i] = min_value;
        indexes[min_index]++;
    }

    print_array(sorted_array, ARRAY_SIZE);

    free(array);
    free(sorted_array);

    pthread_exit(NULL);
}