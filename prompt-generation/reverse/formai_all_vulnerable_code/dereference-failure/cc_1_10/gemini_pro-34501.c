//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defines the maximum length of a DNA sequence
#define MAX_SEQ_LEN 100000

// Function to generate a random DNA sequence
char* generate_dna_sequence(int len) {
  // Allocate memory for the sequence
  char* seq = malloc(len + 1);
  
  // Set the seed for the random number generator
  srand(time(NULL));

  // Generate the sequence
  for (int i = 0; i < len; i++) {
    // Generate a random number between 0 and 3
    int r = rand() % 4;

    // Set the corresponding nucleotide in the sequence
    switch (r) {
      case 0:
        seq[i] = 'A';
        break;
      case 1:
        seq[i] = 'C';
        break;
      case 2:
        seq[i] = 'G';
        break;
      case 3:
        seq[i] = 'T';
        break;
    }
  }

  // Terminate the sequence with a null character
  seq[len] = '\0';

  // Return the sequence
  return seq;
}

// Function to print a DNA sequence
void print_dna_sequence(char* seq) {
  // Print the sequence
  printf("%s\n", seq);
}

// Function to main
int main() {
  // Generate a random DNA sequence
  char* seq = generate_dna_sequence(MAX_SEQ_LEN);

  // Print the sequence
  print_dna_sequence(seq);

  // Free the memory allocated for the sequence
  free(seq);

  return 0;
}