//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generateRandomSequence(int length) {
    Sequence *sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->sequence = (char *) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->length = length;
    return sequence;
}

int compareSequences(const void *a, const void *b) {
    Sequence *sequenceA = *(Sequence **) a;
    Sequence *sequenceB = *(Sequence **) b;
    return strcmp(sequenceA->sequence, sequenceB->sequence);
}

void printSequence(Sequence *sequence) {
    printf("%s (%d bp)\n", sequence->sequence, sequence->length);
}

int main() {
    srand(time(NULL));

    int numSequences;
    printf("Enter the number of sequences to generate (max %d): ", MAX_NUM_SEQUENCES);
    scanf("%d", &numSequences);

    Sequence **sequences = (Sequence **) malloc((numSequences + 1) * sizeof(Sequence *));
    for (int i = 0; i < numSequences; i++) {
        int length;
        printf("Enter the length of sequence %d (max %d): ", i+1, MAX_SEQUENCE_LENGTH);
        scanf("%d", &length);
        sequences[i] = generateRandomSequence(length);
    }
    sequences[numSequences] = NULL;

    qsort(sequences, numSequences, sizeof(Sequence *), compareSequences);

    for (int i = 0; i < numSequences; i++) {
        printSequence(sequences[i]);
    }

    for (int i = 0; i < numSequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}