//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUCLEOTIDES "ACGT"

// Generate a random DNA sequence of length n.
char *generate_dna(int n) {
    char *dna = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        dna[i] = NUCLEOTIDES[rand() % 4];
    }
    dna[n] = '\0';
    return dna;
}

// Read a DNA sequence from a file.
char *read_dna(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    char *dna = malloc(size + 1);
    fread(dna, 1, size, fp);
    dna[size] = '\0';

    fclose(fp);

    return dna;
}

// Write a DNA sequence to a file.
void write_dna(char *dna, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fp, "%s\n", dna);

    fclose(fp);
}

// Main function.
int main(int argc, char *argv[]) {
    // Seed the random number generator.
    srand(time(NULL));

    // Check the command line arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <n> <filename>\n", argv[0]);
        return 1;
    }

    // Get the length of the DNA sequence.
    int n = atoi(argv[1]);

    // Generate a DNA sequence.
    char *dna = generate_dna(n);

    // Write the DNA sequence to a file.
    write_dna(dna, argv[2]);

    // Free the memory allocated for the DNA sequence.
    free(dna);

    return 0;
}