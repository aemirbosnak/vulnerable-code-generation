//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char* sequence;
    int length;
} Sequence;

typedef struct {
    char* read;
    int length;
    int offset;
} Read;

Sequence* generate_random_sequence(int length) {
    Sequence* sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }

    return sequence;
}

Read* generate_random_read(int length, Sequence* reference) {
    Read* read = malloc(sizeof(Read));
    read->length = length;
    read->offset = rand() % reference->length;

    char* read_sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (i - read->offset >= 0 && i - read->offset < reference->length) {
            read_sequence[i] = reference->sequence[i - read->offset];
        } else {
            read_sequence[i] = 'N';
        }
    }

    read->read = read_sequence;

    return read;
}

int main() {
    srand(time(NULL));

    Sequence* reference = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    printf("Reference sequence:\n%s\n", reference->sequence);

    int num_reads = 100;
    Read** reads = malloc(num_reads * sizeof(Read*));

    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_random_read(MAX_READ_LENGTH, reference);
        printf("Read %d: %s\n", i + 1, reads[i]->read);
    }

    free(reference->sequence);
    free(reference);

    for (int i = 0; i < num_reads; i++) {
        free(reads[i]->read);
        free(reads[i]);
    }
    free(reads);

    return 0;
}