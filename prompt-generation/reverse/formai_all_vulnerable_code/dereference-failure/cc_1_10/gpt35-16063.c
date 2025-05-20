//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define nucleotide characters
#define A 'A'
#define T 'T'
#define C 'C'
#define G 'G'

// Define array of nucleotide characters
char nucleotides[] = { A, T, C, G };

// Define structure to store genome
typedef struct {
    char *sequence;
    int length;
} Genome;

// Function to generate random nucleotide
char random_nucleotide() {
    int rand_idx = rand() % 4;
    return nucleotides[rand_idx];
}

// Function to generate random genome
Genome random_genome(int length) {
    Genome genome;
    genome.sequence = (char *)malloc(sizeof(char) * length);
    genome.length = length;
    for (int i = 0; i < length; i++) {
        genome.sequence[i] = random_nucleotide();
    }
    return genome;
}

// Function to print genome sequence
void print_genome_sequence(Genome genome) {
    printf("%s\n", genome.sequence);
}

// Function to simulate genome sequencing
Genome simulate_genome_sequencing(Genome genome, int coverage) {
    Genome sequencing;
    sequencing.sequence = (char *)malloc(sizeof(char) * genome.length * coverage);
    sequencing.length = genome.length * coverage;
    for (int i = 0; i < sequencing.length; i++) {
        int genome_idx = i / coverage;
        char nucleotide = genome.sequence[genome_idx];
        sequencing.sequence[i] = nucleotide;
    }
    return sequencing;
}

int main() {
    srand(time(NULL));
    Genome genome = random_genome(50);
    print_genome_sequence(genome);
    Genome sequencing = simulate_genome_sequencing(genome, 20);
    print_genome_sequence(sequencing);
    free(genome.sequence);
    free(sequencing.sequence);
    return 0;
}