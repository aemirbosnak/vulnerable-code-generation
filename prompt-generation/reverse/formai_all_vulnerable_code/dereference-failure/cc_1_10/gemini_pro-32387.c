//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000
#define MAX_GENOME_LENGTH 1000000

// Function to generate a random DNA sequence
char* generate_dna_sequence(int length) {
    char* sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int random_number = rand() % 4;
        switch (random_number) {
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

// Function to generate a set of paired-end reads from a DNA sequence
struct read_pair {
    char* read1;
    char* read2;
};

struct read_pair* generate_read_pairs(char* sequence, int num_reads, int read_length) {
    struct read_pair* reads = malloc(num_reads * sizeof(struct read_pair));
    for (int i = 0; i < num_reads; i++) {
        // Generate a random start position for the read pair
        int start_position = rand() % (strlen(sequence) - 2 * read_length);

        // Generate the first read
        reads[i].read1 = malloc(read_length + 1);
        strncpy(reads[i].read1, sequence + start_position, read_length);
        reads[i].read1[read_length] = '\0';

        // Generate the second read
        reads[i].read2 = malloc(read_length + 1);
        strncpy(reads[i].read2, sequence + start_position + read_length, read_length);
        reads[i].read2[read_length] = '\0';
    }
    return reads;
}

// Function to write the reads to a FASTA file
void write_reads_to_fasta(struct read_pair* reads, int num_reads, char* filename) {
    FILE* fp = fopen(filename, "w");
    for (int i = 0; i < num_reads; i++) {
        fprintf(fp, ">Read_pair%d\n", i + 1);
        fprintf(fp, "%s\n", reads[i].read1);
        fprintf(fp, "%s\n", reads[i].read2);
    }
    fclose(fp);
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random DNA sequence
    char* sequence = generate_dna_sequence(MAX_GENOME_LENGTH);

    // Generate a set of paired-end reads from the DNA sequence
    struct read_pair* reads = generate_read_pairs(sequence, MAX_NUM_READS, MAX_READ_LENGTH);

    // Write the reads to a FASTA file
    write_reads_to_fasta(reads, MAX_NUM_READS, "reads.fasta");

    // Free the allocated memory
    free(sequence);
    for (int i = 0; i < MAX_NUM_READS; i++) {
        free(reads[i].read1);
        free(reads[i].read2);
    }
    free(reads);

    return 0;
}