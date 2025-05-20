//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_MUTATION_RATE 0.01

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *generateRandomGenome(int length) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->sequence = (char *) malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = rand() % 4 + 'A';
    }
    genome->sequence[length] = '\0';

    return genome;
}

void printGenome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

int countMutations(Genome *genome1, Genome *genome2) {
    int mutations = 0;

    for (int i = 0; i < genome1->length; i++) {
        if (genome1->sequence[i]!= genome2->sequence[i]) {
            mutations++;
        }
    }

    return mutations;
}

int main() {
    srand(time(NULL));

    Genome *genome1 = generateRandomGenome(MAX_SEQUENCE_LENGTH);
    Genome *genome2 = generateRandomGenome(MAX_SEQUENCE_LENGTH);

    int mutations = countMutations(genome1, genome2);

    printf("Genome 1: ");
    printGenome(genome1);
    printf("Genome 2: ");
    printGenome(genome2);
    printf("Number of mutations: %d\n", mutations);

    return 0;
}