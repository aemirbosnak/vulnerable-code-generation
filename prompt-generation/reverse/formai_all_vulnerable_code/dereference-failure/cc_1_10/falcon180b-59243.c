//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 4
#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *sequences[MAX_THREADS];

void *thread_func(void *arg) {
    int i;
    Sequence *seq = arg;
    for (i = 0; i < seq->length; i++) {
        // Simulate sequencing process
        printf("A%c", "ACGT"[(int)(rand() % 4)]);
    }
    printf("\n");
    return NULL;
}

int main() {
    int i, j;
    Sequence *seq;
    pthread_t threads[MAX_THREADS];

    // Initialize random seed
    srand(time(NULL));

    // Create sequences
    for (i = 0; i < MAX_THREADS; i++) {
        seq = malloc(sizeof(Sequence));
        seq->sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        seq->length = rand() % MAX_SEQUENCE_LENGTH;
        for (j = 0; j < seq->length; j++) {
            seq->sequence[j] = "ACGT"[(int)(rand() % 4)];
        }
        sequences[i] = seq;
    }

    // Start threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, sequences[i]);
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}