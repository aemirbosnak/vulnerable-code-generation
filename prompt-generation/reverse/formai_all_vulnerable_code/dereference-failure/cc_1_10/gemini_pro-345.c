//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Generate a random nucleotide
char generate_nucleotide() {
  int r = rand() % 4;
  switch (r) {
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

// Generate a random DNA sequence of length n
char *generate_dna_sequence(int n) {
  char *sequence = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[n] = '\0';
  return sequence;
}

// Print a DNA sequence
void print_dna_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *sequence = generate_dna_sequence(100);

  // Print the DNA sequence
  print_dna_sequence(sequence);

  // Free the allocated memory
  free(sequence);

  return 0;
}