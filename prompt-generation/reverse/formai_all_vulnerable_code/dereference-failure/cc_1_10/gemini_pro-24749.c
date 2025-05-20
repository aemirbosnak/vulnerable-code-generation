//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define READ_LENGTH 100
#define NUM_READS 10000
#define GENOME_SIZE 1000000

// Types
typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} Reads;

// Function prototypes
Reads *generate_reads(int num_reads, int read_length);
void print_reads(Reads *reads);
void free_reads(Reads *reads);

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate the reads
    Reads *reads = generate_reads(NUM_READS, READ_LENGTH);

    // Print the reads
    print_reads(reads);

    // Free the reads
    free_reads(reads);

    return 0;
}

// Generate reads function
Reads *generate_reads(int num_reads, int read_length) {
    // Allocate memory for the reads
    Reads *reads = malloc(sizeof(Reads));
    reads->reads = malloc(sizeof(Read) * num_reads);

    // Generate the reads
    for (int i = 0; i < num_reads; i++) {
        // Allocate memory for the read
        reads->reads[i].sequence = malloc(sizeof(char) * read_length);

        // Generate the read
        for (int j = 0; j < read_length; j++) {
            reads->reads[i].sequence[j] = rand() % 4 + 'A';
        }

        // Set the read length
        reads->reads[i].length = read_length;
    }

    // Set the number of reads
    reads->num_reads = num_reads;

    // Return the reads
    return reads;
}

// Print reads function
void print_reads(Reads *reads) {
    // Print the reads
    for (int i = 0; i < reads->num_reads; i++) {
        printf("%s\n", reads->reads[i].sequence);
    }
}

// Free reads function
void free_reads(Reads *reads) {
    // Free the reads
    for (int i = 0; i < reads->num_reads; i++) {
        free(reads->reads[i].sequence);
    }

    // Free the reads structure
    free(reads->reads);
    free(reads);
}