//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nucleotide codes
#define A 0
#define C 1
#define G 2
#define T 3

// Generate a random sequence of DNA (A, C, G, T)
char* generate_dna(int length) {
  // Allocate memory for the DNA sequence
  char *dna = malloc(length + 1);

  // Set the random seed
  srand(time(NULL));

  // Generate the DNA sequence
  for (int i = 0; i < length; i++) {
    int nucleotide = rand() % 4;
    switch (nucleotide) {
      case A:
        dna[i] = 'A';
        break;
      case C:
        dna[i] = 'C';
        break;
      case G:
        dna[i] = 'G';
        break;
      default:
        dna[i] = 'T';
        break;
    }
  }

  // Terminate the string with a null character
  dna[length] = '\0';

  // Return the DNA sequence
  return dna;
}

// Print a DNA sequence in a cheerful style
void print_dna(char *dna) {
  // Print the DNA sequence
  printf("Here's your DNA sequence, all sparkly and new:\n");
  for (int i = 0; i < strlen(dna); i++) {
    switch (dna[i]) {
      case A:
        printf("\x1B[31m%c\x1B[0m", dna[i]);
        break;
      case C:
        printf("\x1B[32m%c\x1B[0m", dna[i]);
        break;
      case G:
        printf("\x1B[33m%c\x1B[0m", dna[i]);
        break;
      default:
        printf("\x1B[34m%c\x1B[0m", dna[i]);
        break;
    }
  }

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Generate a DNA sequence of length 100
  char *dna = generate_dna(100);

  // Print the DNA sequence
  print_dna(dna);

  // Free the memory allocated for the DNA sequence
  free(dna);

  return 0;
}