//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: unmistakable
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
#define NUM_READS 1000

// Define the error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide base
char random_base() {
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
  return '\0';
}

// Generate a random read of a given length
char *generate_read(int length) {
  char *read = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read[i] = random_base();
  }
  read[length] = '\0';
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read) {
  int length = strlen(read);
  for (int i = 0; i < length; i++) {
    if (rand() < ERROR_RATE) {
      read[i] = random_base();
    }
  }
}

// Print a read
void print_read(char *read) {
  printf("%s\n", read);
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

  // Introduce errors into the reads
  for (int i = 0; i < NUM_READS; i++) {
    introduce_errors(reads[i]);
  }

  // Print the reads
  for (int i = 0; i < NUM_READS; i++) {
    print_read(reads[i]);
  }

  // Free the reads
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}