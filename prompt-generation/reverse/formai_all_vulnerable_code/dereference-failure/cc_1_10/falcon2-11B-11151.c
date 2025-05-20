//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* data;
int length;
pthread_mutex_t lock;

void* read(void* arg) {
    int threadId = *((int*) arg);
    srand(time(NULL));

    int start = rand() % length;
    int end = rand() % length;

    for (int i = start; i < end; i++) {
        data[i] = rand() % 10;
    }

    pthread_mutex_lock(&lock);
    data[threadId] = 0;
    pthread_mutex_unlock(&lock);

    return NULL;
}

void* write(void* arg) {
    int threadId = *((int*) arg);
    pthread_mutex_lock(&lock);
    int result = data[threadId];
    pthread_mutex_unlock(&lock);

    printf("Thread %d: Result is %d\n", threadId, result);

    return NULL;
}

int main() {
    int nThreads = 2;
    int nSamples = 100;
    int sampleSize = 100;

    data = (int*) malloc(nSamples * sizeof(int));
    length = nSamples;

    pthread_t threads[nThreads];
    int thread_id[nThreads];

    for (int i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, read, &thread_id[i]);
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_create(&threads[i], NULL, write, &thread_id[i]);
    }

    for (int i = 0; i < nThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(data);

    return 0;
}