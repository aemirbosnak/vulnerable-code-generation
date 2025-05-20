//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000

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
        seq->sequence[i] = rand() % 4 + 'A';
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
    int numSequences, maxLength;

    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);

    printf("Enter the maximum length of each sequence: ");
    scanf("%d", &maxLength);

    Sequence **sequences = malloc(numSequences * sizeof(Sequence *));

    for (int i = 0; i < numSequences; i++) {
        sequences[i] = generateRandomSequence(rand() % maxLength + 1);
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}