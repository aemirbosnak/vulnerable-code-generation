//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Initialize the random number generator
void init_rand() {
    srand(time(NULL));
}

// Generate a random base (A, C, G, or T)
char get_random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
        default: return 'N';
    }
}

// Generate a random sequence of bases of a given length
char *get_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = get_random_base();
    }
    sequence[length] = '\0';
    return sequence;
}

// Compare two sequences and return the number of mismatches
int compare_sequences(char *seq1, char *seq2) {
    int mismatches = 0;
    for (int i = 0; i < strlen(seq1); i++) {
        if (seq1[i] != seq2[i]) {
            mismatches++;
        }
    }
    return mismatches;
}

// Simulate the sequencing of a genome
void simulate_sequencing(char *genome, int read_length) {
    // Generate a set of random reads from the genome
    int num_reads = 1000;
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = get_random_sequence(read_length);
    }

    // Compare each read to the genome and count the number of mismatches
    int total_mismatches = 0;
    for (int i = 0; i < num_reads; i++) {
        total_mismatches += compare_sequences(reads[i], genome);
    }

    // Calculate the average number of mismatches per read
    double avg_mismatches = (double)total_mismatches / num_reads;

    // Print the results
    printf("Simulated sequencing of a genome of length %d:\n", strlen(genome));
    printf("Number of reads: %d\n", num_reads);
    printf("Read length: %d\n", read_length);
    printf("Average number of mismatches per read: %.2f\n", avg_mismatches);
}

int main() {
    // Initialize the random number generator
    init_rand();

    // Create a random genome
    int genome_length = 1000000;
    char *genome = get_random_sequence(genome_length);

    // Simulate the sequencing of the genome with different read lengths
    int read_lengths[] = {50, 100, 150, 200};
    for (int i = 0; i < 4; i++) {
        simulate_sequencing(genome, read_lengths[i]);
    }

    return 0;
}