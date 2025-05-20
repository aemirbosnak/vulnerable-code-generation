//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_BATCH_SIZE 100

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int count;
} Batch;

Batch *create_batch(int size) {
    Batch *batch = (Batch *) malloc(sizeof(Batch));
    batch->sequences = (Sequence *) malloc(size * sizeof(Sequence));
    batch->count = 0;
    return batch;
}

void add_sequence(Batch *batch, char *sequence) {
    Sequence *seq = &batch->sequences[batch->count];
    strncpy(seq->sequence, sequence, MAX_SEQUENCE_LENGTH);
    seq->length = strlen(sequence);
    batch->count++;
}

void print_batch(Batch *batch) {
    for (int i = 0; i < batch->count; i++) {
        printf("Sequence %d: %s (%d bases)\n", i + 1, batch->sequences[i].sequence, batch->sequences[i].length);
    }
}

void destroy_batch(Batch *batch) {
    free(batch->sequences);
    free(batch);
}

int main() {
    srand(time(NULL));

    int batch_size = rand() % MAX_BATCH_SIZE + 1;
    Batch *batch = create_batch(batch_size);

    for (int i = 0; i < batch_size; i++) {
        char sequence[MAX_SEQUENCE_LENGTH];
        int length = rand() % MAX_SEQUENCE_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            sequence[j] = rand() % 4 + 'A';
        }
        sequence[length] = '\0';
        add_sequence(batch, sequence);
    }

    print_batch(batch);

    destroy_batch(batch);

    return 0;
}