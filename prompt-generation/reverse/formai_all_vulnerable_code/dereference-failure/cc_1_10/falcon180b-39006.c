//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the length of the genome
#define GENOME_LENGTH 1000

// Define the length of the read
#define READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 10

// Function to generate a random nucleotide base
int generate_base() {
    int base = rand() % 4;
    return base;
}

// Function to generate a random genome sequence
char* generate_genome() {
    char* genome = (char*) malloc(sizeof(char) * GENOME_LENGTH);
    for (int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = generate_base();
    }
    return genome;
}

// Function to generate a random read sequence
char* generate_read() {
    char* read = (char*) malloc(sizeof(char) * READ_LENGTH);
    for (int i = 0; i < READ_LENGTH; i++) {
        read[i] = generate_base();
    }
    return read;
}

// Function to print the genome sequence
void print_genome(char* genome) {
    for (int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

// Function to print the read sequence
void print_read(char* read) {
    for (int i = 0; i < READ_LENGTH; i++) {
        printf("%c", read[i]);
    }
    printf("\n");
}

// Function to overlap the reads
void overlap_reads(char* genome, char** reads, int num_reads) {
    for (int i = 0; i < num_reads; i++) {
        printf("Overlapping read %d:\n", i+1);
        for (int j = 0; j < READ_LENGTH; j++) {
            if (reads[i][j] == genome[j]) {
                printf("%c", reads[i][j]);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Generate the genome sequence
    char* genome = generate_genome();
    print_genome(genome);

    // Generate the read sequences
    char** reads = (char**) malloc(sizeof(char*) * NUM_READS);
    for (int i = 0; i < NUM_READS; i++) {
        reads[i] = generate_read();
        printf("Read %d: ", i+1);
        print_read(reads[i]);
    }

    // Overlap the reads
    overlap_reads(genome, reads, NUM_READS);

    return 0;
}