//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide
char generate_nucleotide() {
    return nucleotides[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = generate_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Function to simulate a sequencing error
char *simulate_error(char *sequence) {
    int error_rate = 1;  // Error rate of 1%
    int sequence_length = strlen(sequence);
    for (int i = 0; i < sequence_length; i++) {
        if (rand() % 100 < error_rate) {
            sequence[i] = generate_nucleotide();
        }
    }
    return sequence;
}

// Function to print the sequence
void print_sequence(char *sequence) {
    printf("%s\n", sequence);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence of length 100
    char *sequence = generate_sequence(100);

    // Simulate a sequencing error
    char *error_sequence = simulate_error(sequence);

    // Print the original sequence
    printf("Original sequence:\n");
    print_sequence(sequence);

    // Print the error-induced sequence
    printf("Error-induced sequence:\n");
    print_sequence(error_sequence);

    // Free the allocated memory
    free(sequence);
    free(error_sequence);

    return 0;
}