//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_THREADS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int num_threads = 0;

void* thread_function(void* arg) {
    pthread_mutex_lock(&mutex);
    num_threads++;
    printf("Thread %d started.\n", *(int*)arg);
    printf("Total number of active threads: %d\n", num_threads);
    pthread_mutex_unlock(&mutex);
    
    // perform some system administration tasks
    // for the purpose of this example, we will simulate some tasks
    // by sleeping for a random amount of time
    srand(time(NULL));
    int sleep_time = rand() % 5;
    printf("Thread %d performing system administration tasks for %d seconds.\n", *(int*)arg, sleep_time);
    sleep(sleep_time);
    
    pthread_mutex_lock(&mutex);
    num_threads--;
    printf("Thread %d completed.\n", *(int*)arg);
    printf("Total number of active threads: %d\n", num_threads);
    pthread_mutex_unlock(&mutex);
    
    free(arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i;
    for (i = 0; i < MAX_THREADS; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)thread_num);
    }
    
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}