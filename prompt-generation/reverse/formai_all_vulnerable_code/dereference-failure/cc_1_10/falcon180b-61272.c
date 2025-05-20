//Falcon-180B DATASET v1.0 Category: Sorting ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_ELEMENTS 1000000
#define MIN_VALUE 0
#define MAX_VALUE 999999

int num_threads;
int elements_per_thread;
int *array;
pthread_t threads[NUM_THREADS];

void *sort_thread(void *param) {
    int start = ((int)param) * elements_per_thread;
    int end = start + elements_per_thread - 1;
    int i, j;

    for (i = start; i <= end; i++) {
        for (j = i + 1; j <= end; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    return NULL;
}

void generate_array() {
    int i;

    for (i = 0; i < MAX_ELEMENTS; i++) {
        array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }
}

int main() {
    int i;

    srand(time(NULL));
    num_threads = NUM_THREADS;
    elements_per_thread = MAX_ELEMENTS / num_threads;
    array = (int *)malloc(MAX_ELEMENTS * sizeof(int));

    generate_array();

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, sort_thread, (void *)i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Sorted array:\n");
    for (i = 0; i < MAX_ELEMENTS; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}