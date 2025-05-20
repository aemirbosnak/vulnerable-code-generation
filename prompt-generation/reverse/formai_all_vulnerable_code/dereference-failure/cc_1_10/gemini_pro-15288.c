//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide
char generate_nucleotide() {
  return nucleotides[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_dna_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing of a DNA sequence with a given error rate
char *simulate_sequencing(char *dna_sequence, double error_rate) {
  int length = strlen(dna_sequence);
  char *sequenced_sequence = malloc(length + 1);
  strcpy(sequenced_sequence, dna_sequence);
  for (int i = 0; i < length; i++) {
    if ((double)rand() / RAND_MAX < error_rate) {
      sequenced_sequence[i] = generate_nucleotide();
    }
  }
  return sequenced_sequence;
}

// Function to print a DNA sequence
void print_dna_sequence(char *dna_sequence) {
  printf("%s\n", dna_sequence);
}

// Function to test the DNA genome sequencing simulator
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Set the DNA sequence length and error rate
  int length = 1000;
  double error_rate = 0.01;

  // Generate the original DNA sequence
  char *dna_sequence = generate_dna_sequence(length);

  // Simulate the sequencing of the DNA sequence
  char *sequenced_sequence = simulate_sequencing(dna_sequence, error_rate);

  // Print the original and sequenced DNA sequences
  printf("Original DNA Sequence:\n");
  print_dna_sequence(dna_sequence);
  printf("\nSequenced DNA Sequence:\n");
  print_dna_sequence(sequenced_sequence);

  // Free the allocated memory
  free(dna_sequence);
  free(sequenced_sequence);

  return 0;
}