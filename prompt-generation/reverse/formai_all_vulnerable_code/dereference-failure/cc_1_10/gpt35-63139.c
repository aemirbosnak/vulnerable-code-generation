//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define READ_LENGTH 100
#define REFERENCE_LENGTH 1000
#define MUTATION_RATE 0.01

// Generate a random base
char generateBase() {
    int value = rand() % 4;
    switch (value) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
}

// Generate a random DNA string
char* generateDNA(int length) {
    char* dna = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        dna[i] = generateBase();
    }
    return dna;
}

// Mutate a single base
char mutate(char base) {
    double mutationProbability = (double)rand() / RAND_MAX;
    if (mutationProbability <= MUTATION_RATE) {
        // Generate a random base other than the current one
        char newBase;
        do {
            newBase = generateBase();
        } while (newBase == base);
        return newBase;
    } else {
        return base;
    }
}

// Mutate a DNA string
char* mutateDNA(char* dna, int length) {
    char* mutated = malloc(sizeof(char) * length);
    for (int i = 0; i < length; i++) {
        mutated[i] = mutate(dna[i]);
    }
    free(dna);
    return mutated;
}

// Compare two DNA strings and return the number of differences
int compareDNA(char* dna1, char* dna2, int length) {
    int differences = 0;
    for (int i = 0; i < length; i++) {
        if (dna1[i] != dna2[i]) {
            differences++;
        }
    }
    return differences;
}

int main() {
    srand(time(NULL));

    // Generate reference DNA and read
    char* referenceDNA = generateDNA(REFERENCE_LENGTH);
    char* read = malloc(sizeof(char) * READ_LENGTH);
    int start = rand() % (REFERENCE_LENGTH - READ_LENGTH);
    for (int i = 0; i < READ_LENGTH; i++) {
        read[i] = referenceDNA[start + i];
    }

    // Mutate reference DNA and read
    char* mutatedDNA = mutateDNA(referenceDNA, REFERENCE_LENGTH);
    char* mutatedRead = mutateDNA(read, READ_LENGTH);

    // Compare the resulting DNA strings
    int referenceToMutated = compareDNA(referenceDNA, mutatedDNA, REFERENCE_LENGTH);
    int readToMutated = compareDNA(read, mutatedRead, READ_LENGTH);

    // Print the results
    printf("Reference DNA: %s\n", referenceDNA);
    printf("Mutated DNA: %s\n", mutatedDNA);
    printf("Differences in reference DNA: %d\n", referenceToMutated);
    printf("Original read: %s\n", read);
    printf("Mutated read: %s\n", mutatedRead);
    printf("Differences in read: %d\n", readToMutated);

    // Free memory
    free(referenceDNA);
    free(mutatedDNA);
    free(read);
    free(mutatedRead);

    return 0;
}