//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the read length
#define READ_LENGTH 100

// Define the number of reads
#define NUM_READS 1000

// Generate a random nucleotide base
char generate_base() {
    int random_num = rand() % 4;
    switch (random_num) {
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
char *generate_read() {
    char *read = malloc(READ_LENGTH + 1);
    for (int i = 0; i < READ_LENGTH; i++) {
        read[i] = generate_base();
    }
    read[READ_LENGTH] = '\0';
    return read;
}

// Generate a list of reads
char **generate_reads(int num_reads) {
    char **reads = malloc(num_reads * sizeof(char *));
    for (int i = 0; i < num_reads; i++) {
        reads[i] = generate_read();
    }
    return reads;
}

// Print a list of reads
void print_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Free the memory allocated for a list of reads
void free_reads(char **reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a list of reads
    char **reads = generate_reads(NUM_READS);

    // Print the list of reads
    print_reads(reads, NUM_READS);

    // Free the memory allocated for the list of reads
    free_reads(reads, NUM_READS);

    return 0;
}