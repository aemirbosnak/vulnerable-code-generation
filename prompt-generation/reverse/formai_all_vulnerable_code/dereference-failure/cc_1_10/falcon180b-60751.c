//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 10
#define MAX_NUM 100
#define SEMAPHORE_VALUE 0

int semaphore;

void *runner(void *param) {
    int id = *(int *) param;
    int num = 0;
    int prev_num = 0;

    srand(time(NULL) + id);

    for (int i = 0; i < MAX_NUM; i++) {
        sem_wait(&semaphore);
        num = rand() % 100;
        printf("Thread %d generated number %d\n", id, num);
        prev_num = num;
        sem_post(&semaphore);

        if (i > 0 && prev_num > 0) {
            sem_wait(&semaphore);
            printf("Thread %d calculated Fibonacci number %d\n", id, prev_num + num);
            sem_post(&semaphore);
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    srand(time(NULL));

    sem_init(&semaphore, 0, SEMAPHORE_VALUE);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, runner, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&semaphore);

    return 0;
}