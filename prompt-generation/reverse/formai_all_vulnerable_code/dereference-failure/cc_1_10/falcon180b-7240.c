//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int start;
    int end;
} Read;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4; // A, C, G, or T
    }

    return sequence;
}

Read *generateRandomRead(int length, Sequence *sequence) {
    Read *read = malloc(sizeof(Read));
    read->sequence = malloc(length * sizeof(char));

    int start = rand() % (sequence->length - length);
    int end = start + length;

    for (int i = 0; i < length; i++) {
        read->sequence[i] = sequence->sequence[start + i];
    }

    read->start = start;
    read->end = end;

    return read;
}

int main() {
    srand(time(NULL));

    Sequence *genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Read *read1 = generateRandomRead(MAX_READ_LENGTH, genome);
    Read *read2 = generateRandomRead(MAX_READ_LENGTH, genome);

    printf("Genome sequence:\n%s\n", genome->sequence);
    printf("Read 1: %s\n", read1->sequence);
    printf("Read 2: %s\n", read2->sequence);

    return 0;
}