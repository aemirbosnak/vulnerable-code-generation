//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// DNA base pairs
#define A 0
#define C 1
#define G 2
#define T 3

// Error rates
#define SUBSTITUTION_ERROR_RATE 0.01
#define INDEL_ERROR_RATE 0.001

// Length of the genome to be sequenced
#define GENOME_LENGTH 100000

// Function to generate a random DNA sequence
char *generate_random_dna_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    int base = rand() % 4;
    switch (base) {
      case A:
        sequence[i] = 'A';
        break;
      case C:
        sequence[i] = 'C';
        break;
      case G:
        sequence[i] = 'G';
        break;
      case T:
        sequence[i] = 'T';
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate sequencing errors
char *simulate_sequencing_errors(char *sequence, double substitution_error_rate, double indel_error_rate) {
  int length = strlen(sequence);
  char *sequenced_sequence = malloc(length + 1);
  strcpy(sequenced_sequence, sequence);

  // Simulate substitution errors
  for (int i = 0; i < length; i++) {
    double r = (double)rand() / (double)RAND_MAX;
    if (r < substitution_error_rate) {
      int base = rand() % 4;
      while (base == sequence[i]) {
        base = rand() % 4;
      }
      sequenced_sequence[i] = base;
    }
  }

  // Simulate indel errors
  for (int i = 0; i < length; i++) {
    double r = (double)rand() / (double)RAND_MAX;
    if (r < indel_error_rate) {
      int type = rand() % 2;
      if (type == 0) {
        // Insertion
        int base = rand() % 4;
        char *new_sequence = malloc(length + 2);
        memcpy(new_sequence, sequenced_sequence, i + 1);
        new_sequence[i + 1] = base;
        memcpy(new_sequence + i + 2, sequenced_sequence + i, length - i);
        new_sequence[length + 1] = '\0';
        free(sequenced_sequence);
        sequenced_sequence = new_sequence;
        length++;
      } else {
        // Deletion
        char *new_sequence = malloc(length - 1);
        memcpy(new_sequence, sequenced_sequence, i);
        memcpy(new_sequence + i, sequenced_sequence + i + 1, length - i - 1);
        new_sequence[length - 1] = '\0';
        free(sequenced_sequence);
        sequenced_sequence = new_sequence;
        length--;
      }
    }
  }

  return sequenced_sequence;
}

// Function to calculate the Hamming distance between two sequences
int hamming_distance(char *sequence1, char *sequence2) {
  int length = strlen(sequence1);
  int distance = 0;
  for (int i = 0; i < length; i++) {
    if (sequence1[i] != sequence2[i]) {
      distance++;
    }
  }
  return distance;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_random_dna_sequence(GENOME_LENGTH);

  // Simulate sequencing errors
  char *sequenced_sequence = simulate_sequencing_errors(sequence, SUBSTITUTION_ERROR_RATE, INDEL_ERROR_RATE);

  // Calculate the Hamming distance between the original and sequenced sequences
  int distance = hamming_distance(sequence, sequenced_sequence);

  // Print the results
  printf("Original sequence: %s\n", sequence);
  printf("Sequenced sequence: %s\n", sequenced_sequence);
  printf("Hamming distance: %d\n", distance);

  // Free the allocated memory
  free(sequence);
  free(sequenced_sequence);

  return 0;
}