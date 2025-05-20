//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_NUM_SEQUENCES 1000

typedef struct {
    char* sequence;
    int length;
} Sequence;

typedef struct {
    Sequence* sequences;
    int numSequences;
} Genome;

void generateRandomSequence(char* sequence, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
}

Genome* createGenome(int numSequences, int maxSequenceLength) {
    Genome* genome = malloc(sizeof(Genome));
    genome->sequences = malloc(numSequences * sizeof(Sequence));
    genome->numSequences = numSequences;

    for (int i = 0; i < numSequences; i++) {
        genome->sequences[i].sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
        genome->sequences[i].length = rand() % maxSequenceLength + 1;
        generateRandomSequence(genome->sequences[i].sequence, genome->sequences[i].length);
    }

    return genome;
}

void printGenome(Genome* genome) {
    for (int i = 0; i < genome->numSequences; i++) {
        printf("Sequence %d: %s\n", i+1, genome->sequences[i].sequence);
    }
}

void freeGenome(Genome* genome) {
    for (int i = 0; i < genome->numSequences; i++) {
        free(genome->sequences[i].sequence);
    }
    free(genome->sequences);
    free(genome);
}

int main() {
    Genome* genome = createGenome(10, 100);
    printGenome(genome);
    freeGenome(genome);

    return 0;
}