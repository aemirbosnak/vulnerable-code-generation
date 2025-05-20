//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000000

typedef struct {
    char* sequence;
    int length;
} Sequence;

Sequence* generateRandomSequence(int length) {
    Sequence* sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }
    return sequence;
}

void printSequence(Sequence* sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i] + 'A');
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence* referenceSequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Sequence* querySequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);

    int* matches = malloc(MAX_SEQUENCE_LENGTH * sizeof(int));
    int numMatches = 0;

    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        if (referenceSequence->sequence[i] == querySequence->sequence[i]) {
            matches[numMatches++] = i;
        }
    }

    printf("Reference sequence:\n");
    printSequence(referenceSequence);

    printf("Query sequence:\n");
    printSequence(querySequence);

    printf("Matches:\n");
    for (int i = 0; i < numMatches; i++) {
        printf("%d ", matches[i]);
    }
    printf("\n");

    free(matches);
    free(referenceSequence->sequence);
    free(referenceSequence);
    free(querySequence->sequence);
    free(querySequence);

    return 0;
}