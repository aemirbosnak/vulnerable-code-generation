//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Sherlock Holmes Genome Sequencing Simulator
// "Elementary, my dear Watson!"

// Constants
#define DNA_SIZE 1000000

// Generate random DNA sequence
char *generateDNA() {
    char *dna = malloc(DNA_SIZE);
    for (int i = 0; i < DNA_SIZE; i++) {
        int randNum = rand() % 4;
        switch (randNum) {
            case 0:
                dna[i] = 'A';
                break;
            case 1:
                dna[i] = 'C';
                break;
            case 2:
                dna[i] = 'G';
                break;
            case 3:
                dna[i] = 'T';
                break;
        }
    }
    return dna;
}

// Print DNA sequence
void printDNA(char *dna) {
    for (int i = 0; i < DNA_SIZE; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");
}

// Find Watson's favorite pattern in DNA
int findWatsonPattern(char *dna) {
    char *pattern = "CGTACGT";
    int patternLength = strlen(pattern);
    int found = 0;
    for (int i = 0; i < DNA_SIZE - patternLength + 1; i++) {
        if (strncmp(&dna[i], pattern, patternLength) == 0) {
            found = 1;
            break;
        }
    }
    return found;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate DNA sequence
    char *dna = generateDNA();

    // Print DNA sequence
    printf("Watson's DNA sequence:\n");
    printDNA(dna);

    // Find Watson's favorite pattern in DNA
    int found = findWatsonPattern(dna);

    // Print result
    if (found) {
        printf("Elementary, my dear Watson! I have found your favorite pattern in your DNA sequence.\n");
    } else {
        printf("My apologies, Watson, but I cannot find your favorite pattern in your DNA sequence.\n");
    }

    // Free memory
    free(dna);

    return 0;
}