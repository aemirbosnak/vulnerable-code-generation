//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GENOME_SIZE 1000000

/* Define nucleotide symbols */
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

/* Randomly generates a nucleotide symbol (A, C, G, or T) */
char random_nucleotide() {
    char nucleotides[4] = {A, C, G, T};
    int randomIndex = rand() % 4;
    return nucleotides[randomIndex];
}

/* Randomly generates a DNA strand of specified length */
void simulate_genome(char* genome, int length) {
    for (int i = 0; i < length; i++) {
        genome[i] = random_nucleotide();
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    /* Simulate human genome */
    char* humanGenome = malloc(GENOME_SIZE * sizeof(char));
    simulate_genome(humanGenome, GENOME_SIZE);
    printf("Simulated human genome: %s\n", humanGenome);

    /* Simulate cancer genome */
    char* cancerGenome = malloc(GENOME_SIZE * sizeof(char));
    memcpy(cancerGenome, humanGenome, GENOME_SIZE);
    int numMutations = rand() % (GENOME_SIZE / 10); // Generate random number of mutations (up to 10% of genome)
    int* mutationIndices = malloc(numMutations * sizeof(int));
    for (int i = 0; i < numMutations; i++) {
        int index = rand() % GENOME_SIZE;
        mutationIndices[i] = index;
        char originalNucleotide = cancerGenome[index];
        char newNucleotide = random_nucleotide();
        while (newNucleotide == originalNucleotide) { // Make sure new nucleotide is different than original
            newNucleotide = random_nucleotide();
        }
        cancerGenome[index] = newNucleotide;
    }
    printf("Simulated cancer genome with %d mutations: %s\n", numMutations, cancerGenome);

    free(humanGenome);
    free(cancerGenome);
    free(mutationIndices);

    return 0;
}