//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of the genome
#define MAX_LENGTH 1000

// Define the number of reads to generate
#define NUM_READS 100

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Function to generate a random nucleotide character
char random_nucleotide() {
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
      return A;
  }
}

// Function to generate a random read
char *random_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    read[i] = random_nucleotide();
  }

  // Add the null terminator
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Function to simulate sequencing errors
char *simulate_errors(char *read) {
  // Allocate memory for the error-prone read
  char *error_prone_read = malloc(MAX_READ_LENGTH + 1);

  // Copy the original read into the error-prone read
  strcpy(error_prone_read, read);

  // Introduce sequencing errors
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    if ((double)rand() / RAND_MAX < ERROR_PROBABILITY) {
      error_prone_read[i] = random_nucleotide();
    }
  }

  // Return the error-prone read
  return error_prone_read;
}

// Function to print the reads
void print_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("Read %d: %s\n", i + 1, reads[i]);
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = random_read();
  }

  // Simulate sequencing errors
  char **error_prone_reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    error_prone_reads[i] = simulate_errors(reads[i]);
  }

  // Print the reads
  printf("Original reads:\n");
  print_reads(reads, NUM_READS);

  printf("\nError-prone reads:\n");
  print_reads(error_prone_reads, NUM_READS);

  // Free the memory allocated for the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
    free(error_prone_reads[i]);
  }
  free(reads);
  free(error_prone_reads);

  return 0;
}