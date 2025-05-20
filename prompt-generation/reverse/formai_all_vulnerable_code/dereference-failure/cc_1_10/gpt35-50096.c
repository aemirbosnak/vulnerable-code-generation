//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define nucleotide characters
#define NUCLEOTIDES "ACGT"

// Define genome length
#define GENOME_LENGTH 1000

// Function to generate a random nucleotide
char get_random_nucleotide() {
    int index = rand() % 4;
    return NUCLEOTIDES[index];
}

// Function to generate a random genome
char* generate_genome(int length) {
    char* genome = (char*)malloc(length * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        genome[i] = get_random_nucleotide();
    }
    genome[length] = '\0';
    return genome;
}

// Function to print a genome
void print_genome(char* genome) {
    printf("%s\n", genome);
}

// Function to check if two genomes are equal
int are_equal(char* genome1, char* genome2) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        if (genome1[i] != genome2[i]) {
            return 0;
        }
    }
    return 1;
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(char* genome) {
    int i;
    for (i = 0; i < GENOME_LENGTH; i++) {
        // Generate a random error rate between 0 and 1
        float error_rate = (float)rand() / RAND_MAX;
        if (error_rate < 0.01) { // Simulate a sequencing error
            char wrong_nucleotide = get_random_nucleotide();
            while (wrong_nucleotide == genome[i]) {
                wrong_nucleotide = get_random_nucleotide();
            }
            printf("%c", wrong_nucleotide);
        } else { // Print the correct nucleotide
            printf("%c", genome[i]);
        }
    }
    printf("\n");
}

int main() {
    srand(time(0)); // Seed the random number generator
    char* genome = generate_genome(GENOME_LENGTH);
    printf("Original genome:\n");
    print_genome(genome);
    printf("Sequenced genome:\n");
    simulate_genome_sequencing(genome);
    free(genome);
    return 0;
}