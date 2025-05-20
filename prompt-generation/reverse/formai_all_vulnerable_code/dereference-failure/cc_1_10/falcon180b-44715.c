//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_ALPHABET_SIZE 26
#define MAX_MUTATION_RATE 0.05

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
} Genome;

void generateRandomSequence(Genome *genome, int length) {
    for (int i = 0; i < length; i++) {
        genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
    }
    genome->length = length;
}

void printGenome(Genome genome) {
    printf("Genome: %s\n", genome.sequence);
    printf("Length: %d\n", genome.length);
}

void mutateGenome(Genome *genome, float mutationRate) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() % 100 < mutationRate * 100) {
            genome->sequence[i] = 'A' + rand() % MAX_ALPHABET_SIZE;
        }
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));

    int numGenerations = 100;
    int populationSize = 100;
    float mutationRate = MAX_MUTATION_RATE;

    Genome *population = (Genome *) malloc(populationSize * sizeof(Genome));

    for (int i = 0; i < populationSize; i++) {
        generateRandomSequence(&population[i], rand() % MAX_SEQUENCE_LENGTH + 1);
    }

    for (int generation = 0; generation < numGenerations; generation++) {
        printf("Generation %d:\n", generation);

        for (int i = 0; i < populationSize; i++) {
            printGenome(population[i]);
        }

        for (int i = 0; i < populationSize; i++) {
            mutateGenome(&population[i], mutationRate);
        }
    }

    free(population);

    return 0;
}