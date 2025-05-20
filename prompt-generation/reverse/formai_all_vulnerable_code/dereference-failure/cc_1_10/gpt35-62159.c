//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define BASES "ACGT"

// Function to generate a random genome sequence
char *generate_genome() {
    char *genome = malloc(GENOME_LENGTH+1); // +1 for null terminator
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = BASES[rand() % 4];
    }
    genome[GENOME_LENGTH] = '\0';
    return genome;
}

// Function to simulate DNA sequencing
void dna_sequencing(char *genome, int coverage) {
    int genome_length = strlen(genome);
    int num_reads = coverage * genome_length;
    char **reads = malloc(num_reads * sizeof(char *));

    // Generate reads from genome
    for(int i = 0; i < num_reads; i++) {
        int start_position = rand() % genome_length;
        int read_length = rand() % 50 + 50; // Generate random read length between 50 and 100
        char *read = malloc(read_length+1); // +1 for null terminator
        strncpy(read, genome+start_position, read_length);
        read[read_length] = '\0';
        reads[i] = read;
    }

    // Print out reads
    for(int i = 0; i < num_reads; i++) {
        printf(">Read %d\n%s\n", i+1, reads[i]);
        free(reads[i]);
    }
    free(reads);
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    char *genome = generate_genome();
    int coverage = 10;
    printf("Generated genome:\n%s\n", genome);
    printf("Simulated sequencing at %dx coverage:\n", coverage);
    dna_sequencing(genome, coverage);

    free(genome);
    return 0;
}