//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int num_threads = 5;
int thread_count = 0;
int *thread_ids;
int *thread_stacks;
int *thread_priority;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* thread_function(void *args) {
    int id = *(int*)args;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (thread_count == num_threads) {
            pthread_cond_signal(&cond);
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        if (thread_priority[id] == 1) {
            printf("Thread %d is executing\n", id);
            thread_count++;
            pthread_mutex_unlock(&mutex);
            return NULL;
        }
        pthread_mutex_unlock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        thread_priority[id] = 1;
        pthread_mutex_lock(&mutex);
    }
}

int main() {
    pthread_t threads[num_threads];
    int i;
    for (i = 0; i < num_threads; i++) {
        thread_ids = (int*)malloc(sizeof(int));
        *thread_ids = i;
        thread_stacks = (int*)malloc(sizeof(int));
        thread_priority = (int*)malloc(sizeof(int));
        pthread_create(&threads[i], NULL, thread_function, (void*)thread_ids);
        pthread_detach(threads[i]);
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    free(thread_ids);
    free(thread_stacks);
    free(thread_priority);
    return 0;
}