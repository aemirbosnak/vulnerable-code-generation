//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 50

int items[MAX_ITEMS] = {8, 9, 2, 4, 19, 3, 7, 15, 11, 1, 10, 5, 14, 6, 18, 13, 12, 20, 17, 16, 23, 24, 25, 26, 21, 22, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
int n = MAX_ITEMS;
int thread_count;
int sum = 0;
pthread_mutex_t mutex;

void *SumParts(void* rank) {
    long my_rank = (long) rank;
    int part_size = n/thread_count;
    int my_first_i = my_rank * part_size;
    int my_last_i = (my_rank+1) * part_size - 1;

    int local_sum = 0;
    for (int i = my_first_i; i <= my_last_i; i++) {
        local_sum += items[i];
    }

    printf("Thread %ld local sum = %d\n", my_rank, local_sum);

    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main(int argc, char* argv[]) {
    pthread_t* thread_handles;

    thread_count = strtol(argv[1], NULL, 10);
    thread_handles = malloc(thread_count * sizeof(pthread_t));

    pthread_mutex_init(&mutex, NULL);

    for (int thread_i = 0; thread_i < thread_count; thread_i++) {
        pthread_create(&thread_handles[thread_i], NULL, SumParts, (void*) thread_i);
    }

    for (int thread_i = 0; thread_i < thread_count; thread_i++) {
        pthread_join(thread_handles[thread_i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    printf("Total sum = %d\n", sum);

    return 0;
}