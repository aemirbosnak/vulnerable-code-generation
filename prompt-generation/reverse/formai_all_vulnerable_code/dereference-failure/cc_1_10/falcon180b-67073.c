//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 10
#define STACK_SIZE 1024

sem_t mutex;
sem_t print_sem;

void *thread_func(void *arg) {
    char *message = (char *) arg;
    int id = *(int *) message;

    printf("Thread %d is starting...\n", id);
    sleep(1);

    for (int i = 0; i < 5; i++) {
        sem_wait(&print_sem);
        printf("Thread %d is printing %d\n", id, i);
        sem_post(&print_sem);
        sleep(1);
    }

    printf("Thread %d is finishing...\n", id);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];
    char *messages[NUM_THREADS];

    srand(time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = rand() % 100;
        messages[i] = (char *) malloc(sizeof(int) + sizeof(char));
        *(int *) messages[i] = ids[i];
        strcat(messages[i], " is starting...\n");
    }

    sem_init(&mutex, 0, 1);
    sem_init(&print_sem, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, messages[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&print_sem);

    return 0;
}