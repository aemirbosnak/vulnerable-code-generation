//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 1000

// Define the number of reads to generate
#define NUM_READS 1000

// Define the length of each read
#define READ_LENGTH 100

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random DNA sequence
char *generate_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate a random sequence of DNA bases
  for (int i = 0; i < length; i++) {
    int base = rand() % 4;
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

  // Add a null terminator to the end of the sequence
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Generate a read from a DNA sequence
char *generate_read(char *sequence, int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Copy the specified number of bases from the sequence into the read
  strncpy(read, sequence, length);

  // Add a null terminator to the end of the read
  read[length] = '\0';

  // Introduce errors into the read
  for (int i = 0; i < length; i++) {
    if (rand() < ERROR_RATE) {
      int base = rand() % 4;
      switch (base) {
        case 0:
          read[i] = A;
          break;
        case 1:
          read[i] = C;
          break;
        case 2:
          read[i] = G;
          break;
        case 3:
          read[i] = T;
          break;
      }
    }
  }

  // Return the read
  return read;
}

// Write the reads to a file
void write_reads(char **reads, int num_reads, int read_length, char *filename) {
  // Open the file for writing
  FILE *file = fopen(filename, "w");

  // Write the reads to the file
  for (int i = 0; i < num_reads; i++) {
    fprintf(file, "%s\n", reads[i]);
  }

  // Close the file
  fclose(file);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a DNA sequence
  char *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

  // Generate reads from the DNA sequence
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(sequence, READ_LENGTH);
  }

  // Write the reads to a file
  write_reads(reads, NUM_READS, READ_LENGTH, "reads.fasta");

  // Free the memory allocated for the sequence and reads
  free(sequence);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}