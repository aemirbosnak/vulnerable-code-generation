//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000000

// Nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Function to generate a random nucleotide base
int get_random_base() {
  return rand() % 4;
}

// Function to generate a random DNA sequence of a given length
char *generate_random_dna(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = "ACGT"[get_random_base()];
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing process on a given DNA sequence
char *simulate_sequencing(char *sequence, int error_rate) {
  char *sequenced_sequence = malloc(strlen(sequence) + 1);
  for (int i = 0; i < strlen(sequence); i++) {
    if (rand() % 100 < error_rate) {
      // Introduce a sequencing error
      sequenced_sequence[i] = "ACGT"[get_random_base()];
    } else {
      // No sequencing error
      sequenced_sequence[i] = sequence[i];
    }
  }
  sequenced_sequence[strlen(sequence)] = '\0';
  return sequenced_sequence;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence of length 1000000
  char *original_sequence = generate_random_dna(MAX_SEQ_LENGTH);

  // Simulate the sequencing process with an error rate of 1%
  char *sequenced_sequence = simulate_sequencing(original_sequence, 1);

  // Print the original and sequenced sequences
  printf("Original sequence:\n%s\n", original_sequence);
  printf("Sequenced sequence:\n%s\n", sequenced_sequence);

  // Free the allocated memory
  free(original_sequence);
  free(sequenced_sequence);

  return 0;
}