//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
#define MAX_READ_LENGTH 100

// Define the number of reads to generate
#define NUM_READS 1000

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide
char generate_nucleotide() {
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
  }
}

// Generate a random read of a given length
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = generate_nucleotide();
  }
  read[length] = '\0';
  return read;
}

// Introduce sequencing errors into a read
void introduce_errors(char *read, int length) {
  for (int i = 0; i < length; i++) {
    if ((double)rand() / RAND_MAX < ERROR_PROBABILITY) {
      read[i] = generate_nucleotide();
    }
  }
}

// Print a read to the console
void print_read(char *read, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", read[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the reads
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
  }

  // Introduce sequencing errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    introduce_errors(reads[i], MAX_READ_LENGTH);
  }

  // Print the reads to the console
  for (int i = 0; i < NUM_READS; i++) {
    print_read(reads[i], MAX_READ_LENGTH);
  }

  // Free the memory allocated for the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}