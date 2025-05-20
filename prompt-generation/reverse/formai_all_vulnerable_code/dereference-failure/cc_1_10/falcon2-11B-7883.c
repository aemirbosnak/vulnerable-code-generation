//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>

void* worker(void* arg)
{
    pid_t pid = *((pid_t*) arg);
    int status;
    sem_t sem;
    int i;
    int* array = (int*) malloc(sizeof(int));
    *array = 0;
    sem_init(&sem, 0, 0);
    for (i = 0; i < 100; i++) {
        printf("Thread %d: working on task %d\n", getpid(), i);
        sem_wait(&sem);
        usleep(10000);
        sem_post(&sem);
        printf("Thread %d: finished task %d\n", getpid(), i);
    }
    sem_destroy(&sem);
    return NULL;
}

int main(int argc, char* argv[])
{
    int i;
    int nthreads;
    int* array = (int*) malloc(sizeof(int));
    *array = 0;
    pthread_t* threads;
    pthread_attr_t attr;
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <number of threads>\n", argv[0]);
        exit(1);
    }
    nthreads = atoi(argv[1]);
    if (nthreads <= 0) {
        fprintf(stderr, "Invalid number of threads\n");
        exit(1);
    }
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    threads = (pthread_t*) malloc(sizeof(pthread_t) * nthreads);
    for (i = 0; i < nthreads; i++) {
        pthread_create(&threads[i], &attr, worker, &threads[i]);
    }
    for (i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    return 0;
}