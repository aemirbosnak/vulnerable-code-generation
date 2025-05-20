//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10
#define MAX_STEPS 10000

pthread_t threads[MAX_THREADS];

sem_t mutex;
sem_t step_sem;

int step_count = 0;
int thread_count = 0;

void *runner(void *arg) {
    int id = *(int *) arg;

    printf("Thread %d starting\n", id);

    while (step_count < MAX_STEPS) {
        sem_wait(&step_sem);
        step_count++;
        printf("Thread %d took step %d\n", id, step_count);
        sem_post(&mutex);
    }

    printf("Thread %d finished\n", id);

    return NULL;
}

int main() {
    int i;
    int *tids;

    sem_init(&mutex, 0, 1);
    sem_init(&step_sem, 0, 0);

    tids = (int *) malloc(MAX_THREADS * sizeof(int));

    for (i = 0; i < MAX_THREADS; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, runner, &tids[i]);
        thread_count++;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    free(tids);

    return 0;
}