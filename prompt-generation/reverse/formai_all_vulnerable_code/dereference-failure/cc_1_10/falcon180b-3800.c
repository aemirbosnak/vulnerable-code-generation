//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define STACK_SIZE 1024

typedef struct thread_data {
    int id;
    void (*function)(void *data);
    void *data;
} ThreadData;

pthread_t threads[MAX_THREADS];
int thread_count = 0;

void *thread_function(void *data) {
    ThreadData *thread_data = data;
    thread_data->function(thread_data->data);
    pthread_exit(0);
}

int create_thread(void (*function)(void *data), void *data) {
    if(thread_count >= MAX_THREADS) {
        printf("Maximum number of threads reached\n");
        return -1;
    }

    ThreadData *thread_data = malloc(sizeof(ThreadData));
    if(thread_data == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    thread_data->id = thread_count;
    thread_data->function = function;
    thread_data->data = data;

    int ret = pthread_create(&threads[thread_count], NULL, thread_function, thread_data);
    if(ret!= 0) {
        printf("Failed to create thread\n");
        free(thread_data);
        return -1;
    }

    thread_count++;
    return thread_data->id;
}

void join_threads() {
    for(int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    srand(time(NULL));

    int thread_ids[MAX_THREADS];
    int num_threads = rand() % MAX_THREADS + 1;

    for(int i = 0; i < num_threads; i++) {
        thread_ids[i] = create_thread(thread_function, NULL);
    }

    for(int i = 0; i < num_threads; i++) {
        sleep(rand() % 5);
        printf("Thread %d started\n", thread_ids[i]);
    }

    join_threads();

    return 0;
}