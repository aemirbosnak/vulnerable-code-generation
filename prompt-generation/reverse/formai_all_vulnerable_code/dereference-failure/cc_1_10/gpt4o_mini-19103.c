//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants defining the genome properties
#define SEQUENCE_LENGTH 1000
#define MAX_MUTATIONS 10
#define NUM_BASES 4

// Function to generate a random base (A, T, C, G)
char generate_random_base() {
    int rand_val = rand() % NUM_BASES;
    switch (rand_val) {
        case 0: return 'A';
        case 1: return 'T';
        case 2: return 'C';
        case 3: return 'G';
        default: return 'A'; // Fallback, should never happen
    }
}

// Function to create a random genome sequence
void generate_genome_sequence(char *sequence) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = generate_random_base();
    }
    sequence[SEQUENCE_LENGTH] = '\0'; // Null terminate the string
}

// Function to mutate the genome sequence by introducing random changes
void mutate_genome_sequence(char *sequence) {
    int num_mutations = rand() % (MAX_MUTATIONS + 1); // Random mutations count

    for (int i = 0; i < num_mutations; i++) {
        int position = rand() % SEQUENCE_LENGTH; // Random position for mutation
        sequence[position] = generate_random_base(); // Change the base to a new random base
    }
}

// Function to print the genome sequence
void print_genome_sequence(const char *sequence) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        putchar(sequence[i]);
        // Add space for better readability every 50 bases
        if ((i + 1) % 50 == 0) {
            putchar(' ');
        }
    }
    putchar('\n'); // New line at the end of the sequence
}

// Function to simulate genome sequencing with error rates
void simulate_genome_sequencing(const char *sequence, char *sequence_with_errors, float error_rate) {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        // Introduce an error based on the error rate
        if (((float)rand() / RAND_MAX) < error_rate) {
            sequence_with_errors[i] = generate_random_base(); // Change to a random base
        } else {
            sequence_with_errors[i] = sequence[i]; // Keep original base
        }
    }
    sequence_with_errors[SEQUENCE_LENGTH] = '\0'; // Null terminate
}

// Main function to demonstrate the genome sequencing simulator
int main() {
    // Seed the random number generator for reproducibility
    srand(time(NULL));

    // Allocate memory for the original and mutated genome sequences
    char *original_genome = (char *)malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
    char *mutated_genome = (char *)malloc((SEQUENCE_LENGTH + 1) * sizeof(char));
    char *sequenced_genome = (char *)malloc((SEQUENCE_LENGTH + 1) * sizeof(char));

    // Generate the original genome sequence
    generate_genome_sequence(original_genome);
    printf("Original Genome Sequence:\n");
    print_genome_sequence(original_genome);

    // Mutate the original genome sequence
    strcpy(mutated_genome, original_genome);
    mutate_genome_sequence(mutated_genome);
    printf("\nMutated Genome Sequence:\n");
    print_genome_sequence(mutated_genome);

    // Simulate genome sequencing with a certain error rate
    float error_rate = 0.05; // Define error rate (5% errors)
    simulate_genome_sequencing(mutated_genome, sequenced_genome, error_rate);
    printf("\nSequenced Genome with Errors (5%% Error Rate):\n");
    print_genome_sequence(sequenced_genome);

    // Free the allocated memory
    free(original_genome);
    free(mutated_genome);
    free(sequenced_genome);

    return 0;
}