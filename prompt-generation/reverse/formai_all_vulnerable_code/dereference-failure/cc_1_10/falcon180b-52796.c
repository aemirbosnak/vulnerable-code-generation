//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000 // maximum length of a DNA sequence
#define NUM_BASES 4 // number of possible DNA bases (A, C, G, T)

// function to generate a random DNA sequence of length n
char* generateRandomSequence(int n) {
    char* sequence = (char*)malloc(n+1);
    for (int i = 0; i < n; i++) {
        int base = rand() % NUM_BASES;
        sequence[i] = "ACGT"[base];
    }
    sequence[n] = '\0';
    return sequence;
}

// function to reverse a DNA sequence
char* reverseSequence(char* sequence) {
    char* reversed = (char*)malloc(strlen(sequence)+1);
    for (int i = strlen(sequence)-1; i >= 0; i--) {
        reversed[i] = sequence[i];
    }
    reversed[strlen(sequence)] = '\0';
    return reversed;
}

// function to print a DNA sequence
void printSequence(char* sequence) {
    printf("%s\n", sequence);
}

// function to simulate a genome sequencing experiment
void simulateSequencing(char* sequence, int numReads, int readLength) {
    srand(time(NULL)); // seed the random number generator with the current time

    // generate random DNA reads
    char** reads = (char**)malloc(numReads * sizeof(char*));
    for (int i = 0; i < numReads; i++) {
        int start = rand() % (MAX_SEQUENCE_LENGTH - readLength);
        int end = start + readLength;
        char* read = (char*)malloc(readLength+1);
        for (int j = 0; j < readLength; j++) {
            int base = sequence[j+start] == 'A'? 0 : (sequence[j+start] == 'C'? 1 : (sequence[j+start] == 'G'? 2 : 3)); // convert DNA base to integer (0 for A, 1 for C, 2 for G, 3 for T)
            read[j] = "0123"[base]; // convert integer to DNA base (0 for A, 1 for C, 2 for G, 3 for T)
        }
        reads[i] = read;
    }

    // print the DNA reads
    for (int i = 0; i < numReads; i++) {
        printf("Read %d: %s\n", i+1, reads[i]);
    }

    // free memory
    for (int i = 0; i < numReads; i++) {
        free(reads[i]);
    }
    free(reads);
}

int main() {
    int numReads = 10;
    int readLength = 100;

    // generate a random DNA sequence
    char* sequence = generateRandomSequence(MAX_SEQUENCE_LENGTH);

    // simulate genome sequencing
    simulateSequencing(sequence, numReads, readLength);

    // reverse the DNA sequence
    char* reversedSequence = reverseSequence(sequence);

    // print the original and reversed DNA sequences
    printf("Original DNA sequence:\n");
    printSequence(sequence);
    printf("Reversed DNA sequence:\n");
    printSequence(reversedSequence);

    return 0;
}