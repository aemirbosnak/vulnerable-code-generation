//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
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

// Define the sequencing error rate
#define ERROR_RATE 0.01

// Function to generate a random nucleotide character
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
      return A;  // Default to A to avoid undefined behavior
  }
}

// Function to simulate sequencing errors in a read
void simulate_errors(char *read) {
  // Iterate over each nucleotide in the read
  for (int i = 0; i < strlen(read); i++) {
    // Generate a random number to determine if an error should be introduced
    double random_number = (double)rand() / RAND_MAX;

    // If the random number is less than the error rate, introduce an error
    if (random_number < ERROR_RATE) {
      // Generate a new random nucleotide character
      char new_nucleotide = generate_nucleotide();

      // Replace the existing nucleotide with the new nucleotide
      read[i] = new_nucleotide;
    }
  }
}

// Function to generate a simulated read
char *generate_read() {
  // Allocate memory for the read
  char *read = malloc(MAX_READ_LENGTH + 1);

  // Generate a random length for the read
  int read_length = rand() % MAX_READ_LENGTH + 1;

  // Generate the nucleotides for the read
  for (int i = 0; i < read_length; i++) {
    read[i] = generate_nucleotide();
  }

  // Add a null terminator to the end of the read
  read[read_length] = '\0';

  // Simulate sequencing errors in the read
  simulate_errors(read);

  // Return the read
  return read;
}

// Function to generate a set of simulated reads
char **generate_reads() {
  // Allocate memory for the reads
  char **reads = malloc(NUM_READS * sizeof(char *));

  // Generate each read
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read();
  }

  // Return the reads
  return reads;
}

// Function to print the reads
void print_reads(char **reads) {
  // Iterate over each read
  for (int i = 0; i < NUM_READS; i++) {
    // Print the read
    printf("%s\n", reads[i]);

    // Free the memory allocated for the read
    free(reads[i]);
  }

  // Free the memory allocated for the reads array
  free(reads);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a set of simulated reads
  char **reads = generate_reads();

  // Print the reads
  print_reads(reads);

  return 0;
}