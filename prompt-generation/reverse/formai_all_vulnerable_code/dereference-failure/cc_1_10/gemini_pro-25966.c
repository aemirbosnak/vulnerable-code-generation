//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome
#define GENOME_LENGTH 1000000

// Define the number of reads
#define NUM_READS 10000

// Define the maximum read length
#define MAX_READ_LENGTH 100

// Generate a random nucleotide
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

// Generate a random read
char* random_read() {
    int length = rand() % MAX_READ_LENGTH + 1;
    char* read = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        read[i] = random_nucleotide();
    }
    read[length] = '\0';
    return read;
}

// Generate a genome
char* generate_genome() {
    char* genome = malloc(GENOME_LENGTH + 1);
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = random_nucleotide();
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

// Simulate sequencing the genome
char** simulate_sequencing(char* genome) {
    char** reads = malloc(NUM_READS * sizeof(char*));
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = random_read();
    }
    return reads;
}

// Print the genome
void print_genome(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

// Print the reads
void print_reads(char** reads) {
    for (int i = 0; i < NUM_READS; i++) {
        printf("%s\n", reads[i]);
    }
}

// Free the memory allocated for the genome and reads
void free_genome_and_reads(char* genome, char** reads) {
    free(genome);
    for (int i = 0; i < NUM_READS; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate the genome
    char* genome = generate_genome();

    // Simulate sequencing the genome
    char** reads = simulate_sequencing(genome);

    // Print the genome
    printf("Genome:\n");
    print_genome(genome);

    // Print the reads
    printf("\nReads:\n");
    print_reads(reads);

    // Free the memory allocated for the genome and reads
    free_genome_and_reads(genome, reads);

    return 0;
}