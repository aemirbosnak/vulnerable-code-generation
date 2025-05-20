//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to generate random DNA bases A, C, G, T
char generateRandomBase() {
    char bases[] = {'A', 'C', 'G', 'T'};
    int index = rand() % 4;
    return bases[index];
}

// Function to generate random DNA sequence of length n
char* generateRandomDNASequence(int n) {
    char* sequence = malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        sequence[i] = generateRandomBase();
    }
    return sequence;
}

// Function to initialize the genome with a random sequence
char* initializeGenome(int n) {
    char* genome = malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        genome[i] = generateRandomBase();
    }
    return genome;
}

// Function to simulate a genome mutation at a random index
char* simulateMutation(char* genome, int n) {
    int index = rand() % n;
    char base = generateRandomBase();
    genome[index] = base;
    return genome;
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate random DNA sequence of length 1000
    int n = 1000;
    char* sequence = generateRandomDNASequence(n);
    
    // Print DNA sequence
    printf("DNA sequence:\n%s\n\n", sequence);
    
    // Initialize genome with random sequence
    char* genome = initializeGenome(n);
    
    // Print original genome
    printf("Original genome:\n%s\n\n", genome);
    
    // Simulate mutation in genome
    genome = simulateMutation(genome, n);
    
    // Print mutated genome
    printf("Mutated genome:\n%s\n", genome);
    
    return 0;
}