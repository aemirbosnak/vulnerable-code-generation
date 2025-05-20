//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_READS 1000000
#define MAX_GENOME_LENGTH 10000000

// Function to generate a random DNA sequence
char *generateRandomDNA(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int randomNucleotide = rand() % 4;
        switch (randomNucleotide) {
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

// Function to simulate sequencing reads from a DNA sequence
char **simulateSequencingReads(char *genome, int readLength, int numReads) {
    char **reads = malloc(numReads * sizeof(char *));
    for (int i = 0; i < numReads; i++) {
        int startPosition = rand() % (strlen(genome) - readLength);
        reads[i] = malloc(readLength + 1);
        strncpy(reads[i], genome + startPosition, readLength);
        reads[i][readLength] = '\0';
    }
    return reads;
}

// Function to print the DNA sequence and sequencing reads
void printResults(char *genome, char **reads, int numReads) {
    printf("Genome:\n%s\n", genome);
    printf("Sequencing Reads:\n");
    for (int i = 0; i < numReads; i++) {
        printf("%s\n", reads[i]);
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence
    char *genome = generateRandomDNA(MAX_GENOME_LENGTH);

    // Simulate sequencing reads from the DNA sequence
    char **reads = simulateSequencingReads(genome, MAX_READ_LENGTH, MAX_READS);

    // Print the DNA sequence and sequencing reads
    printResults(genome, reads, MAX_READS);

    // Free the allocated memory
    free(genome);
    for (int i = 0; i < MAX_READS; i++) {
        free(reads[i]);
    }
    free(reads);

    return 0;
}