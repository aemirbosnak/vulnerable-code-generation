//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERRORS 3
#define MATCH 1
#define MISMATCH -1
#define GAP -2

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = rand() % 4;
    }
    sequence->sequence[length] = '\0';
    return sequence;
}

void printSequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int compareSequences(Sequence *sequence1, Sequence *sequence2, int maxErrors) {
    int errors = 0;
    for (int i = 0; i < sequence1->length && i < sequence2->length; i++) {
        if (sequence1->sequence[i]!= sequence2->sequence[i]) {
            errors++;
            if (errors > maxErrors) {
                return -1;
            }
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    Sequence *referenceSequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    Sequence *readSequence = generateRandomSequence(MAX_READ_LENGTH);

    printf("Reference sequence:\n");
    printSequence(referenceSequence);

    printf("Read sequence:\n");
    printSequence(readSequence);

    int result = compareSequences(referenceSequence, readSequence, MAX_ERRORS);
    if (result == 0) {
        printf("Sequences match.\n");
    } else {
        printf("Sequences do not match.\n");
    }

    free(referenceSequence->sequence);
    free(referenceSequence);
    free(readSequence->sequence);
    free(readSequence);

    return 0;
}