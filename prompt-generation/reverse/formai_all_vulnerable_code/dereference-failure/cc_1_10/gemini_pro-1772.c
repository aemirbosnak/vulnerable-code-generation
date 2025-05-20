//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a genome
#define MAX_LENGTH 10000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Generate a random nucleotide character
char generate_nucleotide() {
    int rand_num = rand() % 4;
    switch (rand_num) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
        default:
            return A;
    }
}

// Generate a random genome of a specified length
char *generate_genome(int length) {
    // Allocate memory for the genome
    char *genome = malloc(length + 1);

    // Initialize the genome with random nucleotides
    for (int i = 0; i < length; i++) {
        genome[i] = generate_nucleotide();
    }

    // Add a null terminator to the end of the genome
    genome[length] = '\0';

    return genome;
}

// Mutate a genome with a specified probability
void mutate_genome(char *genome, double mutation_probability) {
    for (int i = 0; i < strlen(genome); i++) {
        if ((double)rand() / RAND_MAX < mutation_probability) {
            genome[i] = generate_nucleotide();
        }
    }
}

// Print a genome to the console
void print_genome(char *genome) {
    printf("%s\n", genome);
}

// Free the memory allocated for a genome
void free_genome(char *genome) {
    free(genome);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the length of the genome to be generated
    int length = 1000;

    // Generate a random genome
    char *genome = generate_genome(length);

    // Print the original genome
    printf("Original genome:\n");
    print_genome(genome);

    // Mutate the genome with a probability of 1%
    mutate_genome(genome, MUTATION_PROBABILITY);

    // Print the mutated genome
    printf("\nMutated genome:\n");
    print_genome(genome);

    // Free the memory allocated for the genome
    free_genome(genome);

    return 0;
}