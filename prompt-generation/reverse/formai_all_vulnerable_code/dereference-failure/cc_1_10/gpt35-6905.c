//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LEN 1000

// Function to generate a random base
char genBase() {
    int num = rand() % 4;
    switch(num) {
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
char* genSeq() {
    char* sequence = malloc(sizeof(char) * SEQUENCE_LEN);
    int i;
    for(i = 0; i < SEQUENCE_LEN; i++) {
        sequence[i] = genBase();
    }
    return sequence;
}

// Function to simulate errors in a DNA sequence
char* simulateErrors(char* sequence, float errorRate) {
    char* seqWithError = malloc(sizeof(char) * SEQUENCE_LEN);
    int i;
    for(i = 0; i < SEQUENCE_LEN; i++) {
        if((float)rand() / (float)RAND_MAX < errorRate) {
            seqWithError[i] = genBase();
        } else {
            seqWithError[i] = sequence[i];
        }
    }
    return seqWithError;
}

// Function to display a DNA sequence
void displaySeq(char* sequence) {
    int i;
    for(i = 0; i < SEQUENCE_LEN; i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Main function
int main() {
    srand(time(NULL));

    // Generate a DNA sequence with no errors
    char* sequence = genSeq();
    printf("Generated DNA sequence:\n");
    displaySeq(sequence);

    // Simulate errors in the DNA sequence
    float errorRate = 0.1;
    char* seqWithError = simulateErrors(sequence, errorRate);
    printf("Simulated DNA sequence with %.2f error rate:\n", errorRate);
    displaySeq(seqWithError);

    // Clean up memory
    free(sequence);
    free(seqWithError);

    return 0;
}