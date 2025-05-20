//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide codes
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Sequence length
#define SEQ_LEN 100

// Generate a random nucleotide
char rand_nuc() {
  int r = rand() % 4;
  switch (r) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
    default:
      return 'N';
  }
}

// Simulate Illumina sequencing
char **illumina_seq(char *seq) {
  int num_reads = 100;
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = malloc(SEQ_LEN + 1);
    int start = rand() % (SEQ_LEN - 100);
    for (int j = 0; j < 100; j++) {
      int error = rand() % 10;
      if (error == 0) {
        reads[i][j] = rand_nuc();
      } else {
        reads[i][j] = seq[start + j];
      }
    }
    reads[i][100] = '\0';
  }
  return reads;
}

// Assemble the reads into a consensus sequence
char *assemble(char **reads, int num_reads) {
  char *consensus = malloc(SEQ_LEN + 1);
  for (int i = 0; i < SEQ_LEN; i++) {
    int counts[4] = {0};
    for (int j = 0; j < num_reads; j++) {
      char nuc = reads[j][i];
      switch (nuc) {
        case A:
          counts[0]++;
          break;
        case C:
          counts[1]++;
          break;
        case G:
          counts[2]++;
          break;
        case T:
          counts[3]++;
          break;
      }
    }
    int max_count = 0;
    int max_index = -1;
    for (int k = 0; k < 4; k++) {
      if (counts[k] > max_count) {
        max_count = counts[k];
        max_index = k;
      }
    }
    switch (max_index) {
      case 0:
        consensus[i] = A;
        break;
      case 1:
        consensus[i] = C;
        break;
      case 2:
        consensus[i] = G;
        break;
      case 3:
        consensus[i] = T;
        break;
      default:
        consensus[i] = 'N';
        break;
    }
  }
  consensus[SEQ_LEN] = '\0';
  return consensus;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random sequence
  char *seq = malloc(SEQ_LEN + 1);
  for (int i = 0; i < SEQ_LEN; i++) {
    seq[i] = rand_nuc();
  }
  seq[SEQ_LEN] = '\0';

  // Simulate Illumina sequencing
  char **reads = illumina_seq(seq);

  // Assemble the reads into a consensus sequence
  char *consensus = assemble(reads, 100);

  // Print the original sequence and the consensus sequence
  printf("Original sequence: %s\n", seq);
  printf("Consensus sequence: %s\n", consensus);

  // Free the allocated memory
  free(seq);
  for (int i = 0; i < 100; i++) {
    free(reads[i]);
  }
  free(reads);
  free(consensus);

  return 0;
}