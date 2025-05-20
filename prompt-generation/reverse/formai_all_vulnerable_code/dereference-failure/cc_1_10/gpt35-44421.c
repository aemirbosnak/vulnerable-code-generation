//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define SEQ_LENGTH 1000 // The length of the DNA sequence
#define MUTATION_RATE 0.01 // The probability of a mutation occurring at each base pair

// Function prototypes
char generate_random_base();
char mutate_base(char base);
char* generate_random_sequence();
char* mutate_sequence(char* sequence);

// Main program
int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random DNA sequence
    char* sequence = generate_random_sequence();
    printf("Original sequence: %s\n", sequence);
    
    // Simulate mutations
    for (int i = 0; i < 100; i++) {
        sequence = mutate_sequence(sequence);
        printf("Mutated sequence %d: %s\n", i+1, sequence);
    }
    
    // Free dynamically allocated memory
    free(sequence);
    
    return 0;
}

// Function to generate a random base
char generate_random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

// Function to mutate a base
char mutate_base(char base) {
    if ((double)rand() / RAND_MAX < MUTATION_RATE) {
        switch (base) {
            case 'A':
                return generate_random_base() != 'A' ? 'A' : generate_random_base();
            case 'C':
                return generate_random_base() != 'C' ? 'C' : generate_random_base();
            case 'G':
                return generate_random_base() != 'G' ? 'G' : generate_random_base();
            case 'T':
                return generate_random_base() != 'T' ? 'T' : generate_random_base();
            default:
                return generate_random_base();
        }
    } else {
        return base;
    }
}

// Function to generate a random DNA sequence
char* generate_random_sequence() {
    char* sequence = (char*)malloc((SEQ_LENGTH+1) * sizeof(char));
    for (int i = 0; i < SEQ_LENGTH; i++) {
        sequence[i] = generate_random_base();
    }
    sequence[SEQ_LENGTH] = '\0';
    return sequence;
}

// Function to mutate a DNA sequence
char* mutate_sequence(char* sequence) {
    char* mutated_sequence = (char*)malloc((SEQ_LENGTH+1) * sizeof(char));
    for (int i = 0; i < SEQ_LENGTH; i++) {
        mutated_sequence[i] = mutate_base(sequence[i]);
    }
    mutated_sequence[SEQ_LENGTH] = '\0';
    free(sequence); // Free the old sequence
    return mutated_sequence;
}