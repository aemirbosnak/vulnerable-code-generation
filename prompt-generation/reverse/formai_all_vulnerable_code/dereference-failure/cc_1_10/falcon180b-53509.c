//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *seq = malloc(sizeof(Sequence));
    seq->length = length;
    seq->sequence = malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        seq->sequence[i] = rand() % 4; // A, C, G, or T
    }

    return seq;
}

void printSequence(Sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->sequence[i]);
    }
    printf("\n");
}

int main() {
    int sequenceLength = MAX_SEQUENCE_LENGTH;
    int readLength = MAX_READ_LENGTH;

    Sequence *genome = generateRandomSequence(sequenceLength);
    Sequence *read1 = generateRandomSequence(readLength);
    Sequence *read2 = generateRandomSequence(readLength);

    printf("Genome sequence:\n");
    printSequence(genome);

    printf("Read 1:\n");
    printSequence(read1);

    printf("Read 2:\n");
    printSequence(read2);

    return 0;
}