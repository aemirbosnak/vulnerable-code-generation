//FormAI DATASET v1.0 Category: Computer Biology ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Hamming distance between two DNA sequences
int hamming_distance(char* dna1, char* dna2, int length) {
    int distance = 0;
    for (int i = 0; i < length; i++) {
        if (dna1[i] != dna2[i]) {
            distance++;
        }
    }
    return distance;
}

// Function to generate a random DNA sequence
char* generate_sequence(int length) {
    static const char alphabet[] = "ACGT";
    char* sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = alphabet[rand() % 4];
    }
    sequence[length] = '\0';
    return sequence;
}

int main() {
    // Program to demonstrate the calculation of Hamming distances between random DNA sequences

    // Seed the random number generator
    srand(time(NULL));

    // Generate two random DNA sequences
    int length = 100;
    char* dna1 = generate_sequence(length);
    char* dna2 = generate_sequence(length);

    // Print the DNA sequences
    printf("DNA Sequence 1: %s\n", dna1);
    printf("DNA Sequence 2: %s\n", dna2);

    // Calculate the Hamming distance between the sequences
    int distance = hamming_distance(dna1, dna2, length);

    // Print the Hamming distance
    printf("Hamming Distance: %d\n", distance);

    // Free the dynamically allocated memory for the DNA sequences
    free(dna1);
    free(dna2);
    
    return 0;
}