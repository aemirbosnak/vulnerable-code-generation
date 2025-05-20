//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide symbols
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Simulated sequencing error rate
#define ERROR_RATE 0.01

// Function to generate a random nucleotide
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
            return A; // Default to A
    }
}

// Function to introduce sequencing errors
char introduce_error(char nucleotide) {
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
        // Introduce an error by randomly generating a new nucleotide
        return generate_nucleotide();
    } else {
        // No error introduced, return the original nucleotide
        return nucleotide;
    }
}

// Function to simulate sequencing a DNA fragment
char *simulate_sequencing(char *dna_fragment) {
    // Allocate memory for the simulated sequence
    char *simulated_sequence = malloc(strlen(dna_fragment) + 1);

    // Simulate sequencing the DNA fragment
    for (int i = 0; i < strlen(dna_fragment); i++) {
        simulated_sequence[i] = introduce_error(dna_fragment[i]);
    }

    // Terminate the simulated sequence with a null character
    simulated_sequence[strlen(dna_fragment)] = '\0';

    return simulated_sequence;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the DNA fragment to be sequenced
    char dna_fragment[] = "ACGTACGTACGT";

    // Simulate sequencing the DNA fragment
    char *simulated_sequence = simulate_sequencing(dna_fragment);

    // Print the simulated sequence
    printf("Simulated sequence: %s\n", simulated_sequence);

    // Free the allocated memory
    free(simulated_sequence);

    return 0;
}