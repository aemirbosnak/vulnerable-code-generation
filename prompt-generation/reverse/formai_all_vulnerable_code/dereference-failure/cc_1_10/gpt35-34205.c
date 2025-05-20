//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define GENOME_LEN 100 // length of genome
#define MUTATION_RATE 0.1 // probability of mutation for each base
#define BASES "ATCG" // possible bases for DNA

typedef struct {
    char bases[GENOME_LEN+1];
    int fitness;
} Genome;

char randomBase() {
    int r = rand() % strlen(BASES);
    return BASES[r];
}

void randomSequence(char *seq) {
    for(int i=0; i<GENOME_LEN; i++) {
        seq[i] = randomBase();
    }
    seq[GENOME_LEN] = '\0';
}

void mutateSequence(char *seq) {
    for(int i=0; i<GENOME_LEN; i++) {
        float r = (float)rand()/(float)RAND_MAX;
        if(r < MUTATION_RATE) {
            seq[i] = randomBase();
        }
    }
}

int calculateFitness(char *seq, char *target) {
    int fitness = 0;
    for(int i=0; i<GENOME_LEN; i++) {
        if(seq[i] == target[i]) {
            fitness++;
        }
    }
    return fitness;
}

void copySequence(char *dest, char *src) {
    for(int i=0; i<GENOME_LEN; i++) {
        dest[i] = src[i];
    }
    dest[GENOME_LEN] = '\0';
}

void copyGenome(Genome *dest, Genome *src) {
    copySequence(dest->bases, src->bases);
    dest->fitness = src->fitness;
}

void generatePopulation(Genome *population, char *target, int size) {
    for(int i=0; i<size; i++) {
        randomSequence(population[i].bases);
        population[i].fitness = calculateFitness(population[i].bases, target);
    }
}

int compareGenomes(const void *a, const void *b) {
    Genome *g1 = (Genome *)a;
    Genome *g2 = (Genome *)b;
    return g2->fitness - g1->fitness;
}

void sortPopulation(Genome *population, int size) {
    qsort(population, size, sizeof(Genome), compareGenomes);
}

void breed(Genome *parent1, Genome *parent2, Genome *child) {
    int midpoint = rand() % GENOME_LEN;
    for(int i=0; i<GENOME_LEN; i++) {
        if(i < midpoint) {
            child->bases[i] = parent1->bases[i];
        } else {
            child->bases[i] = parent2->bases[i];
        }
    }
    mutateSequence(child->bases);
    child->fitness = calculateFitness(child->bases, parent1->bases);
}

void evolvePopulation(Genome *population, char *target, int popSize, int numKids) {
    Genome *kids = (Genome *)malloc(numKids * sizeof(Genome));
    for(int i=0; i<numKids; i++) {
        int parent1 = rand() % popSize;
        int parent2 = rand() % popSize;
        breed(&population[parent1], &population[parent2], &kids[i]);
    }
    sortPopulation(population, popSize);
    sortPopulation(kids, numKids);
    for(int i=0; i<numKids; i++) {
        copyGenome(&population[popSize-numKids+i], &kids[i]);
    }
    free(kids);

    // update fitness for entire population
    for(int i=0; i<popSize; i++) {
        population[i].fitness = calculateFitness(population[i].bases, target);
    }
}

void printGenome(Genome *genome) {
    printf("%s (%d)\n", genome->bases, genome->fitness);
}

int main() {
    srand(time(NULL));

    // set target genome
    char target[GENOME_LEN+1] = "ATTATCCAAGCTCGGATTAGGTGAGACAGGTTCAGGTAGGTCTCACTGACCACGAGAGTCCTGTCTCGATT";

    // set population size and number of kids per generation
    int popSize = 50;
    int numKids = 10;

    // create initial population
    Genome *population = (Genome *)malloc(popSize * sizeof(Genome));
    generatePopulation(population, target, popSize);

    // evolve population
    int generations = 0;
    while(population[0].fitness < GENOME_LEN) {
        evolvePopulation(population, target, popSize, numKids);
        printf("Generation %d: ", generations);
        printGenome(&population[0]);
        generations++;
    }

    free(population);

    return 0;
}