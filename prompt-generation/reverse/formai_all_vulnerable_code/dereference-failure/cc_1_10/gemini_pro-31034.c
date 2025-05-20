//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
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

// Define the error rate
#define ERROR_RATE 0.01

// Function to generate a random nucleotide base
char generate_base() {
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

// Function to generate a random read
char *generate_read(int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Generate the read
  for (int i = 0; i < length; i++) {
    read[i] = generate_base();
  }

  // Null-terminate the read
  read[length] = '\0';

  // Return the read
  return read;
}

// Function to introduce errors into a read
char *introduce_errors(char *read, double error_rate) {
  // Get the length of the read
  int length = strlen(read);

  // Iterate over the read
  for (int i = 0; i < length; i++) {
    // Get a random number between 0 and 1
    double random_number = (double)rand() / (double)RAND_MAX;

    // If the random number is less than the error rate, introduce an error
    if (random_number < error_rate) {
      // Get a random nucleotide base
      char base = generate_base();

      // Replace the current nucleotide base with the random base
      read[i] = base;
    }
  }

  // Return the read
  return read;
}

// Function to write the reads to a file
void write_reads_to_file(char *reads[], int num_reads, char *filename) {
  // Open the file
  FILE *file = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(file, "%s\n", reads[i]);
  }

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char *reads[NUM_READS];
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
  }

  // Introduce errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = introduce_errors(reads[i], ERROR_RATE);
  }

  // Write the reads to a file
  write_reads_to_file(reads, NUM_READS, "reads.txt");

  // Free the memory allocated for the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }

  return 0;
}