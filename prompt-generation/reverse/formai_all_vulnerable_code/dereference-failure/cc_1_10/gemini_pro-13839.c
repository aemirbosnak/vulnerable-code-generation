//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
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
    default:
      return A;  // Default to A to avoid undefined behavior
  }
}

// Function to generate a random read
char *generate_read(int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Generate the read
  for (int i = 0; i < length; i++) {
    // Generate a random nucleotide base
    char base = generate_base();

    // Introduce a sequencing error with a certain probability
    if ((double)rand() / RAND_MAX < ERROR_PROBABILITY) {
      // Generate a random error base
      int error_r = rand() % 4;
      switch (error_r) {
        case 0:
          base = A;
          break;
        case 1:
          base = C;
          break;
        case 2:
          base = G;
          break;
        case 3:
          base = T;
          break;
      }
    }

    // Store the base in the read
    read[i] = base;
  }

  // Terminate the read with a null character
  read[length] = '\0';

  // Return the read
  return read;
}

// Function to write the reads to a file
void write_reads(char **reads, int num_reads, char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(fp, "%s\n", reads[i]);
  }

  // Close the file
  fclose(fp);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
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