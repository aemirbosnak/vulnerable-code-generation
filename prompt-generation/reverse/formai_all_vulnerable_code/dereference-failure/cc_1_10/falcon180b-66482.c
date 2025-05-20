//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_SEQUENCE_LENGTH 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

Sequence *sequences[MAX_THREADS];
pthread_t threads[MAX_THREADS];
int num_threads;

void *run(void *arg) {
    int i;
    Sequence *seq = arg;

    for (i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }

    printf("\n");

    return NULL;
}

int main() {
    int i;
    char input[MAX_SEQUENCE_LENGTH];

    printf("Enter the number of sequences: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter sequence %d: ", i+1);
        scanf("%s", input);

        sequences[i] = malloc(sizeof(Sequence));
        sequences[i]->length = strlen(input);
        strcpy(sequences[i]->sequence, input);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, run, sequences[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}