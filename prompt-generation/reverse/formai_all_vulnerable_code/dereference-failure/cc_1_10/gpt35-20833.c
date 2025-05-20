//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000

// Function to generate a random DNA sequence of given length
char* generate_DNA_sequence(int length) {
    const char* nucleotides = "ATCG";
    char* sequence = malloc(sizeof(char) * length);
    for (int i=0; i<length; i++) {
        int index = rand() % 4;
        sequence[i] = nucleotides[index];
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to simulate genome sequencing
int* simulate_genome_sequencing(char* genome, int genome_length, int read_length, float error_probability) {
    int num_reads = genome_length / read_length; // Total number of reads required
    int* read_counts = calloc(genome_length, sizeof(int)); // Array to store count of reads at each position
    for (int i=0; i<num_reads; i++) {
        int start_index = i * read_length; // Starting index of current read
        int end_index = start_index + read_length - 1; // Ending index of current read
        if (end_index >= (genome_length-1)) { // Ignore reads that go beyond the end of genome
            continue;
        }
        char* read = malloc(sizeof(char) * read_length); // Allocate memory for current read
        strncpy(read, genome+start_index, read_length); // Extract the read from genome
        for (int j=0; j<read_length; j++) {
            if ((float)rand()/(float)RAND_MAX <= error_probability) { // Simulate sequencing errors with given probability
                int index = rand() % 4; // Randomly select a nucleotide
                read[j] = (index == 0 ? 'A' : (index == 1 ? 'T' : (index == 2 ? 'C' : 'G'))); // Replace original nucleotide with new one
            }
            int index = start_index + j;
            read_counts[index]++; // Increment read count for the current position in genome
        }
        free(read); // Free memory allocated for current read
    }
    return read_counts;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate a random DNA sequence of length MAX_GENOME_SIZE
    char* genome = generate_DNA_sequence(MAX_GENOME_SIZE);

    // Set the parameters for genome sequencing
    int read_length = 100;
    float error_probability = 0.05;

    // Simulate genome sequencing
    int* read_counts = simulate_genome_sequencing(genome, MAX_GENOME_SIZE, read_length, error_probability);

    // Print the read counts for every 100th position in genome
    for (int i=0; i<MAX_GENOME_SIZE; i+=100) {
        printf("%d,", read_counts[i]);
    }

    // Free memory allocated for genome sequence and read counts
    free(genome);
    free(read_counts);

    return 0;
}