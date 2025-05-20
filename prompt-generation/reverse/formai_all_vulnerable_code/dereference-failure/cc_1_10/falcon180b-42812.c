//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// data structure to hold thread information
typedef struct {
    pthread_t thread_id;
    int thread_num;
} thread_info_t;

// function prototypes
void *thread_func(void *arg);
void create_threads(int num_threads);

int main(int argc, char **argv) {
    int num_threads = 10;

    // create threads
    create_threads(num_threads);

    return 0;
}

// function to create threads
void create_threads(int num_threads) {
    thread_info_t *thread_info = malloc(num_threads * sizeof(thread_info_t));

    // initialize thread information
    for (int i = 0; i < num_threads; i++) {
        thread_info[i].thread_num = i + 1;
    }

    // create threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&thread_info[i].thread_id, NULL, thread_func, &thread_info[i]);
    }

    // wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_info[i].thread_id, NULL);
    }

    free(thread_info);
}

// thread function
void *thread_func(void *arg) {
    thread_info_t *thread_info = arg;
    int thread_num = thread_info->thread_num;

    // do some work
    for (int i = 0; i < 10; i++) {
        printf("Thread %d is working...\n", thread_num);
        sleep(1);
    }

    return NULL;
}