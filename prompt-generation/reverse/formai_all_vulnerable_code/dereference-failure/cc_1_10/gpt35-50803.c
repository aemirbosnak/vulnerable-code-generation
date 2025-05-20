//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to randomize the nucleotides: A, C, G, T
char randomNucleotide() {
    char nucleotide[4] = {'A', 'C', 'G', 'T'};
    return nucleotide[rand() % 4];
}

// Function to generate the DNA sequence
char* generateDNASequence(int length) {
    char* sequence = (char*)malloc(length + 1);
    for(int i = 0; i < length; i++) {
        sequence[i] = randomNucleotide();
    }
    sequence[length] = '\0'; // Null terminator
    return sequence;
}

int main() {

    srand(time(NULL)); // Seed the random number generator

    char* dnaSeq1 = generateDNASequence(100);
    char* dnaSeq2 = generateDNASequence(100);

    int numMutations = rand() % 20;

    printf("------------------------------\n");
    printf("Starting Genome Sequencing...\n");
    printf("------------------------------\n");
    printf("First DNA Sequence: %s\n", dnaSeq1);
    printf("Second DNA Sequence: %s\n", dnaSeq2);
    printf("Number of Mutations: %d\n", numMutations);
    printf("------------------------------\n");
    printf("Simulating Mutations...\n");
    printf("------------------------------\n");

    // Simulate mutations
    for(int i = 0; i < numMutations; i++) {
        int index = rand() % 100; // Choose random index to mutate
        char newNucleotide = randomNucleotide(); // Generate new nucleotide
        dnaSeq1[index] = newNucleotide;
        printf("Mutation at position %d: %c -> %c\n", index, dnaSeq1[index], newNucleotide);
    }

    // Print mutated DNA sequence
    printf("------------------------------\n");
    printf("Mutated DNA Sequence: %s\n", dnaSeq1);
    printf("------------------------------\n");

    // Cleaning up memory
    free(dnaSeq1);
    free(dnaSeq2);
    
    return 0;
}