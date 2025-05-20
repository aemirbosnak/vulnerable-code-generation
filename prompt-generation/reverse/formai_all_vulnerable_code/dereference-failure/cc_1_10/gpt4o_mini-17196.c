//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_THREADS 5
#define MAX_FIB 45  // Maximum Fibonacci number to calculate

pthread_mutex_t lock;
long long fibonacci[MAX_FIB + 1];

typedef struct {
    int start;
    int end;
} ThreadData;

void* calculate_fibonacci(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int start = data->start;
    int end = data->end;

    for (int i = start; i <= end; i++) {
        if (i == 0) {
            fibonacci[i] = 0;
        } else if (i == 1) {
            fibonacci[i] = 1;
        } else {
            pthread_mutex_lock(&lock);
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
            pthread_mutex_unlock(&lock);
        }
        usleep(100);  // Simulate some work
    }
    
    free(data);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&lock, NULL);
    
    int range = MAX_FIB / MAX_THREADS;  
    for (int i = 0; i < MAX_THREADS; i++) {
        ThreadData* data = (ThreadData*)malloc(sizeof(ThreadData));
        data->start = i * range;
        data->end = (i == MAX_THREADS - 1) ? MAX_FIB : (i + 1) * range - 1;

        if (pthread_create(&threads[i], NULL, calculate_fibonacci, (void*)data) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Fibonacci series up to %d:\n", MAX_FIB);
    for (int i = 0; i <= MAX_FIB; i++) {
        printf("F(%d) = %lld\n", i, fibonacci[i]);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}