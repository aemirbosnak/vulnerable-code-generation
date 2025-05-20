//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define MAX_SEQUENCES 10

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->sequence = malloc(length + 1);
    sequence->length = length;

    // generate a random sequence of A, C, G, and T
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

void printSequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    // generate 10 random sequences
    Sequence *sequences[MAX_SEQUENCES];
    for (int i = 0; i < MAX_SEQUENCES; i++) {
        sequences[i] = generateRandomSequence(rand() % MAX_SEQUENCE_LENGTH + 1);
    }

    // print the sequences
    for (int i = 0; i < MAX_SEQUENCES; i++) {
        printSequence(sequences[i]);
    }

    // free the memory
    for (int i = 0; i < MAX_SEQUENCES; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }

    return 0;
}