//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the sequencing error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide base
char generate_base() {
  // Get a random number between 0 and 3
  int r = rand() % 4;

  // Return the corresponding nucleotide base
  switch (r) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
    default:
      return 'N';  // Invalid nucleotide base
  }
}

// Simulate the sequencing of a DNA fragment
char *simulate_sequencing(char *dna, int length) {
  // Allocate memory for the sequenced DNA fragment
  char *sequenced_dna = malloc(length + 1);

  // Simulate the sequencing process
  for (int i = 0; i < length; i++) {
    // Get the original nucleotide base
    char base = dna[i];

    // Introduce a sequencing error with a probability of ERROR_RATE
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
      // Generate a random nucleotide base
      base = generate_base();
    }

    // Store the sequenced nucleotide base
    sequenced_dna[i] = base;
  }

  // Null-terminate the sequenced DNA fragment
  sequenced_dna[length] = '\0';

  // Return the sequenced DNA fragment
  return sequenced_dna;
}

// Print the DNA fragment and its sequenced version
void print_dna(char *dna, char *sequenced_dna, int length) {
  // Print the original DNA fragment
  printf("Original DNA fragment: %s\n", dna);

  // Print the sequenced DNA fragment
  printf("Sequenced DNA fragment: %s\n", sequenced_dna);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Define the DNA fragment to be sequenced
  char dna[] = "ACGTACGTACGT";
  int length = strlen(dna);

  // Simulate the sequencing of the DNA fragment
  char *sequenced_dna = simulate_sequencing(dna, length);

  // Print the DNA fragment and its sequenced version
  print_dna(dna, sequenced_dna, length);

  // Free the allocated memory
  free(sequenced_dna);

  return 0;
}