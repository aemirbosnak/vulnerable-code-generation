//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the possible nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide
char generate_nucleotide() {
  return nucleotides[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing of a DNA sequence
char *simulate_sequencing(char *sequence) {
  int length = strlen(sequence);
  char *sequenced_sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    if (rand() % 100 < 95) {
      sequenced_sequence[i] = sequence[i];
    } else {
      sequenced_sequence[i] = generate_nucleotide();
    }
  }
  sequenced_sequence[length] = '\0';
  return sequenced_sequence;
}

// Function to print a DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence of length 1000
  char *sequence = generate_sequence(1000);

  // Simulate the sequencing of the DNA sequence
  char *sequenced_sequence = simulate_sequencing(sequence);

  // Print the original DNA sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Print the sequenced DNA sequence
  printf("Sequenced sequence:\n");
  print_sequence(sequenced_sequence);

  // Free the allocated memory
  free(sequence);
  free(sequenced_sequence);

  return 0;
}