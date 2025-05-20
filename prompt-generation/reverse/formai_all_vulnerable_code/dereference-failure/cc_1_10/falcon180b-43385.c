//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

void printSequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

int main() {
    int numSequences, maxLength;

    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);

    printf("Enter the maximum length of each sequence: ");
    scanf("%d", &maxLength);

    Sequence **sequences = malloc(numSequences * sizeof(Sequence *));

    for (int i = 0; i < numSequences; i++) {
        sequences[i] = generateRandomSequence(maxLength);
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}