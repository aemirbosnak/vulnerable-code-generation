//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program simulates the process of genome sequencing by
 * generating random sequenced fragments and assembling them into
 * a complete genome. It takes in user-defined parameters for the
 * length of the genome and the size of the sequenced fragments.
 */

// Function to generate a random DNA sequence
char generate_base() {
    int random_num = rand() % 4;
    switch (random_num) {
        case 0:
            return 'A';
        case 1:
            return 'T';
        case 2:
            return 'C';
        case 3:
            return 'G';
    }
}

// Function to generate a random fragment of DNA sequence
char* generate_fragment(int size) {
    char* fragment = malloc((size + 1) * sizeof(char));
    for (int i = 0; i < size; i++) {
        fragment[i] = generate_base();
    }
    fragment[size] = '\0';
    return fragment;
}

int main() {
    // User-defined parameters
    int genome_length = 100;
    int fragment_size = 10;

    // Generate random genome sequence
    char* genome = malloc((genome_length + 1) * sizeof(char));
    for (int i = 0; i < genome_length; i++) {
        genome[i] = generate_base();
    }
    genome[genome_length] = '\0';
    printf("Original genome sequence: %s\n\n", genome);

    // Generate random fragments of genome sequence
    int num_fragments = genome_length / fragment_size;
    char** fragments = malloc(num_fragments * sizeof(char*));
    for (int i = 0; i < num_fragments; i++) {
        fragments[i] = generate_fragment(fragment_size);
    }

    // Assemble fragments into complete genome sequence
    char* assembled_genome = malloc((genome_length + 1) * sizeof(char));
    for (int i = 0; i < num_fragments; i++) {
        strcat(assembled_genome, fragments[i]);
    }
    printf("Assembled genome sequence: %s\n\n", assembled_genome);

    // Free allocated memory
    free(genome);
    free(assembled_genome);
    for (int i = 0; i < num_fragments; i++) {
        free(fragments[i]);
    }
    free(fragments);

    return 0;
}