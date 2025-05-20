//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
char bases[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide base
char generate_base() {
  return bases[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_base();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to print a DNA sequence
void print_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Function to simulate the sequencing of a DNA sequence
char *simulate_sequencing(char *sequence) {
  int length = strlen(sequence);
  char *sequenced_sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    // Simulate the sequencing error with a 1% probability
    if (rand() % 100 < 1) {
      sequenced_sequence[i] = generate_base();
    } else {
      sequenced_sequence[i] = sequence[i];
    }
  }
  sequenced_sequence[length] = '\0';
  return sequenced_sequence;
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 100
  char *sequence = generate_sequence(100);

  // Print the original DNA sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Simulate the sequencing of the DNA sequence
  char *sequenced_sequence = simulate_sequencing(sequence);

  // Print the sequenced DNA sequence
  printf("Sequenced sequence:\n");
  print_sequence(sequenced_sequence);

  // Free the allocated memory
  free(sequence);
  free(sequenced_sequence);

  return 0;
}