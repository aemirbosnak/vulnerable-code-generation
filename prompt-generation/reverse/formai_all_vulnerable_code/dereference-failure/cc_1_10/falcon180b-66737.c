//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *name;
    Sequence *sequence;
} Genome;

char *generateRandomSequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    sequence[length] = '\0';
    return sequence;
}

Genome *createGenome(int numSequences, int maxSequenceLength) {
    Genome *genome = malloc(sizeof(Genome));
    genome->name = "Happy Genome";
    genome->sequence = malloc(numSequences * sizeof(Sequence));

    for (int i = 0; i < numSequences; i++) {
        genome->sequence[i].sequence = generateRandomSequence(rand() % maxSequenceLength + 1);
        genome->sequence[i].length = strlen(genome->sequence[i].sequence);
    }

    return genome;
}

void printGenome(Genome *genome) {
    printf("Genome Name: %s\n", genome->name);
    printf("Number of Sequences: %d\n", genome->sequence[0].length);

    for (int i = 0; i < genome->sequence[0].length; i++) {
        printf("%c", *(genome->sequence[0].sequence + i));
    }

    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome *genome = createGenome(5, MAX_SEQUENCE_LENGTH);
    printGenome(genome);

    free(genome->name);
    for (int i = 0; i < genome->sequence[0].length; i++) {
        free(genome->sequence[i].sequence);
    }
    free(genome->sequence);
    free(genome);

    return 0;
}