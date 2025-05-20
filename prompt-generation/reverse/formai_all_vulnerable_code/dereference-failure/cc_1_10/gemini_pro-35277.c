//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    // Check if the user has provided enough arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <reference genome> <read length> <number of reads>\n", argv[0]);
        return 1;
    }

    // Read the reference genome into memory
    FILE* reference_genome_file = fopen(argv[1], "r");
    if (reference_genome_file == NULL) {
        fprintf(stderr, "Error: could not open reference genome file\n");
        return 1;
    }
    char* reference_genome = malloc(BUFFER_SIZE);
    while (fgets(reference_genome, BUFFER_SIZE, reference_genome_file) != NULL) {
        // Remove the newline character from the end of the line
        reference_genome[strlen(reference_genome) - 1] = '\0';
    }
    fclose(reference_genome_file);
    printf("read %s length %lu\n", argv[1], strlen(reference_genome));

    // Get the read length from the user
    int read_length = atoi(argv[2]);
    if (read_length <= 0) {
        fprintf(stderr, "Error: invalid read length\n");
        free(reference_genome);
        return 1;
    }
    printf("read len %d\n", read_length);

    // Get the number of reads from the user
    int number_of_reads = atoi(argv[3]);
    if (number_of_reads <= 0) {
        fprintf(stderr, "Error: invalid number of reads\n");
        free(reference_genome);
        return 1;
    }
    printf("reads %d\n", number_of_reads);

    // Seed the random number generator
    srand(time(NULL));

    // Generate the reads
    int i;
    char* reads[number_of_reads];
    for (i = 0; i < number_of_reads; i++) {
        // Get a random starting position for the read
        int start_position = rand() % (strlen(reference_genome) - read_length + 1);

        // Get the read sequence from the reference genome
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], reference_genome + start_position, read_length);
        reads[i][read_length] = '\0';
        printf("read %05d %s\n", i, reads[i]);
    }

    return 0;
}