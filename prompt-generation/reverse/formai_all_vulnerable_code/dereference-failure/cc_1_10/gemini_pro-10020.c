//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_LENGTH 1000

// Define the number of DNA sequences to generate
#define NUM_SEQUENCES 10

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Define the seed for the random number generator
#define SEED 42

// Generate a random DNA sequence
char *generate_sequence() {
  // Allocate memory for the DNA sequence
  char *sequence = malloc(MAX_LENGTH);

  // Initialize the random number generator
  srand(SEED);

  // Generate the DNA sequence
  for (int i = 0; i < MAX_LENGTH; i++) {
    // Generate a random DNA base
    char base = rand() % 4;

    // Convert the random number to a DNA base
    switch (base) {
      case 0:
        sequence[i] = A;
        break;
      case 1:
        sequence[i] = C;
        break;
      case 2:
        sequence[i] = G;
        break;
      case 3:
        sequence[i] = T;
        break;
    }
  }

  // Return the DNA sequence
  return sequence;
}

// Mutate a DNA sequence
char *mutate_sequence(char *sequence) {
  // Allocate memory for the mutated DNA sequence
  char *mutated_sequence = malloc(MAX_LENGTH);

  // Copy the original DNA sequence to the mutated DNA sequence
  strcpy(mutated_sequence, sequence);

  // Mutate the DNA sequence
  for (int i = 0; i < MAX_LENGTH; i++) {
    // Generate a random number
    double r = rand() / (double)RAND_MAX;

    // Mutate the DNA base if the random number is less than the mutation probability
    if (r < MUTATION_PROBABILITY) {
      // Generate a random DNA base
      char base = rand() % 4;

      // Convert the random number to a DNA base
      switch (base) {
        case 0:
          mutated_sequence[i] = A;
          break;
        case 1:
          mutated_sequence[i] = C;
          break;
        case 2:
          mutated_sequence[i] = G;
          break;
        case 3:
          mutated_sequence[i] = T;
          break;
      }
    }
  }

  // Return the mutated DNA sequence
  return mutated_sequence;
}

// Print a DNA sequence
void print_sequence(char *sequence) {
  // Print the DNA sequence
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Generate DNA sequences
  char **sequences = malloc(sizeof(char *) * NUM_SEQUENCES);
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    sequences[i] = generate_sequence();
  }

  // Mutate DNA sequences
  char **mutated_sequences = malloc(sizeof(char *) * NUM_SEQUENCES);
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    mutated_sequences[i] = mutate_sequence(sequences[i]);
  }

  // Print DNA sequences
  printf("Original DNA sequences:\n");
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    print_sequence(sequences[i]);
  }

  // Print mutated DNA sequences
  printf("\nMutated DNA sequences:\n");
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    print_sequence(mutated_sequences[i]);
  }

  // Free memory
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    free(sequences[i]);
    free(mutated_sequences[i]);
  }
  free(sequences);
  free(mutated_sequences);

  return 0;
}