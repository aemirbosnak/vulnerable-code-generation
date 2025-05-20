//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
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

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Generate a random nucleotide base
char generate_nucleotide() {
  // Get a random number between 0 and 3
  int random_number = rand() % 4;

  // Return the corresponding nucleotide base
  switch (random_number) {
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

// Generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    // Get a random nucleotide base
    char nucleotide = generate_nucleotide();

    // Check if the nucleotide should be mutated
    if (rand() < MUTATION_PROBABILITY * RAND_MAX) {
      // Get a random nucleotide base to mutate to
      char mutation = generate_nucleotide();

      // Mutate the nucleotide
      nucleotide = mutation;
    }

    // Add the nucleotide to the read
    read[i] = nucleotide;
  }

  // Add the null terminator to the read
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Generate a set of reads
char **generate_reads(int num_reads) {
  // Allocate memory for the reads
  char **reads = malloc(num_reads * sizeof(char *));

  // Generate the reads
  for (int i = 0; i < num_reads; i++) {
    // Generate a read
    char *read = generate_read();

    // Add the read to the set of reads
    reads[i] = read;
  }

  // Return the set of reads
  return reads;
}

// Print a set of reads
void print_reads(char **reads, int num_reads) {
  // Print each read
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free a set of reads
void free_reads(char **reads, int num_reads) {
  // Free each read
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }

  // Free the set of reads
  free(reads);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a set of reads
  char **reads = generate_reads(NUM_READS);

  // Print the set of reads
  print_reads(reads, NUM_READS);

  // Free the set of reads
  free_reads(reads, NUM_READS);

  return 0;
}