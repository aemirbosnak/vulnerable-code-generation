//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DNA nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Generate a random DNA sequence of length n
char* generate_dna(int n) {
    char* dna = malloc(n + 1); // +1 for the null terminator
    for (int i = 0; i < n; i++) {
        dna[i] = nucleotides[rand() % 4];
    }
    dna[n] = '\0'; // Null terminate the string
    return dna;
}

// Simulate the sequencing process
char* sequence_dna(char* dna) {
    int n = strlen(dna);
    char* sequence = malloc(n + 1); // +1 for the null terminator
    for (int i = 0; i < n; i++) {
        // Simulate sequencing errors with a 1% probability
        if (rand() % 100 < 1) {
            sequence[i] = nucleotides[rand() % 4];
        } else {
            sequence[i] = dna[i];
        }
    }
    sequence[n] = '\0'; // Null terminate the string
    return sequence;
}

// Print the DNA sequence and its sequenced version
void print_dna(char* dna, char* sequence) {
    printf("Original DNA sequence: %s\n", dna);
    printf("Sequenced DNA sequence: %s\n", sequence);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random DNA sequence of length 100
    char* dna = generate_dna(100);

    // Simulate the sequencing process
    char* sequence = sequence_dna(dna);

    // Print the DNA sequence and its sequenced version
    print_dna(dna, sequence);

    // Free the allocated memory
    free(dna);
    free(sequence);

    return 0;
}