//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide character
char generate_nucleotide() {
  // Generate a random number between 0 and 3
  int random_number = rand() % 4;

  // Return the corresponding nucleotide character
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
      return A;  // Default to A in case of an invalid random number
  }
}

// Generate a random read
char *generate_read(int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Generate the read nucleotides
  for (int i = 0; i < length; i++) {
    read[i] = generate_nucleotide();
  }

  // Add the null terminator
  read[length] = '\0';

  // Return the read
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read, int length) {
  // Loop through the read nucleotides
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 1
    double random_number = (double)rand() / RAND_MAX;

    // If the random number is less than the error rate, introduce an error
    if (random_number < ERROR_RATE) {
      // Generate a new random nucleotide character
      char new_nucleotide = generate_nucleotide();

      // Replace the original nucleotide with the new nucleotide
      read[i] = new_nucleotide;
    }
  }
}

// Print the reads to a file
void print_reads(char **reads, int num_reads, int length) {
  // Open the file for writing
  FILE *file = fopen("reads.txt", "w");

  // Loop through the reads
  for (int i = 0; i < num_reads; i++) {
    // Write the read to the file
    fprintf(file, "%s\n", reads[i]);
  }

  // Close the file
  fclose(file);
}

// Free the memory allocated for the reads
void free_reads(char **reads, int num_reads) {
  // Loop through the reads
  for (int i = 0; i < num_reads; i++) {
    // Free the memory allocated for the read
    free(reads[i]);
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
  }

  // Introduce errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    introduce_errors(reads[i], MAX_READ_LENGTH);
  }

  // Print the reads to a file
  print_reads(reads, NUM_READS, MAX_READ_LENGTH);

  // Free the memory allocated for the reads
  free_reads(reads, NUM_READS);

  return 0;
}