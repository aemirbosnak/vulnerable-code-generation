//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA alphabet
char dna_alphabet[] = {'A', 'C', 'G', 'T'};

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 100

// Function to generate a random DNA sequence
char *generate_dna_sequence(int length) {
  // Allocate memory for the DNA sequence
  char *sequence = malloc(length + 1);

  // Initialize the DNA sequence to all As
  memset(sequence, 'A', length);

  // Generate a random number for each position in the DNA sequence
  for (int i = 0; i < length; i++) {
    int random_number = rand() % 4;
    sequence[i] = dna_alphabet[random_number];
  }

  // Terminate the DNA sequence with a null character
  sequence[length] = '\0';

  // Return the DNA sequence
  return sequence;
}

// Function to print a DNA sequence
void print_dna_sequence(char *sequence) {
  // Print the DNA sequence to the console
  printf("%s\n", sequence);
}

// Function to main
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_dna_sequence(MAX_SEQUENCE_LENGTH);

  // Print the DNA sequence
  print_dna_sequence(sequence);

  // Free the memory allocated for the DNA sequence
  free(sequence);

  return 0;
}