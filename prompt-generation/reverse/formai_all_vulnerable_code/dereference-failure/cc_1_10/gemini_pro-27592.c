//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA base pairs
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_SEQ_LEN 1000

// Define the number of DNA sequences to generate
#define NUM_SEQS 10

// Function to generate a random DNA sequence
char* generate_dna_seq(int len) {
  // Allocate memory for the DNA sequence
  char* seq = malloc(len + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  for (int i = 0; i < len; i++) {
    switch (rand() % 4) {
      case 0:
        seq[i] = A;
        break;
      case 1:
        seq[i] = C;
        break;
      case 2:
        seq[i] = G;
        break;
      case 3:
        seq[i] = T;
        break;
    }
  }

  // Terminate the DNA sequence with a null character
  seq[len] = '\0';

  // Return the DNA sequence
  return seq;
}

// Function to write the DNA sequences to a file
void write_dna_seqs(char** seqs, int num_seqs, char* filename) {
  // Open the file for writing
  FILE* fp = fopen(filename, "w");

  // Write the DNA sequences to the file
  for (int i = 0; i < num_seqs; i++) {
    fprintf(fp, "%s\n", seqs[i]);
  }

  // Close the file
  fclose(fp);
}

// Main function
int main() {
  // Generate the DNA sequences
  char** seqs = malloc(NUM_SEQS * sizeof(char*));
  for (int i = 0; i < NUM_SEQS; i++) {
    seqs[i] = generate_dna_seq(MAX_SEQ_LEN);
  }

  // Write the DNA sequences to a file
  write_dna_seqs(seqs, NUM_SEQS, "dna_seqs.txt");

  // Free the memory allocated for the DNA sequences
  for (int i = 0; i < NUM_SEQS; i++) {
    free(seqs[i]);
  }
  free(seqs);

  return 0;
}