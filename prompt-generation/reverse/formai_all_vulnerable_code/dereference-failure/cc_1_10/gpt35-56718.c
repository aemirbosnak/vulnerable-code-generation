//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_SIZE 100 // Define the size of our sample genome
#define MUTATION_RATE 0.05 // Define the mutation rate (5%)

typedef struct {
    char nucleotide; // A, C, G, or T
    int position; // The position in the genome
} Gene;

// Generate a random nucleotide
char random_nucleotide() {
    int r = rand() % 4;
    if (r == 0) return 'A';
    else if (r == 1) return 'C';
    else if (r == 2) return 'G';
    else return 'T';
}

// Generate a random genome
Gene* random_genome() {
    srand(time(NULL)); // Seed the random number generator
    Gene* genome = (Gene*) malloc(SAMPLE_SIZE * sizeof(Gene));
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        genome[i].nucleotide = random_nucleotide();
        genome[i].position = i;
    }
    return genome;
}

// Mutate a genome with some probability
void mutate_genome(Gene* genome) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        double p = (double) rand() / RAND_MAX;
        if (p < MUTATION_RATE) {
            genome[i].nucleotide = random_nucleotide();
        }
    }
}

// Print a genome
void print_genome(Gene* genome) {
    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printf("%c", genome[i].nucleotide);
    }
    printf("\n");
}

// Main function
int main() {
    Gene* genome = random_genome();
    printf("Original genome: ");
    print_genome(genome);
    mutate_genome(genome);
    printf("Mutated genome: ");
    print_genome(genome);
    free(genome);
    return 0;
}