//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: inquisitive
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
#define NUM_READS 100

// Define the length of each read
#define READ_LENGTH 100

// Function to generate a random DNA sequence
char *generate_random_sequence(int length) {
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

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to generate a set of reads from a DNA sequence
char **generate_reads(char *sequence, int length, int num_reads, int read_length) {
  // Allocate memory for the reads
  char **reads = malloc(num_reads * sizeof(char *));

  // Generate a set of reads from the sequence
  for (int i = 0; i < num_reads; i++) {
    // Generate a random starting position for the read
    int start = rand() % (length - read_length + 1);

    // Allocate memory for the read
    reads[i] = malloc(read_length + 1);

    // Copy the read from the sequence
    strncpy(reads[i], sequence + start, read_length);

    // Terminate the read with a null character
    reads[i][read_length] = '\0';
  }

  // Return the reads
  return reads;
}

// Function to print a set of reads
void print_reads(char **reads, int num_reads, int read_length) {
  // Print the reads
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);

  // Generate a set of reads from the sequence
  char **reads = generate_reads(sequence, MAX_SEQUENCE_LENGTH, NUM_READS, READ_LENGTH);

  // Print the reads
  print_reads(reads, NUM_READS, READ_LENGTH);

  // Free the memory allocated for the sequence and reads
  free(sequence);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}