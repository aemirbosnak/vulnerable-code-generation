//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA alphabet
char *dna_alphabet = "ACGT";

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 1000

// Define the number of DNA sequences to generate
#define NUM_SEQUENCES 10

// Generate a random DNA sequence
char *generate_dna_sequence(int length) {
  // Allocate memory for the DNA sequence
  char *sequence = malloc(length + 1);

  // Generate a random DNA sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = dna_alphabet[rand() % 4];
  }

  // Terminate the DNA sequence with a null character
  sequence[length] = '\0';

  // Return the DNA sequence
  return sequence;
}

// Print a DNA sequence
void print_dna_sequence(char *sequence) {
  // Print the DNA sequence
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate DNA sequences
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    // Generate a random DNA sequence length
    int length = rand() % MAX_SEQUENCE_LENGTH + 1;

    // Generate a random DNA sequence
    char *sequence = generate_dna_sequence(length);

    // Print the DNA sequence
    print_dna_sequence(sequence);

    // Free the memory allocated for the DNA sequence
    free(sequence);
  }

  return 0;
}