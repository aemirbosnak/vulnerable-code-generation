//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Create a DNA sequence of length n
char *generate_dna_sequence(int n) {
  // Initialize the DNA sequence
  char *dna = malloc(n + 1);
  dna[n] = '\0';

  // Generate a random DNA sequence
  for (int i = 0; i < n; i++) {
    int rand_num = rand() % 4;
    switch (rand_num) {
      case 0:
        dna[i] = 'A';
        break;
      case 1:
        dna[i] = 'C';
        break;
      case 2:
        dna[i] = 'G';
        break;
      case 3:
        dna[i] = 'T';
        break;
    }
  }

  // Return the DNA sequence
  return dna;
}

// Generate a sequencing error for a given base
char generate_sequencing_error(char base) {
  // Get a random number between 0 and 3
  int rand_num = rand() % 4;

  // Determine the type of sequencing error
  switch (rand_num) {
    case 0:
      // Base is correct
      return base;
    case 1:
      // Base is substituted with a different base
      switch (base) {
        case 'A':
          return 'C';
        case 'C':
          return 'G';
        case 'G':
          return 'T';
        case 'T':
          return 'A';
      }
    case 2:
      // Base is inserted after the correct base
      return base;
    case 3:
      // Base is deleted
      return '\0';
  }

  // Return the error base
  return '\0';
}

// Generate a sequenced DNA sequence of length n with an error rate of p
char *generate_sequenced_dna_sequence(char *dna, int n, float p) {
  // Initialize the sequenced DNA sequence
  char *sequenced_dna = malloc(n + 1);
  sequenced_dna[n] = '\0';

  // Generate a sequenced DNA sequence
  for (int i = 0; i < n; i++) {
    // Get a random number between 0 and 1
    float rand_num = (float)rand() / (float)RAND_MAX;

    // Determine if the base should be sequenced correctly or with an error
    if (rand_num < p) {
      // Generate a sequencing error
      sequenced_dna[i] = generate_sequencing_error(dna[i]);
    } else {
      // Base is sequenced correctly
      sequenced_dna[i] = dna[i];
    }
  }

  // Return the sequenced DNA sequence
  return sequenced_dna;
}

// Print the DNA sequence
void print_dna_sequence(char *dna) {
  // Print the DNA sequence
  printf("%s\n", dna);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a DNA sequence of length 1000
  char *dna = generate_dna_sequence(1000);

  // Generate a sequenced DNA sequence with an error rate of 0.01
  char *sequenced_dna = generate_sequenced_dna_sequence(dna, 1000, 0.01);

  // Print the DNA sequence
  print_dna_sequence(dna);

  // Print the sequenced DNA sequence
  print_dna_sequence(sequenced_dna);

  // Free the allocated memory
  free(dna);
  free(sequenced_dna);

  return 0;
}