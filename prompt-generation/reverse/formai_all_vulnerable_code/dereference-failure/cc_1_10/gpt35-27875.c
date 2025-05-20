//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 100 // Length of the genome
#define MUTATION_RATE 0.01 // Mutation rate

/**
 * This function generates a random nucleotide
 **/
char generateNucleotide() {
    int random = rand() % 4;
    switch (random) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return '-';
    }
}

/**
 * This function generates a random genome
 **/
char* generateGenome() {
    char* genome = malloc(sizeof(char) * LENGTH);
    for (int i = 0; i < LENGTH; i++) {
        genome[i] = generateNucleotide();
    }
    return genome;
}

/**
 * This function prints a genome
 **/
void printGenome(char* genome) {
    for (int i = 0; i < LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

/**
 * This function mutates a genome
 **/
void mutateGenome(char* genome) {
    for (int i = 0; i < LENGTH; i++) {
        double random = (double) rand() / (double) RAND_MAX;
        if (random <= MUTATION_RATE) {
            genome[i] = generateNucleotide();
        }
    }
}

/**
 * This function compares two genomes and returns the number of differences
 **/
int compareGenomes(char* genome1, char* genome2) {
    int differences = 0;
    for (int i = 0; i < LENGTH; i++) {
        if (genome1[i] != genome2[i]) {
            differences++;
        }
    }
    return differences;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Generate two random genomes
    char* genome1 = generateGenome();
    char* genome2 = generateGenome();

    printf("Genome 1: ");
    printGenome(genome1);

    printf("Genome 2: ");
    printGenome(genome2);

    // Mutate one of the genomes
    mutateGenome(genome1);

    printf("Mutated genome 1: ");
    printGenome(genome1);

    // Compare the genomes and print the number of differences
    int differences = compareGenomes(genome1, genome2);
    printf("Number of differences: %d\n", differences);

    // Free the memory used by the genomes
    free(genome1);
    free(genome2);

    return 0;
}