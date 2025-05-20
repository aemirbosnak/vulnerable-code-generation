//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 1000
#define MAX_NUM_READS 1000000

// Function to generate a random DNA sequence of length 'length'
char* generateRandomDNASequence(int length) {
    // Array to store the DNA sequence
    char* sequence = malloc(length + 1);

    // Seed the random number generator
    srand(time(NULL));

    // Generate the DNA sequence
    for (int i = 0; i < length; i++) {
        // Generate a random number between 0 and 3
        int randomNum = rand() % 4;

        // Add the corresponding nucleotide to the sequence
        switch (randomNum) {
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

    // Terminate the string with a null character
    sequence[length] = '\0';

    // Return the DNA sequence
    return sequence;
}

// Function to simulate the sequencing process
char** simulateSequencing(char* genome, int readLength, int numReads) {
    // Array to store the simulated reads
    char** reads = malloc(numReads * sizeof(char*));

    // Generate the simulated reads
    for (int i = 0; i < numReads; i++) {
        // Generate a random starting position for the read
        int startPos = rand() % (strlen(genome) - readLength);

        // Get the substring of the genome at the starting position
        char* read = malloc(readLength + 1);
        strncpy(read, genome + startPos, readLength);

        // Terminate the string with a null character
        read[readLength] = '\0';

        // Add the read to the array
        reads[i] = read;
    }

    // Return the simulated reads
    return reads;
}

// Function to print the simulated reads
void printSimulatedReads(char** reads, int numReads) {
    for (int i = 0; i < numReads; i++) {
        printf("%s\n", reads[i]);
    }
}

// Function to free the memory allocated for the simulated reads
void freeSimulatedReads(char** reads, int numReads) {
    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);
}

// Main function
int main() {
    // Generate a random DNA sequence of length 100000
    char* genome = generateRandomDNASequence(100000);

    // Simulate the sequencing process with a read length of 100 and 10000 reads
    char** reads = simulateSequencing(genome, 100, 10000);

    // Print the simulated reads
    printSimulatedReads(reads, 10000);

    // Free the memory allocated for the simulated reads
    freeSimulatedReads(reads, 10000);

    // Free the memory allocated for the genome
    free(genome);

    return 0;
}