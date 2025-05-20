//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000

// Structure to represent a DNA read
typedef struct {
    char *sequence;
    int length;
} Read;

// Function to generate a random DNA sequence
char *generate_random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = "ACGT"[rand() % 4];
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to simulate the sequencing process
Read *simulate_sequencing(int num_reads, int read_length) {
    Read *reads = malloc(num_reads * sizeof(Read));
    for (int i = 0; i < num_reads; i++) {
        reads[i].sequence = generate_random_sequence(read_length);
        reads[i].length = read_length;
    }
    return reads;
}

// Function to write the reads to a file
void write_reads_to_file(Read *reads, int num_reads, char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < num_reads; i++) {
        fprintf(file, "%s\n", reads[i].sequence);
    }
    fclose(file);
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Simulate the sequencing process
    int num_reads = 1000;
    int read_length = 100;
    Read *reads = simulate_sequencing(num_reads, read_length);

    // Write the reads to a file
    char *filename = "reads.txt";
    write_reads_to_file(reads, num_reads, filename);

    // Free the memory allocated for the reads
    for (int i = 0; i < num_reads; i++) {
        free(reads[i].sequence);
    }
    free(reads);

    return 0;
}