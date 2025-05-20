//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a sequence
#define MAX_SEQ_LEN 10000

// Define the number of sequences to generate
#define NUM_SEQS 100

// Define the probability of each nucleotide base
#define PROB_A 0.25
#define PROB_C 0.25
#define PROB_G 0.25
#define PROB_T 0.25

// Generate a random nucleotide base
char generate_base() {
  double r = (double)rand() / RAND_MAX;

  if (r < PROB_A) {
    return A;
  } else if (r < PROB_A + PROB_C) {
    return C;
  } else if (r < PROB_A + PROB_C + PROB_G) {
    return G;
  } else {
    return T;
  }
}

// Generate a random sequence
char *generate_sequence(int len) {
  char *seq = malloc(len + 1);

  for (int i = 0; i < len; i++) {
    seq[i] = generate_base();
  }

  seq[len] = '\0';

  return seq;
}

// Write a sequence to a file
void write_sequence(char *seq, char *filename) {
  FILE *file = fopen(filename, "w");

  fprintf(file, "%s", seq);

  fclose(file);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the sequences
  for (int i = 0; i < NUM_SEQS; i++) {
    char *seq = generate_sequence(MAX_SEQ_LEN);

    // Write the sequence to a file
    char filename[256];
    snprintf(filename, 256, "sequence_%d.txt", i);
    write_sequence(seq, filename);

    // Free the sequence
    free(seq);
  }

  return 0;
}