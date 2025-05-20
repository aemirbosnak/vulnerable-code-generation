//FormAI DATASET v1.0 Category: Computer Biology ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_GENES 10
#define MIN_MUTATIONS 1
#define MAX_MUTATIONS 3
#define MUTATION_PROBABILITY 5

typedef struct {
    bool alleles[NUM_GENES];
} Genome;

Genome* createGenome() {
    Genome* genome = malloc(sizeof(Genome));
    for (int i = 0; i < NUM_GENES; i++) {
        genome->alleles[i] = rand() % 2 == 0;
    }
    return genome;
}

void mutateGenome(Genome* genome) {
    int numMutations = rand() % (MAX_MUTATIONS - MIN_MUTATIONS + 1) + MIN_MUTATIONS;
    for (int i = 0; i < numMutations; i++) {
        int geneIndex = rand() % NUM_GENES;
        if (rand() % 100 < MUTATION_PROBABILITY) {
            genome->alleles[geneIndex] = !genome->alleles[geneIndex];
        }
    }
}

int main() {
    srand(time(NULL));
    Genome* momGenome = createGenome();
    printf("Mom's Genome: ");
    for (int i = 0; i < NUM_GENES; i++) {
        printf("%d ", momGenome->alleles[i]);
    }
    printf("\n");
    Genome* dadGenome = createGenome();
    printf("Dad's Genome: ");
    for (int i = 0; i < NUM_GENES; i++) {
        printf("%d ", dadGenome->alleles[i]);
    }
    printf("\n");
    Genome* childGenome = malloc(sizeof(Genome));
    for (int i = 0; i < NUM_GENES; i++) {
        if (rand() % 2 == 0) {
            childGenome->alleles[i] = momGenome->alleles[i];
        } else {
            childGenome->alleles[i] = dadGenome->alleles[i];
        }
    }
    printf("Child's Genome: ");
    for (int i = 0; i < NUM_GENES; i++) {
        printf("%d ", childGenome->alleles[i]);
    }
    printf("\n");
    mutateGenome(childGenome);
    printf("Mutated Child's Genome: ");
    for (int i = 0; i < NUM_GENES; i++) {
        printf("%d ", childGenome->alleles[i]);
    }
    printf("\n");
    free(momGenome);
    free(dadGenome);
    free(childGenome);
    return 0;
}