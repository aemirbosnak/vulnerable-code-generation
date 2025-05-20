//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <errno.h>

sem_t mutex;
sem_t cond_var;
pthread_t tid;

void *thread1(void *arg) {
    int value = *(int *)arg;
    printf("Thread 1 started with value %d.\n", value);
    sem_wait(&mutex);
    while (value > 0) {
        printf("Thread 1: %d\n", value);
        value--;
        usleep(100000);  // Sleep for 0.1 seconds.
    }
    sem_post(&mutex);
    sem_post(&cond_var);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int value;

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return EXIT_FAILURE;
    }

    value = atoi(argv[1]);
    if (value <= 0) {
        printf("Value must be positive.\n");
        return EXIT_FAILURE;
    }

    sem_init(&mutex, 0, value == 1 ? 0 : 1);
    sem_init(&cond_var, 0, 0);
    pthread_create(&tid, NULL, thread1, &value);

    sem_wait(&cond_var);
    sem_destroy(&mutex);
    sem_destroy(&cond_var);
    pthread_join(tid, NULL);

    printf("Main thread finished.\n");
    return EXIT_SUCCESS;
}