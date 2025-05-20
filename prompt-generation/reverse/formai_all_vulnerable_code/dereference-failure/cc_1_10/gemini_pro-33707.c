//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Read;

// Function to generate a random DNA sequence of a given length
char *generate_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
        }
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to generate a set of reads from a given genome sequence
Read *generate_reads(char *genome, int num_reads) {
    Read *reads = malloc(num_reads * sizeof(Read));
    for (int i = 0; i < num_reads; i++) {
        int start = rand() % (strlen(genome) - MAX_READ_LENGTH);
        int length = rand() % (MAX_READ_LENGTH - 1) + 1;
        reads[i].sequence = malloc(length + 1);
        strncpy(reads[i].sequence, genome + start, length);
        reads[i].sequence[length] = '\0';
        reads[i].length = length;
    }
    return reads;
}

// Function to simulate the sequencing process
char *sequence_genome(char *genome, int num_reads) {
    // Generate a set of reads from the genome
    Read *reads = generate_reads(genome, num_reads);

    // Assemble the reads into a consensus sequence
    char *consensus = malloc(strlen(genome) + 1);
    for (int i = 0; i < strlen(genome); i++) {
        // Get the most common base at this position in the reads
        int counts[4] = {0, 0, 0, 0};
        for (int j = 0; j < num_reads; j++) {
            if (i < reads[j].length) {
                int base = reads[j].sequence[i] - 'A';
                counts[base]++;
            }
        }
        int max_count = 0;
        int max_base = 0;
        for (int j = 0; j < 4; j++) {
            if (counts[j] > max_count) {
                max_count = counts[j];
                max_base = j;
            }
        }

        // Add the most common base to the consensus sequence
        switch (max_base) {
            case 0:
                consensus[i] = 'A';
                break;
            case 1:
                consensus[i] = 'C';
                break;
            case 2:
                consensus[i] = 'G';
                break;
            case 3:
                consensus[i] = 'T';
                break;
        }
    }
    consensus[strlen(genome)] = '\0';

    // Free the reads
    for (int i = 0; i < num_reads; i++) {
        free(reads[i].sequence);
    }
    free(reads);

    return consensus;
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence
    char *genome = generate_random_sequence(100000);

    // Simulate the sequencing process
    char *consensus = sequence_genome(genome, 10000);

    // Print the consensus sequence
    printf("%s\n", consensus);

    // Free the genome and consensus sequences
    free(genome);
    free(consensus);

    return 0;
}