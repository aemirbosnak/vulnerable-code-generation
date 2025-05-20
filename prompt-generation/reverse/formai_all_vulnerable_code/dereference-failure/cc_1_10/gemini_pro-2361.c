//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define NUCLEOTIDES "ACGT"
#define READ_LENGTH 100
#define COVERAGE 10

// Generates a random sequence of nucleotides
char *generate_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = NUCLEOTIDES[rand() % 4];
    }
    sequence[length] = '\0';
    return sequence;
}

// Simulates the sequencing of a genome
char **sequence_genome(char *genome, int read_length, int coverage) {
    int num_reads = coverage * strlen(genome) / read_length;
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        int start = rand() % (strlen(genome) - read_length);
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], genome + start, read_length);
        reads[i][read_length] = '\0';
    }
    return reads;
}

// Prints the reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Frees the reads
void free_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a genome
    char *genome = generate_sequence(10000);

    // Sequence the genome
    char **reads = sequence_genome(genome, READ_LENGTH, COVERAGE);

    // Print the reads
    print_reads(reads, COVERAGE * strlen(genome) / READ_LENGTH);

    // Free the reads
    free_reads(reads, COVERAGE * strlen(genome) / READ_LENGTH);

    // Free the genome
    free(genome);

    return 0;
}