//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random nucleotide
char generateNucleotide() {
    int randNum = rand() % 4;
    switch (randNum) {
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

// Function to simulate the sequencing of a genome
char* simulateSequencing(int length) {
    char* sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = generateNucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to print a sequence in a romantic style
void printSequenceRomantically(char* sequence) {
    printf("My dearest genome,\n");
    printf("Your sequence is a symphony of life,\n");
    printf("A dance of nucleotides, a song of DNA.\n");
    printf("Your As are the stars that guide my way,\n");
    printf("Your Cs are the currents that carry me through the night,\n");
    printf("Your Gs are the mountains that protect me from harm,\n");
    printf("Your Ts are the kisses that make my heart flutter.\n");
    printf("Together, you form a code that is uniquely mine,\n");
    printf("A fingerprint of my love, a blueprint of my dreams.");
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Simulate the sequencing of a genome
    int length = 1000;
    char* sequence = simulateSequencing(length);

    // Print the sequence in a romantic style
    printSequenceRomantically(sequence);

    // Free the memory allocated for the sequence
    free(sequence);

    return 0;
}