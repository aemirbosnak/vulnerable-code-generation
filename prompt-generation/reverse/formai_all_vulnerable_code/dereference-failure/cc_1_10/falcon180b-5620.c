//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_BASE_TYPES 4

// Define the base types
#define A 0
#define C 1
#define G 2
#define T 3

// Function to generate a random base
char getRandomBase() {
    int random = rand() % MAX_BASE_TYPES;
    switch (random) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
    }
}

// Function to generate a random DNA sequence
void generateSequence(char* sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = getRandomBase();
    }
    sequence[length] = '\0';
}

// Function to print a DNA sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

// Function to simulate genome sequencing
void simulateSequencing(char* sequence, int coverage, FILE* output) {
    int numReads = 0;
    while (numReads < coverage) {
        int readLength = rand() % (MAX_SEQUENCE_LENGTH / 2) + 1;
        int startIndex = rand() % (MAX_SEQUENCE_LENGTH - readLength);
        char* readSequence = malloc(readLength + 1);
        generateSequence(readSequence, readLength);
        fprintf(output, ">Read_%d\n%s\n", numReads + 1, readSequence);
        free(readSequence);
        numReads++;
    }
}

int main() {
    srand(time(NULL));

    char* referenceSequence = malloc(MAX_SEQUENCE_LENGTH + 1);
    generateSequence(referenceSequence, MAX_SEQUENCE_LENGTH);

    FILE* outputFile = fopen("output.txt", "w");

    printf("Reference sequence:\n");
    printSequence(referenceSequence);

    simulateSequencing(referenceSequence, 10, outputFile);

    fclose(outputFile);

    free(referenceSequence);

    return 0;
}