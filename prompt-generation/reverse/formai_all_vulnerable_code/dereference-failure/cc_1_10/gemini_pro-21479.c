//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide base
char generate_base() {
  // Get a random number between 0 and 3
  int r = rand() % 4;

  // Return the corresponding nucleotide base
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
      return '\0';
  }
}

// Generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    // Get a random nucleotide base
    char base = generate_base();

    // Introduce a sequencing error with a probability of ERROR_PROBABILITY
    if ((double)rand() / RAND_MAX < ERROR_PROBABILITY) {
      // Get a random nucleotide base
      base = generate_base();
    }

    // Add the nucleotide base to the read
    read[i] = base;
  }

  // Terminate the read with a null character
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Generate a set of reads
char **generate_reads() {
  // Allocate memory for the reads
  char **reads = malloc(NUM_READS * sizeof(char *));

  // Generate the reads
  for (int i = 0; i < NUM_READS; i++) {
    // Generate a random read
    reads[i] = generate_read();
  }

  // Return the reads
  return reads;
}

// Print the reads
void print_reads(char **reads) {
  // Print the reads to the console
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the reads
void free_reads(char **reads) {
  // Free the memory allocated for each read
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }

  // Free the memory allocated for the array of reads
  free(reads);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a set of reads
  char **reads = generate_reads();

  // Print the reads
  print_reads(reads);

  // Free the memory allocated for the reads
  free_reads(reads);

  return 0;
}