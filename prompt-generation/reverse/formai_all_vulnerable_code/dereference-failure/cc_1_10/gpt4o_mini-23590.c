//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5
#define MAX_FIB 15  // Calculate Fibonacci up to the 15th number

pthread_mutex_t lock;

void *fibonacci(void *arg) {
    int index = *((int *)arg);
    free(arg);
    
    unsigned long long a = 0, b = 1, next;
    printf("Thread %d: Calculating Fibonacci sequence:\n", index);
    
    for (int i = 0; i <= MAX_FIB; ++i) {
        pthread_mutex_lock(&lock);
        printf("Thread %d: Fibonacci(%d) = %llu\n", index, i, a);
        pthread_mutex_unlock(&lock);
        
        next = a + b;
        a = b;
        b = next;
        usleep(100000); // Sleep for just a bit to simulate work
    }

    printf("Thread %d: Completed Fibonacci calculations!\n", index);
    return NULL;
}

int main() {
    printf("Welcome to the Fibonacci Threading Show! 🌟\n");
    
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i + 1; // ID starts from 1 for better readability
        if (pthread_create(&threads[i], NULL, fibonacci, thread_id) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            free(thread_id);
            return 1;
        }
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    
    printf("All threads completed their tasks! 🎉\n");
    return 0;
}