//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

#define MAX_THREADS 4
#define MAX_SEQUENCE_LENGTH 10000000

char *sequence = NULL;
size_t sequence_length = 0;

pthread_mutex_t sequence_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t sequence_cond = PTHREAD_COND_INITIALIZER;

void *sequence_generator(void *arg) {
    srand(time(NULL));

    char *sequence_part = malloc(MAX_SEQUENCE_LENGTH);
    memset(sequence_part, 'A', MAX_SEQUENCE_LENGTH);

    pthread_mutex_lock(&sequence_mutex);
    strncat(sequence, sequence_part, MAX_SEQUENCE_LENGTH);
    sequence_length += MAX_SEQUENCE_LENGTH;
    pthread_mutex_unlock(&sequence_mutex);

    pthread_cond_broadcast(&sequence_cond);

    free(sequence_part);
    return NULL;
}

void *sequence_consumer(void *arg) {
    char *buffer = malloc(MAX_SEQUENCE_LENGTH);

    while (true) {
        pthread_mutex_lock(&sequence_mutex);
        while (sequence_length == 0) {
            pthread_cond_wait(&sequence_cond, &sequence_mutex);
        }

        strncpy(buffer, sequence, MAX_SEQUENCE_LENGTH);
        pthread_mutex_unlock(&sequence_mutex);

        printf("%s\n", buffer);

        free(buffer);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, sequence_generator, NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, sequence_consumer, NULL);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}