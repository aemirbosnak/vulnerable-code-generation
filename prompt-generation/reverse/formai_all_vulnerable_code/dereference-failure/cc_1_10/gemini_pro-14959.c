//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
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
#define NUM_READS 10000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide base
char generate_base() {
  int random_number = rand() % 4;
  switch (random_number) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
    default:
      return A;
  }
}

// Generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    // Generate a random nucleotide base
    char base = generate_base();

    // Introduce a sequencing error with a probability of ERROR_PROBABILITY
    if ((double)rand() / RAND_MAX < ERROR_PROBABILITY) {
      // Generate a random nucleotide base
      base = generate_base();
    }

    // Add the nucleotide base to the read
    read[i] = base;
  }

  // Add the null terminator to the read
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Generate a genome sequencing dataset
void generate_genome_sequencing_dataset() {
  // Open the output file
  FILE *output_file = fopen("genome_sequencing_dataset.txt", "w");

  // Generate the reads
  for (int i = 0; i < NUM_READS; i++) {
    // Generate a random read
    char *read = generate_read();

    // Write the read to the output file
    fprintf(output_file, "%s\n", read);

    // Free the memory allocated for the read
    free(read);
  }

  // Close the output file
  fclose(output_file);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome sequencing dataset
  generate_genome_sequencing_dataset();

  return 0;
}