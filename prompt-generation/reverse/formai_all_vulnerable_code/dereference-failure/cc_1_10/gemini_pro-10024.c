//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the nucleotide characters
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the read length
#define READ_LENGTH 100

// Define the number of reads
#define NUM_READS 1000

// Define the genome size
#define GENOME_SIZE 1000000

// Define the error rate
#define ERROR_RATE 0.01

// Function to generate a random nucleotide
char generate_nucleotide() {
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

// Function to generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = generate_nucleotide();
  }

  // Add the null terminator
  read[READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Function to simulate sequencing errors
char *simulate_errors(char *read) {
  // Allocate memory for the read with errors
  char *read_with_errors = malloc(READ_LENGTH + 1);

  // Copy the read into the read with errors
  strcpy(read_with_errors, read);

  // Simulate the errors
  for (int i = 0; i < READ_LENGTH; i++) {
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
      read_with_errors[i] = generate_nucleotide();
    }
  }

  // Add the null terminator
  read_with_errors[READ_LENGTH] = '\0';

  // Return the read with errors
  return read_with_errors;
}

// Function to write the reads to a file
void write_reads_to_file(char **reads, int num_reads, char *filename) {
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
  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read();
  }

  // Simulate the sequencing errors
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = simulate_errors(reads[i]);
  }

  // Write the reads to a file
  write_reads_to_file(reads, NUM_READS, "reads.txt");

  // Free the memory
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}