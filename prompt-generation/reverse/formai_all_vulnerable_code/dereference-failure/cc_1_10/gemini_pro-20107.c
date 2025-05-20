//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: retro
/*************************************************************************
 * C Genome Sequencing Simulator                                         *
 *                                                                       *
 * A simple program that simulates the process of genome sequencing.        *
 *                                                                       *
 * Usage:                                                               *
 *   ./genome_sequencer <input file> <output file>                        *
 *                                                                       *
 * Input file:                                                          *
 *   A FASTA file containing the reference genome.                         *
 *                                                                       *
 * Output file:                                                         *
 *   A FASTA file containing the simulated reads.                        *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Maximum read length
#define MAX_READ_LENGTH 100

// Error rate
#define ERROR_RATE 0.01

// Function to generate a random number between 0 and 1
double rand_01() {
  return (double)rand() / (double)RAND_MAX;
}

// Function to generate a random read of length n
char *generate_read(char *genome, int n) {
  // Allocate memory for the read
  char *read = malloc(n + 1);

  // Copy the first n characters from the genome to the read
  strncpy(read, genome, n);

  // Add a null terminator to the end of the read
  read[n] = '\0';

  // Introduce errors into the read
  for (int i = 0; i < n; i++) {
    if (rand_01() < ERROR_RATE) {
      // Flip a random bit in the read
      read[i] = read[i] ^ (1 << (rand() % 8));
    }
  }

  // Return the read
  return read;
}

// Function to simulate the genome sequencing process
void simulate_genome_sequencing(char *input_file, char *output_file) {
  // Open the input file
  FILE *input = fopen(input_file, "r");
  if (input == NULL) {
    fprintf(stderr, "Error: could not open input file %s\n", input_file);
    exit(1);
  }

  // Open the output file
  FILE *output = fopen(output_file, "w");
  if (output == NULL) {
    fprintf(stderr, "Error: could not open output file %s\n", output_file);
    exit(1);
  }

  // Read the reference genome from the input file
  char *genome = NULL;
  size_t len = 0;
  getline(&genome, &len, input);

  // Remove the newline character from the end of the genome
  genome[strlen(genome) - 1] = '\0';

  // Generate simulated reads from the reference genome
  for (int i = 0; i < 10000; i++) {
    // Generate a random read length
    int read_length = rand() % MAX_READ_LENGTH + 1;

    // Generate a random read
    char *read = generate_read(genome, read_length);

    // Write the read to the output file
    fprintf(output, ">read%d\n", i);
    fprintf(output, "%s\n", read);

    // Free the memory allocated for the read
    free(read);
  }

  // Close the input and output files
  fclose(input);
  fclose(output);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments has been provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
    exit(1);
  }

  // Seed the random number generator
  srand(time(NULL));

  // Simulate the genome sequencing process
  simulate_genome_sequencing(argv[1], argv[2]);

  return 0;
}