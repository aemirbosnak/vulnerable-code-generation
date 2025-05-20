//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MIN_SEQUENCE_LENGTH 100
#define MAX_SEQUENCE_VARIATION 1000000

typedef struct {
    char *sequence;
    int length;
} Sequence;

void generateRandomSequence(Sequence *sequence, int minLength, int maxLength) {
    int length = rand() % (maxLength - minLength + 1) + minLength;
    sequence->sequence = (char *) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }
    sequence->sequence[length] = '\0';
    sequence->length = length;
}

void printSequence(Sequence sequence) {
    printf("%s\n", sequence.sequence);
}

void simulateMutations(Sequence *sequence, int numMutations, int maxSequenceVariation) {
    for (int i = 0; i < numMutations; i++) {
        int position = rand() % sequence->length;
        int variation = rand() % maxSequenceVariation;
        int newBase = sequence->sequence[position] + variation;
        if (newBase > 3) {
            newBase = 0;
        }
        sequence->sequence[position] = newBase;
    }
}

int main() {
    srand(time(NULL));

    int numSequences = rand() % 10 + 1;
    Sequence *sequences = (Sequence *) malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        int sequenceLength = rand() % MAX_SEQUENCE_LENGTH + MIN_SEQUENCE_LENGTH;
        generateRandomSequence(&sequences[i], MIN_SEQUENCE_LENGTH, sequenceLength);
    }

    for (int i = 0; i < numSequences; i++) {
        int numMutations = rand() % MAX_SEQUENCE_VARIATION + 1;
        simulateMutations(&sequences[i], numMutations, MAX_SEQUENCE_VARIATION);
    }

    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}