//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random nucleotide
char generate_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

// Function to generate a random DNA sequence
char *generate_dna_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = generate_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to write a DNA sequence to a file
void write_dna_sequence(char *sequence, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(fp, "%s", sequence);
    fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided a length for the DNA sequence
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <length>\n", argv[0]);
        exit(1);
    }

    // Convert the length to an integer
    int length = atoi(argv[1]);

    // Generate a random DNA sequence
    char *sequence = generate_dna_sequence(length);

    // Write the DNA sequence to a file
    write_dna_sequence(sequence, "sequence.txt");

    // Free the memory allocated for the DNA sequence
    free(sequence);

    return 0;
}