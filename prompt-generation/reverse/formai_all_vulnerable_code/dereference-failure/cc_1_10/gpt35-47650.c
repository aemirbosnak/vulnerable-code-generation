//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defining structure for genes
struct Gene { 
    char letter; 
    int position; 
}; 

// Defining structure for chromosomes
struct Chromosome {
    struct Gene* genes;
    int length;
};

// Function to generate random gene
char getRandomGene() {
    int randomNumber = rand() % 4;

    switch (randomNumber) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
}

// Function to create chromosome
struct Chromosome createChromosome(int length) {
    struct Chromosome chromosome;
    chromosome.length = length;
    chromosome.genes = malloc(length * sizeof(struct Gene));

    for (int i = 0; i < length; i++) {
        chromosome.genes[i].letter = getRandomGene();
        chromosome.genes[i].position = i;
    }

    return chromosome;
}

// Function to print chromosome
void printChromosome(struct Chromosome chromosome) {
    for (int i = 0; i < chromosome.length; i++) {
        printf("%c", chromosome.genes[i].letter);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the C Genome Sequencing Simulator!\n");

    int chromosomeLength = rand() % 50 + 1;

    printf("Generating random chromosome with length %d...\n", chromosomeLength);
    
    struct Chromosome chromosome = createChromosome(chromosomeLength);
    
    printf("Here's your chromosome: ");
    printChromosome(chromosome);

    free(chromosome.genes);
    return 0;
}