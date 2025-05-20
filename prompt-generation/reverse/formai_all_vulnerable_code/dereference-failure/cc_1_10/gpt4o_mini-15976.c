//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random DNA sequence
void generateRandomDNA(char *sequence, int length) {
    const char nucleotides[] = "ACGT"; // The four bases of DNA
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % 4]; // Randomly select a nucleotide
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to calculate nucleotide frequencies
void calculateFrequencies(const char *sequence, int length, int *frequencies) {
    // Reset frequency array
    for (int i = 0; i < 4; i++) {
        frequencies[i] = 0;
    }
    // Count frequencies
    for (int i = 0; i < length; i++) {
        switch (sequence[i]) {
            case 'A': frequencies[0]++; break;
            case 'C': frequencies[1]++; break;
            case 'G': frequencies[2]++; break;
            case 'T': frequencies[3]++; break;
        }
    }
}

// Function to display the generated DNA sequence and its frequencies
void displayDNAInfo(const char *sequence, int *frequencies, int length) {
    printf("Generated DNA Sequence: %s\n", sequence);
    printf("Length of Sequence: %d\n", length);
    printf("Nucleotide Frequencies:\n");
    printf("A: %d\n", frequencies[0]);
    printf("C: %d\n", frequencies[1]);
    printf("G: %d\n", frequencies[2]);
    printf("T: %d\n", frequencies[3]);
}

int main() {
    srand(time(0)); // Seed the random number generator
    int sequenceCount, sequenceLength;

    // Ask user for number of sequences and their length
    printf("Welcome to the Genome Sequencing Simulator!\n");
    printf("How many random DNA sequences would you like to generate? ");
    scanf("%d", &sequenceCount);
    printf("What should be the length of each sequence? ");
    scanf("%d", &sequenceLength);

    // Allocate memory for the DNA sequences and frequency count
    char *sequence = (char *)malloc((sequenceLength + 1) * sizeof(char));
    if (sequence == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    int frequencies[4]; // Array to hold the frequency of A, C, G, T
    for (int i = 0; i < sequenceCount; i++) {
        generateRandomDNA(sequence, sequenceLength); // Generate a new sequence
        calculateFrequencies(sequence, sequenceLength, frequencies); // Calculate frequencies
        displayDNAInfo(sequence, frequencies, sequenceLength); // Display information
        printf("\n"); // Print a new line for better readability
    }

    free(sequence); // Free the allocated memory
    printf("Thank you for using the Genome Sequencing Simulator!\n");
    return 0;
}