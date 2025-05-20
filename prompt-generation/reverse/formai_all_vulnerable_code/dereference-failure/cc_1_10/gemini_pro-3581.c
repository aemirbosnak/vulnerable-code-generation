//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int tid;
    int* arr;
} thread_args;

void* thread_func(void* args) {
    thread_args* t_args = (thread_args*)args;
    printf("Thread %d: Hello from the thread world!\n", t_args->tid);

    // Do some work here
    for (int i = 0; i < 10; i++) {
        t_args->arr[i] = t_args->tid * 10 + i;
    }

    printf("Thread %d: Done!\n", t_args->tid);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].tid = i;
        args[i].arr = (int*)malloc(10 * sizeof(int));
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the array
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Array from thread %d:\n", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", args[i].arr[j]);
        }
        printf("\n");
    }

    // Free the memory
    for (int i = 0; i < NUM_THREADS; i++) {
        free(args[i].arr);
    }

    return 0;
}