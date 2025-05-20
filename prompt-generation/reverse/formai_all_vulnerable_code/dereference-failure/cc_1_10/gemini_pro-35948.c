//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the maximum length of the genome
#define MAX_LENGTH 10000

// Define the probability of each nucleotide base
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide base
int generate_nucleotide() {
  // Get a random number between 0 and 3
  int random = rand() % 4;

  // Return the corresponding nucleotide base
  switch (random) {
    case A:
      return A;
    case C:
      return C;
    case G:
      return G;
    case T:
      return T;
  }

  // This should never happen
  return -1;
}

// Generate a random genome sequence
char *generate_genome(int length) {
  // Allocate memory for the genome sequence
  char *genome = malloc(length + 1);

  // Generate the genome sequence
  for (int i = 0; i < length; i++) {
    // Get a random nucleotide base
    int nucleotide = generate_nucleotide();

    // Convert the nucleotide base to a character
    char base;
    switch (nucleotide) {
      case A:
        base = 'A';
        break;
      case C:
        base = 'C';
        break;
      case G:
        base = 'G';
        break;
      case T:
        base = 'T';
        break;
    }

    // Add the character to the genome sequence
    genome[i] = base;
  }

  // Add the null terminator to the end of the genome sequence
  genome[length] = '\0';

  // Return the genome sequence
  return genome;
}

// Print the genome sequence
void print_genome(char *genome) {
  // Print the genome sequence
  printf("%s\n", genome);
}

// Free the memory allocated for the genome sequence
void free_genome(char *genome) {
  // Free the memory
  free(genome);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random genome sequence
  int length = 1000;
  char *genome = generate_genome(length);

  // Print the genome sequence
  print_genome(genome);

  // Free the memory allocated for the genome sequence
  free_genome(genome);

  return 0;
}