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

// Define the maximum length of a read
#define READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Function to generate a random nucleotide base
char generate_base() {
  // Generate a random number between 0 and 3
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
  }
}

// Function to generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < READ_LENGTH; i++) {
    // Generate a random nucleotide base
    char base = generate_base();

    // Check if the base should be mutated
    if ((double)rand() / RAND_MAX < MUTATION_PROBABILITY) {
      // Generate a new random nucleotide base
      base = generate_base();
    }

    // Add the base to the read
    read[i] = base;
  }

  // Terminate the read with a null character
  read[READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Function to write the reads to a file
void write_reads(char **reads, int num_reads, char *filename) {
  // Open the file
  FILE *file = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(file, "%s\n", reads[i]);
  }

  // Close the file
  fclose(file);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read();
  }

  // Write the reads to a file
  write_reads(reads, NUM_READS, "reads.txt");

  // Free the memory allocated for the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}