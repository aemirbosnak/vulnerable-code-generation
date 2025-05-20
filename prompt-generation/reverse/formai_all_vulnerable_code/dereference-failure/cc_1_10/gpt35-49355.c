//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the DNA base pairs
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_GENOME_LENGTH 100

// Define the error probability
#define ERROR_PROBABILITY 0.05

// Define the possible modes of the Simulator
#define MODE_RANDOM 0
#define MODE_FILE 1

// Define the mode of operation and the genome to use
int mode = MODE_RANDOM;
char genome[MAX_GENOME_LENGTH];

// Define helper function that generates a random DNA base pair
char generateRandomBasePair() {
    int r = rand() % 4;
    switch(r) {
        case 0:
            return A;
        case 1:
            return C;
        case 2:
            return G;
        default:
            return T;
    }
}

// Define the main function
int main(int argc, char** argv) {

    // Check the arguments passed to the program
    if(argc < 2) {
        printf("Usage: ./genome_sequencer [mode] [filename (optional)]\n");
        return 0;
    }

    // Parse the arguments
    mode = atoi(argv[1]);

    // Generate a random genome.
    // This mode assumes the user wants to sequence a random genome
    if(mode == MODE_RANDOM) {
        // Generate a random genome with a maximum length of MAX_GENOME_LENGTH
        for(int i = 0; i < MAX_GENOME_LENGTH; i++) {
            genome[i] = generateRandomBasePair();
        }
    }

    // Read a genome from a file.
    // This mode assumes the user wants to sequence a specific genome from a file
    else if(mode == MODE_FILE) {

        // Check if a filename was provided
        if(argc < 3) {
            printf("Error: Missing filename.\n");
            return 1;
        }

        // Open the file for reading
        FILE* fp = fopen(argv[2], "r");

        // Check if the file was successfully opened
        if(fp == NULL) {
            printf("Error: Could not open file '%s'.\n", argv[2]);
            return 1;
        }

        // Read the genome from the file
        char c;
        int i = 0;
        while((c = fgetc(fp)) != EOF && i < MAX_GENOME_LENGTH) {
            genome[i] = c;
            i++;
        }
        fclose(fp);
    }

    // Unknown mode
    else {
        printf("Error: Unknown mode.\n");
        return 1;
    }

    // Print the original genome
    printf("Original genome:\n");
    for(int i = 0; i < MAX_GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");

    // Simulate sequencing errors
    for(int i = 0; i < MAX_GENOME_LENGTH; i++) {
        if(rand() / (float)RAND_MAX <= ERROR_PROBABILITY) {
            genome[i] = generateRandomBasePair();
        }
    }

    // Print the sequenced genome
    printf("Sequenced genome:\n");
    for(int i = 0; i < MAX_GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }

    return 0;
}