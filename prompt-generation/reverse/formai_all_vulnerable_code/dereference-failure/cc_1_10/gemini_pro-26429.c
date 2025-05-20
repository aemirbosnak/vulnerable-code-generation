//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Simulate the sequencing of a DNA fragment
char *sequence_dna(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    // Get a random nucleotide
    int nucleotide_index = rand() % 4;
    char nucleotide = nucleotides[nucleotide_index];

    // Add the nucleotide to the sequence
    sequence[i] = nucleotide;
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Print the DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Free the memory allocated for the DNA sequence
void free_sequence(char *sequence) {
  free(sequence);
}

// Main function
int main() {
  // Get the length of the DNA fragment from the user
  int length;
  printf("Enter the length of the DNA fragment: ");
  scanf("%d", &length);

  // Simulate the sequencing of the DNA fragment
  char *sequence = sequence_dna(length);

  // Print the DNA sequence
  printf("DNA sequence: ");
  print_sequence(sequence);

  // Free the memory allocated for the DNA sequence
  free_sequence(sequence);

  return 0;
}