//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Random DNA sequence generator
char* generate_dna(int length) {
    char* dna = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        switch (rand() % 4) {
            case 0: dna[i] = 'A'; break;
            case 1: dna[i] = 'C'; break;
            case 2: dna[i] = 'G'; break;
            case 3: dna[i] = 'T'; break;
        }
    }
    dna[length] = '\0';
    return dna;
}

// DNA sequence simulator
int main(int argc, char** argv) {
    // Set up random seed
    srand(time(NULL));

    // Get command line arguments
    int length = 100;
    int num_reads = 1000;
    int read_length = 100;
    int error_rate = 1;

    // Generate DNA sequence
    char* dna = generate_dna(length);

    // Generate reads
    char** reads = malloc(num_reads * sizeof(char*));
    for (int i = 0; i < num_reads; i++) {
        // Start position
        int start = rand() % (length - read_length + 1);

        // Generate read
        reads[i] = malloc(read_length + 1);
        strncpy(reads[i], dna + start, read_length);
        reads[i][read_length] = '\0';

        // Introduce errors
        for (int j = 0; j < read_length; j++) {
            if (rand() % 100 < error_rate) {
                switch (rand() % 4) {
                    case 0: reads[i][j] = 'A'; break;
                    case 1: reads[i][j] = 'C'; break;
                    case 2: reads[i][j] = 'G'; break;
                    case 3: reads[i][j] = 'T'; break;
                }
            }
        }
    }

    // Print reads
    for (int i = 0; i < num_reads; i++) {
        printf("%s\n", reads[i]);
    }

    // Clean up
    free(dna);
    for (int i = 0; i < num_reads; i++) {
        free(reads[i]);
    }
    free(reads);
    return 0;
}