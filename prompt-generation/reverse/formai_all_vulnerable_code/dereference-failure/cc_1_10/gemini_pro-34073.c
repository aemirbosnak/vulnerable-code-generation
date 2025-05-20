//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUMBER_OF_READS 100000
#define MAX_READ_LENGTH 100

// Define the structure of a read.
typedef struct {
    char *sequence;
    int length;
} Read;

// Define the structure of a genome.
typedef struct {
    char *sequence;
    int length;
} Genome;

// Generate a random sequence of nucleotides.
char *generateRandomSequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = "ACGT"[rand() % 4];
    }
    sequence[length] = '\0';
    return sequence;
}

// Generate a random read from a genome.
Read generateRandomRead(Genome *genome) {
    Read read;
    read.length = rand() % (genome->length - MAX_READ_LENGTH) + MAX_READ_LENGTH;
    read.sequence = malloc(read.length + 1);
    for (int i = 0; i < read.length; i++) {
        read.sequence[i] = genome->sequence[rand() % genome->length];
    }
    read.sequence[read.length] = '\0';
    return read;
}

// Generate a set of reads from a genome.
Read *generateReads(Genome *genome, int number_of_reads) {
    Read *reads = malloc(number_of_reads * sizeof(Read));
    for (int i = 0; i < number_of_reads; i++) {
        reads[i] = generateRandomRead(genome);
    }
    return reads;
}

// Write a set of reads to a file.
void writeReadsToFile(Read *reads, int number_of_reads, char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < number_of_reads; i++) {
        fprintf(file, ">read%d\n", i);
        fprintf(file, "%s\n", reads[i].sequence);
    }
    fclose(file);
}

// Generate a genome.
Genome generateGenome(int length) {
    Genome genome;
    genome.length = length;
    genome.sequence = generateRandomSequence(length);
    return genome;
}

// Write a genome to a file.
void writeGenomeToFile(Genome *genome, char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, ">genome\n");
    fprintf(file, "%s\n", genome->sequence);
    fclose(file);
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user specified the correct number of arguments.
    if (argc != 5) {
        printf("Usage: %s <genome_length> <number_of_reads> <output_reads_file> <output_genome_file>\n", argv[0]);
        return 1;
    }

    // Get the genome length, number of reads, output reads file, and output genome file from the command line arguments.
    int genome_length = atoi(argv[1]);
    int number_of_reads = atoi(argv[2]);
    char *output_reads_file = argv[3];
    char *output_genome_file = argv[4];

    // Generate a genome.
    Genome genome = generateGenome(genome_length);

    // Generate a set of reads from the genome.
    Read *reads = generateReads(&genome, number_of_reads);

    // Write the reads to a file.
    writeReadsToFile(reads, number_of_reads, output_reads_file);

    // Write the genome to a file.
    writeGenomeToFile(&genome, output_genome_file);

    // Free the memory allocated for the genome and the reads.
    free(genome.sequence);
    for (int i = 0; i < number_of_reads; i++) {
        free(reads[i].sequence);
    }
    free(reads);

    return 0;
}