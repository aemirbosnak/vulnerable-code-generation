//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Function to generate a random nucleotide character
char generate_nucleotide() {
  // Generate a random number between 0 and 3
  int random_number = rand() % 4;

  // Return the corresponding nucleotide character
  switch (random_number) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
  }
}

// Function to generate a random DNA sequence of a given length
char *generate_dna_sequence(int length) {
  // Allocate memory for the DNA sequence
  char *dna_sequence = malloc(sizeof(char) * (length + 1));

  // Generate a random nucleotide character for each position in the sequence
  for (int i = 0; i < length; i++) {
    dna_sequence[i] = generate_nucleotide();
  }

  // Add the null-terminator to the end of the sequence
  dna_sequence[length] = '\0';

  // Return the DNA sequence
  return dna_sequence;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *dna_sequence = generate_dna_sequence(100);

  // Print the DNA sequence to the console
  printf("Generated DNA sequence: %s\n", dna_sequence);

  // Free the memory allocated for the DNA sequence
  free(dna_sequence);

  return 0;
}