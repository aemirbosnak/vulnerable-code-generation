//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome
#define GENOME_LENGTH 10000

// Define the probability of each nucleotide
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide
char generate_nucleotide() {
    double r = (double)rand() / RAND_MAX;
    if (r < PROB_A) {
        return A;
    } else if (r < PROB_A + PROB_C) {
        return C;
    } else if (r < PROB_A + PROB_C + PROB_G) {
        return G;
    } else {
        return T;
    }
}

// Generate a random genome
char *generate_genome() {
    char *genome = malloc(GENOME_LENGTH + 1);
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = generate_nucleotide();
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

// Print the genome
void print_genome(char *genome) {
    printf("%s\n", genome);
}

// Free the memory allocated for the genome
void free_genome(char *genome) {
    free(genome);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random genome
    char *genome = generate_genome();

    // Print the genome
    print_genome(genome);

    // Free the memory allocated for the genome
    free_genome(genome);

    return 0;
}