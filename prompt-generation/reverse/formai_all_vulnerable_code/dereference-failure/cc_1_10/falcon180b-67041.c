//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char base;
    int frequency;
} BaseFrequency;

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(sizeof(char) * length);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }

    return sequence;
}

void printSequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
}

void countBases(Sequence *sequence, BaseFrequency *baseFrequencies) {
    for (int i = 0; i < sequence->length; i++) {
        char base = sequence->sequence[i];
        baseFrequencies[base - 'A'].frequency++;
    }
}

void printBaseFrequencies(BaseFrequency *baseFrequencies) {
    for (int i = 0; i < MAX_ALPHABET_SIZE; i++) {
        printf("Base %c: %d\n", i + 'A', baseFrequencies[i].frequency);
    }
}

int main() {
    int sequenceLength = 100;
    Sequence *sequence = generateRandomSequence(sequenceLength);
    BaseFrequency baseFrequencies[MAX_ALPHABET_SIZE] = {0};

    printf("Random sequence of length %d:\n", sequenceLength);
    printSequence(sequence);

    countBases(sequence, baseFrequencies);

    printf("\nBase frequencies:\n");
    printBaseFrequencies(baseFrequencies);

    free(sequence->sequence);
    free(sequence);

    return 0;
}