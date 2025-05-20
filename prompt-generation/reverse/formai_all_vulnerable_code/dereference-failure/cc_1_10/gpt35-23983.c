//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Define a structure to hold thread information */
typedef struct {
    int thread_id;
    int num_threads;
    int *array;
    int array_size;
    int sum;
} thread_info;

/* Define a function that each thread will execute */
void *thread_sum(void *arg) {
    thread_info *info = (thread_info*) arg;
    int thread_id = info->thread_id;
    int num_threads = info->num_threads;
    int *array = info->array;
    int array_size = info->array_size;

    /* Calculate thread's portion of the sum */
    int sum = 0;
    for (int i = thread_id; i < array_size; i += num_threads) {
        sum += array[i];
    }

    /* Store thread's portion of the sum into the info structure */
    info->sum = sum;

    /* Exit the thread */
    pthread_exit(NULL);
}

/* Define a function that sums an array using multiple threads */
int threaded_sum(int *array, int array_size, int num_threads) {
    /* Allocate memory for thread_info structures */
    thread_info *thread_infos = (thread_info*) malloc(num_threads * sizeof(thread_info));

    /* Create threads */
    pthread_t *threads = (pthread_t*) malloc(num_threads * sizeof(pthread_t));
    for (int i = 0; i < num_threads; i++) {
        thread_infos[i].thread_id = i;
        thread_infos[i].num_threads = num_threads;
        thread_infos[i].array = array;
        thread_infos[i].array_size = array_size;
        thread_infos[i].sum = 0;

        pthread_create(&threads[i], NULL, thread_sum, (void*) &thread_infos[i]);
    }

    /* Wait for threads to finish */
    int sum = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        sum += thread_infos[i].sum;
    }

    /* Free memory */
    free(thread_infos);
    free(threads);

    return sum;
}

/* Main function */
int main() {
    /* Create array */
    int array_size = 10000000;
    int *array = (int*) malloc(array_size * sizeof(int));
    for (int i = 0; i < array_size; i++) {
        array[i] = i + 1;
    }

    /* Sum array */
    int num_threads = 4;
    int sum = threaded_sum(array, array_size, num_threads);
    printf("Sum: %d\n", sum);

    /* Free memory */
    free(array);

    return 0;
}