//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a genome sequence
#define MAX_SEQ_LEN 100000

// Define the possible nucleotides
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Define the probability of each nucleotide
double nucleotide_probs[] = {0.25, 0.25, 0.25, 0.25};

// Function to generate a random nucleotide
char generate_nucleotide() {
  // Get a random number between 0 and 1
  double r = (double)rand() / (double)RAND_MAX;

  // Determine which nucleotide corresponds to the random number
  int i;
  for (i = 0; i < 4; i++) {
    if (r < nucleotide_probs[i]) {
      return nucleotides[i];
    }
    r -= nucleotide_probs[i];
  }

  // If the random number is greater than 1, return 'N' (unknown)
  return 'N';
}

// Function to generate a random genome sequence
char *generate_genome_sequence(int len) {
  // Allocate memory for the genome sequence
  char *seq = malloc(len + 1);

  // Generate the genome sequence
  for (int i = 0; i < len; i++) {
    seq[i] = generate_nucleotide();
  }

  // Terminate the genome sequence with a null character
  seq[len] = '\0';

  // Return the genome sequence
  return seq;
}

// Function to print a genome sequence
void print_genome_sequence(char *seq) {
  // Print the genome sequence
  printf("%s\n", seq);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random genome sequence
  char *seq = generate_genome_sequence(MAX_SEQ_LEN);

  // Print the genome sequence
  print_genome_sequence(seq);

  // Free the memory allocated for the genome sequence
  free(seq);

  return 0;
}