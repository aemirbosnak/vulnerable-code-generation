//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_BASES 4
#define MAX_MUTATIONS 100
#define MUTATION_RATE 0.001
#define GENOME_SIZE 1000000

typedef struct {
    char sequence[MAX_SEQUENCE_LENGTH];
    int length;
    int mutations;
} Genome;

Genome *generateRandomGenome(int length) {
    Genome *genome = (Genome *) malloc(sizeof(Genome));
    genome->length = length;
    genome->mutations = 0;

    for (int i = 0; i < length; i++) {
        genome->sequence[i] = rand() % MAX_BASES + 'A';
    }

    return genome;
}

void mutateSequence(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        if (rand() % 100 < MUTATION_RATE) {
            char base = rand() % MAX_BASES + 'A';
            while (base == genome->sequence[i]) {
                base = rand() % MAX_BASES + 'A';
            }
            genome->sequence[i] = base;
            genome->mutations++;
        }
    }
}

void printGenome(Genome *genome) {
    for (int i = 0; i < genome->length; i++) {
        printf("%c", genome->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Genome *genome = generateRandomGenome(GENOME_SIZE);
    mutateSequence(genome);

    printf("Original genome:\n");
    printGenome(genome);

    printf("Mutated genome:\n");
    mutateSequence(genome);
    printGenome(genome);

    return 0;
}