//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a sequence
#define MAX_SEQUENCE_LENGTH 10000

// Define the number of sequences to generate
#define NUM_SEQUENCES 100

// Define the probability of each nucleotide
#define P_A 0.25
#define P_C 0.25
#define P_G 0.25
#define P_T 0.25

// Generate a random nucleotide
char generate_nucleotide() {
  double r = (double)rand() / RAND_MAX;
  if (r < P_A) {
    return A;
  } else if (r < P_A + P_C) {
    return C;
  } else if (r < P_A + P_C + P_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random sequence of nucleotides
char *generate_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[length] = '\0';
  return sequence;
}

// Write a sequence to a file
void write_sequence(char *sequence, FILE *file) {
  fprintf(file, "%s\n", sequence);
}

// Generate and write sequences to a file
void generate_and_write_sequences(FILE *file, int num_sequences, int length) {
  for (int i = 0; i < num_sequences; i++) {
    char *sequence = generate_sequence(length);
    write_sequence(sequence, file);
    free(sequence);
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Open a file to write the sequences to
  FILE *file = fopen("sequences.txt", "w");

  // Generate and write the sequences
  generate_and_write_sequences(file, NUM_SEQUENCES, MAX_SEQUENCE_LENGTH);

  // Close the file
  fclose(file);

  return 0;
}