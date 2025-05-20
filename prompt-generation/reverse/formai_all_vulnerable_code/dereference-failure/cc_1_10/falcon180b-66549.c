//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define NUM_SEQUENCES 100

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

Sequence *generateSequences(int numSequences, int minLength, int maxLength) {
    Sequence *sequences = malloc(sizeof(Sequence) * numSequences);
    for (int i = 0; i < numSequences; i++) {
        sequences[i].name = malloc(sizeof(char) * 10);
        sprintf(sequences[i].name, "Sequence %d", i + 1);
        sequences[i].length = rand() % (maxLength - minLength + 1) + minLength;
        sequences[i].sequence = malloc(sizeof(char) * sequences[i].length);
        for (int j = 0; j < sequences[i].length; j++) {
            sequences[i].sequence[j] = 'A' + rand() % 4;
        }
    }
    return sequences;
}

void printSequences(Sequence *sequences, int numSequences) {
    for (int i = 0; i < numSequences; i++) {
        printf("Name: %s\n", sequences[i].name);
        printf("Sequence: ");
        for (int j = 0; j < sequences[i].length; j++) {
            printf("%c", sequences[i].sequence[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Sequence *sequences = generateSequences(NUM_SEQUENCES, 100, 1000);
    printSequences(sequences, NUM_SEQUENCES);
    for (int i = 0; i < NUM_SEQUENCES; i++) {
        free(sequences[i].name);
        free(sequences[i].sequence);
    }
    free(sequences);
    return 0;
}