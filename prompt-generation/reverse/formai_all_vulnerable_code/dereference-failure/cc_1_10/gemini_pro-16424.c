//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the sequencing error probabilities
#define ERROR_PROB_SUBSTITUTION 0.01
#define ERROR_PROB_INSERTION 0.001
#define ERROR_PROB_DELETION 0.001

// Function to generate a random number between 0 and 1
double rand01() {
  return (double)rand() / (double)RAND_MAX;
}

// Function to generate a random nucleotide base
int rand_base() {
  double r = rand01();
  if (r < 0.25) {
    return A;
  } else if (r < 0.5) {
    return C;
  } else if (r < 0.75) {
    return G;
  } else {
    return T;
  }
}

// Function to simulate a sequencing error
int simulate_error(int base) {
  double r = rand01();
  if (r < ERROR_PROB_SUBSTITUTION) {
    // Substitution error
    return rand_base();
  } else if (r < ERROR_PROB_SUBSTITUTION + ERROR_PROB_INSERTION) {
    // Insertion error
    return base;
  } else if (r < ERROR_PROB_SUBSTITUTION + ERROR_PROB_INSERTION + ERROR_PROB_DELETION) {
    // Deletion error
    return -1;
  } else {
    // No error
    return base;
  }
}

// Function to simulate a DNA sequencing experiment
char *simulate_sequencing(char *sequence) {
  // Allocate memory for the simulated sequence
  char *simulated_sequence = malloc(strlen(sequence) + 1);

  // Simulate sequencing errors
  for (int i = 0; i < strlen(sequence); i++) {
    int base = sequence[i];
    int simulated_base = simulate_error(base);
    if (simulated_base == -1) {
      // Deletion error
      continue;
    }
    simulated_sequence[i] = simulated_base;
  }

  // Add a null terminator to the end of the simulated sequence
  simulated_sequence[strlen(sequence)] = '\0';

  // Return the simulated sequence
  return simulated_sequence;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Define the DNA sequence to be sequenced
  char *sequence = "ACGTACGTACGT";

  // Simulate sequencing errors
  char *simulated_sequence = simulate_sequencing(sequence);

  // Print the original sequence and the simulated sequence
  printf("Original sequence: %s\n", sequence);
  printf("Simulated sequence: %s\n", simulated_sequence);

  // Free the memory allocated for the simulated sequence
  free(simulated_sequence);

  return 0;
}