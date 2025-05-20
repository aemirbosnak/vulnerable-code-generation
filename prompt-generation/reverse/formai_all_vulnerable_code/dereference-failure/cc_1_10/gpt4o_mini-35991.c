//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCES 100
#define MAX_LENGTH 1000
#define BASES "ACGT"

// Function to generate a random base
char random_base() {
    return BASES[rand() % 4];
}

// Function to create a random DNA sequence
char* generate_sequence(int length) {
    char* sequence = (char*)malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = random_base();
    }
    sequence[length] = '\0'; // Null-terminate the string
    return sequence;
}

// Function to generate multiple random DNA sequences
void generate_sequences(char** sequences, int num_sequences, int max_length) {
    for (int i = 0; i < num_sequences; i++) {
        int length = rand() % max_length + 1; // Ensure at least 1 base
        sequences[i] = generate_sequence(length);
    }
}

// Function to print the sequences
void print_sequences(char** sequences, int num_sequences) {
    printf("\nGenerated DNA Sequences:\n");
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
}

// Function to free allocated sequences
void free_sequences(char** sequences, int num_sequences) {
    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]);
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int num_sequences;
    int max_length;

    printf("Surprise! Welcome to the DNA Genome Sequencing Simulator!\n");

    // User input for number of sequences
    printf("How many sequences do you want to generate (max %d)? ", MAX_SEQUENCES);
    scanf("%d", &num_sequences);
    if (num_sequences < 1 || num_sequences > MAX_SEQUENCES) {
        printf("Invalid number of sequences. Please enter a number between 1 and %d.\n", MAX_SEQUENCES);
        return 1; 
    }

    // User input for maximum length of sequences
    printf("What is the maximum length of each sequence (max %d)? ", MAX_LENGTH);
    scanf("%d", &max_length);
    if (max_length < 1 || max_length > MAX_LENGTH) {
        printf("Invalid maximum length. Please select a number between 1 and %d.\n", MAX_LENGTH);
        return 1; 
    }

    char* sequences[MAX_SEQUENCES]; // Array to hold the sequences

    // Generate the sequences
    printf("Generating your sequences...\n");
    generate_sequences(sequences, num_sequences, max_length);

    // Print the sequences
    print_sequences(sequences, num_sequences);

    // Free allocated memory
    free_sequences(sequences, num_sequences);
    printf("\nAll sequences have been generated and memory cleaned up. What a surprise!\n");

    return 0;
}