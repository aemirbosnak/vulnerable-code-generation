//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define GENOME_SIZE 1000000
#define READ_LENGTH 100
#define COVERAGE 10

// Nucleotide codes
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Function to generate a random nucleotide
char random_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        case 3:
            return T;
    }
}

// Function to generate a random genome
char* generate_genome() {
    char* genome = malloc(GENOME_SIZE + 1);
    for (int i = 0; i < GENOME_SIZE; i++) {
        genome[i] = random_nucleotide();
    }
    genome[GENOME_SIZE] = '\0';
    return genome;
}

// Function to generate a random read
char* generate_read(char* genome) {
    int start = rand() % (GENOME_SIZE - READ_LENGTH + 1);
    char* read = malloc(READ_LENGTH + 1);
    for (int i = 0; i < READ_LENGTH; i++) {
        read[i] = genome[start + i];
    }
    read[READ_LENGTH] = '\0';
    return read;
}

// Function to simulate genome sequencing
void simulate_genome_sequencing() {
    // Generate a random genome
    char* genome = generate_genome();

    // Generate a set of reads
    char** reads = malloc(COVERAGE * GENOME_SIZE / READ_LENGTH * sizeof(char*));
    for (int i = 0; i < COVERAGE * GENOME_SIZE / READ_LENGTH; i++) {
        reads[i] = generate_read(genome);
    }

    // Print the reads
    for (int i = 0; i < COVERAGE * GENOME_SIZE / READ_LENGTH; i++) {
        printf("%s\n", reads[i]);
    }

    // Free memory
    free(genome);
    for (int i = 0; i < COVERAGE * GENOME_SIZE / READ_LENGTH; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Simulate genome sequencing
    simulate_genome_sequencing();

    return 0;
}