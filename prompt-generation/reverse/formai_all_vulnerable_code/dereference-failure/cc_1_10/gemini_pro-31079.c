//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA alphabet
char alphabet[] = {'A', 'C', 'G', 'T'};

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 10000

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random DNA sequence
char *generate_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = alphabet[rand() % 4];
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Introduce errors into a DNA sequence
char *introduce_errors(char *sequence, double error_rate) {
  // Allocate memory for the new sequence
  char *new_sequence = malloc(strlen(sequence) + 1);

  // Copy the original sequence to the new sequence
  strcpy(new_sequence, sequence);

  // Introduce errors into the new sequence
  for (int i = 0; i < strlen(sequence); i++) {
    if (rand() / (double)RAND_MAX < error_rate) {
      new_sequence[i] = alphabet[rand() % 4];
    }
  }

  // Return the new sequence
  return new_sequence;
}

// Generate a FASTQ read
char *generate_read(int length, double error_rate) {
  // Generate a random DNA sequence
  char *sequence = generate_sequence(length);

  // Introduce errors into the sequence
  char *read = introduce_errors(sequence, error_rate);

  // Free the original sequence
  free(sequence);

  // Return the read
  return read;
}

// Generate a FASTQ file
void generate_fastq_file(char *filename, int num_reads, int length, double error_rate) {
  // Open the FASTQ file
  FILE *file = fopen(filename, "w");

  // Generate the reads
  for (int i = 0; i < num_reads; i++) {
    // Generate a read
    char *read = generate_read(length, error_rate);

    // Write the read to the file
    fprintf(file, "@%d\n", i);
    fprintf(file, "%s\n", read);
    fprintf(file, "+\n");
    fprintf(file, "%s\n", read);

    // Free the read
    free(read);
  }

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a FASTQ file
  generate_fastq_file("reads.fq", NUM_READS, MAX_READ_LENGTH, ERROR_RATE);

  // Return 0
  return 0;
}