//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of possible nucleotides
#define NUM_NUCLEOTIDES 4

// Define the nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Define the structure of a genome
typedef struct {
    char *sequence;
    int length;
} Genome;

// Function to generate a random nucleotide
char generate_nucleotide() {
    return nucleotides[rand() % NUM_NUCLEOTIDES];
}

// Function to generate a random genome of the given length
Genome generate_genome(int length) {
    Genome genome;
    genome.sequence = calloc(length + 1, sizeof(char));
    genome.length = length;
    for (int i = 0; i < length; i++) {
        genome.sequence[i] = generate_nucleotide();
    }
    return genome;
}

// Function to print a genome
void print_genome(Genome genome) {
    printf("Genome: %s\n", genome.sequence);
    printf("Length: %d\n", genome.length);
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(Genome genome, int read_length) {
    int num_reads = (genome.length + read_length - 1) / read_length;
    for (int i = 0; i < num_reads; i++) {
        int start_index = i * read_length;
        int end_index = start_index + read_length - 1;
        if (end_index >= genome.length) {
            end_index = genome.length - 1;
        }
        char *read = calloc(read_length + 1, sizeof(char));
        for (int j = 0; j < read_length; j++) {
            read[j] = genome.sequence[start_index + j];
        }
        printf("Read %d: %s\n", i + 1, read);
        free(read);
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Generate a random genome
    Genome genome = generate_genome(GENOME_SIZE);
    print_genome(genome);

    // Simulate genome sequencing with a read length of 100
    simulate_genome_sequencing(genome, 100);

    return 0;
}