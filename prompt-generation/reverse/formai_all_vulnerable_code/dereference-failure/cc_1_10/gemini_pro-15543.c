//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 100000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Define the function to generate a random DNA sequence
char *generate_random_dna_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int base = rand() % 4;

    // Convert the number to a base
    switch (base) {
      case 0:
        sequence[i] = A;
        break;
      case 1:
        sequence[i] = C;
        break;
      case 2:
        sequence[i] = G;
        break;
      case 3:
        sequence[i] = T;
        break;
    }
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Define the function to simulate sequencing errors
char *simulate_sequencing_errors(char *sequence) {
  // Allocate memory for the sequence with errors
  char *sequence_with_errors = malloc(strlen(sequence) + 1);

  // Copy the original sequence into the sequence with errors
  strcpy(sequence_with_errors, sequence);

  // Iterate over the sequence and introduce errors with the specified probability
  for (int i = 0; i < strlen(sequence); i++) {
    // Generate a random number between 0 and 1
    double random_number = ((double)rand() / (double)RAND_MAX);

    // If the random number is less than the error probability, introduce an error
    if (random_number < ERROR_PROBABILITY) {
      // Generate a random number between 0 and 3
      int base = rand() % 4;

      // Convert the number to a base
      switch (base) {
        case 0:
          sequence_with_errors[i] = A;
          break;
        case 1:
          sequence_with_errors[i] = C;
          break;
        case 2:
          sequence_with_errors[i] = G;
          break;
        case 3:
          sequence_with_errors[i] = T;
          break;
      }
    }
  }

  // Terminate the sequence with a null character
  sequence_with_errors[strlen(sequence)] = '\0';

  // Return the sequence with errors
  return sequence_with_errors;
}

// Define the function to write the reads to a file
void write_reads_to_file(char **reads, int num_reads, char *filename) {
  // Open the file for writing
  FILE *file = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(file, "%s\n", reads[i]);
  }

  // Close the file
  fclose(file);
}

// Define the main function
int main() {
  // Generate the random DNA sequences
  char **sequences = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    sequences[i] = generate_random_dna_sequence(MAX_READ_LENGTH);
  }

  // Simulate sequencing errors
  char **sequences_with_errors = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    sequences_with_errors[i] = simulate_sequencing_errors(sequences[i]);
  }

  // Write the reads to a file
  write_reads_to_file(sequences_with_errors, NUM_READS, "reads.txt");

  // Free the memory allocated for the sequences
  for (int i = 0; i < NUM_READS; i++) {
    free(sequences[i]);
    free(sequences_with_errors[i]);
  }
  free(sequences);
  free(sequences_with_errors);

  return 0;
}