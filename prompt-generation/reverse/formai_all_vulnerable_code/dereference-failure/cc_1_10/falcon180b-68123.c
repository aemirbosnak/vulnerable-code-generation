//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_DNA_SEQUENCE_LENGTH 1000000
#define NUM_NUCLEOTIDES 4

enum { A, C, G, T };

typedef struct {
    char *sequence;
    int length;
} DNASequence;

DNASequence *generateRandomSequence(int length) {
    DNASequence *result = malloc(sizeof(DNASequence));
    result->sequence = malloc(length + 1);
    result->length = length;

    for (int i = 0; i < length; i++) {
        result->sequence[i] = (char) rand() % NUM_NUCLEOTIDES;
    }
    result->sequence[length] = '\0';

    return result;
}

void printSequence(DNASequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    int numSequences = 10;
    int maxSequenceLength = 100;
    int minSequenceLength = 50;

    DNASequence **sequences = malloc(sizeof(DNASequence *) * numSequences);

    for (int i = 0; i < numSequences; i++) {
        int sequenceLength = rand() % (maxSequenceLength - minSequenceLength + 1) + minSequenceLength;
        sequences[i] = generateRandomSequence(sequenceLength);
    }

    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
        free(sequences[i]->sequence);
        free(sequences[i]);
    }

    free(sequences);

    return 0;
}