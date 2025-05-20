//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000

// Function to generate a random DNA sequence
char* generate_dna_sequence(int length) {
  char* sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int random_number = rand() % 4;
    switch (random_number) {
      case 0:
        sequence[i] = 'A';
        break;
      case 1:
        sequence[i] = 'C';
        break;
      case 2:
        sequence[i] = 'G';
        break;
      case 3:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing process
char* sequence_sequencer(char* sequence, int noise_level) {
  char* sequenced_sequence = malloc(strlen(sequence) + 1);
  for (int i = 0; i < strlen(sequence); i++) {
    int random_number = rand() % 100;
    if (random_number < noise_level) {
      int random_error = rand() % 4;
      switch (random_error) {
        case 0:
          sequenced_sequence[i] = 'A';
          break;
        case 1:
          sequenced_sequence[i] = 'C';
          break;
        case 2:
          sequenced_sequence[i] = 'G';
          break;
        case 3:
          sequenced_sequence[i] = 'T';
          break;
      }
    } else {
      sequenced_sequence[i] = sequence[i];
    }
  }
  sequenced_sequence[strlen(sequence)] = '\0';
  return sequenced_sequence;
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence of length 1000
  char* sequence = generate_dna_sequence(MAX_LENGTH);

  // Simulate the sequencing process with a noise level of 10%
  char* sequenced_sequence = sequence_sequencer(sequence, 10);

  // Print the original sequence
  printf("Original sequence:\n%s\n", sequence);

  // Print the sequenced sequence
  printf("Sequenced sequence:\n%s\n", sequenced_sequence);

  return 0;
}