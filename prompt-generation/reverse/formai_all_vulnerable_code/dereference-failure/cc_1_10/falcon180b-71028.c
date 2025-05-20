//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_MUTATION_RATE 10

typedef struct {
    char *sequence;
    int length;
} Genome;

Genome *generateRandomGenome(int length) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->sequence = (char *) malloc(length + 1);
    genome->length = length;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    genome->sequence[length] = '\0';

    return genome;
}

void printGenome(Genome *genome) {
    printf("Genome: %s\n", genome->sequence);
}

void mutateGenome(Genome *genome, int mutationRate) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() % 100 < mutationRate) {
            genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
        }
    }
}

int main() {
    srand(time(NULL));

    int genomeLength = rand() % MAX_SEQUENCE_LENGTH + 1;
    Genome *genome1 = generateRandomGenome(genomeLength);
    Genome *genome2 = generateRandomGenome(genomeLength);

    printGenome(genome1);
    printGenome(genome2);

    int mutationRate = rand() % MAX_MUTATION_RATE + 1;

    mutateGenome(genome1, mutationRate);
    mutateGenome(genome2, mutationRate);

    printf("Mutated Genome 1: ");
    printGenome(genome1);
    printf("Mutated Genome 2: ");
    printGenome(genome2);

    return 0;
}