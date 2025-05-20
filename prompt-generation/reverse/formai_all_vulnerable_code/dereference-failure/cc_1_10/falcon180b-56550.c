//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

// Function to generate a random DNA sequence
char* generateRandomSequence(int length) {
    char* sequence = (char*) malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        sequence[i] = (char) ('A' + rand() % 4);
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a DNA sequence
void printSequence(char* sequence) {
    for (int i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Function to simulate genome sequencing
void simulateSequencing(char* genome, int readLength) {
    srand(time(NULL));
    int numReads = (int) ((double) strlen(genome) / (double) readLength);
    for (int i = 0; i < numReads; i++) {
        int startIndex = rand() % (strlen(genome) - readLength);
        char* read = (char*) malloc(sizeof(char) * (readLength + 1));
        strncpy(read, genome + startIndex, readLength);
        read[readLength] = '\0';
        printf("Read %d: %s\n", i + 1, read);
        free(read);
    }
}

int main() {
    // Generate a random DNA sequence
    char* genome = generateRandomSequence(MAX_SEQUENCE_LENGTH);
    printf("Genome:\n");
    printSequence(genome);

    // Simulate genome sequencing with 100-bp reads
    simulateSequencing(genome, 100);

    return 0;
}