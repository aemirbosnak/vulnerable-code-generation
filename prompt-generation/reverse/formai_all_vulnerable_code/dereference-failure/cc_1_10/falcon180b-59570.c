//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    int length;
    char *sequence;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

Read *generate_random_read(int length) {
    Read *read = malloc(sizeof(Read));
    read->length = length;
    read->sequence = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        read->sequence[i] = 'A' + rand() % 4;
    }
    read->sequence[length] = '\0';

    return read;
}

int main() {
    srand(time(NULL));

    Sequence *reference_sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    printf("Reference sequence:\n%s\n", reference_sequence->sequence);

    int num_reads = 10;
    Read **reads = malloc(sizeof(Read *) * num_reads);

    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_random_read(MAX_READ_LENGTH);
        printf("Read %d:\n%s\n", i + 1, reads[i]->sequence);
    }

    free(reference_sequence->sequence);
    free(reference_sequence);

    for (int i = 0; i < num_reads; i++) {
        free(reads[i]->sequence);
        free(reads[i]);
    }
    free(reads);

    return 0;
}