//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence generateRandomSequence(int length) {
    Sequence result = {0};
    result.length = length;
    result.sequence = malloc(length * sizeof(char));

    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        result.sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }

    return result;
}

void printSequence(Sequence sequence) {
    printf("Sequence: %s\n", sequence.sequence);
    printf("Length: %d\n", sequence.length);
}

int main() {
    int numSequences;
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &numSequences);

    Sequence *sequences = malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        int length;
        printf("Enter the length of sequence %d: ", i + 1);
        scanf("%d", &length);

        if (length > MAX_SEQUENCE_LENGTH) {
            printf("Error: Sequence length must be less than or equal to %d\n", MAX_SEQUENCE_LENGTH);
            return 1;
        }

        sequences[i] = generateRandomSequence(length);
        printSequence(sequences[i]);
    }

    free(sequences);
    return 0;
}