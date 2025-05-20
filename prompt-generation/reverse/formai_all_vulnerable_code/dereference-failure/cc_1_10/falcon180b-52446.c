//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 20
#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    int id;
    char *sequence;
    int length;
} Sequence;

Sequence *sequences;
int num_sequences;

void *thread_func(void *arg) {
    int i;
    int start = *(int *) arg;
    int end = start + MAX_SEQUENCE_LENGTH / num_sequences;

    for (i = start; i < end; i++) {
        sequences[i / MAX_SEQUENCE_LENGTH].sequence[i % MAX_SEQUENCE_LENGTH] = 'A' + rand() % 4;
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    srand(time(NULL));

    num_sequences = MAX_SEQUENCE_LENGTH / MAX_SEQUENCE_LENGTH;
    sequences = malloc(sizeof(Sequence) * num_sequences);

    for (i = 0; i < num_sequences; i++) {
        sequences[i].id = i;
        sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH);
        sequences[i].length = MAX_SEQUENCE_LENGTH;
        memset(sequences[i].sequence, 'N', MAX_SEQUENCE_LENGTH);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        ids[i] = i * MAX_SEQUENCE_LENGTH / MAX_THREADS;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i, sequences[i].sequence);
        free(sequences[i].sequence);
    }

    free(sequences);

    return 0;
}