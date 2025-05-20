//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a sequence
#define MAX_SEQUENCE_LENGTH 10000

// Define the number of sequences to generate
#define NUM_SEQUENCES 10

// Function to generate a random nucleotide base
char generate_nucleotide() {
  // Initialize the random number generator with the current time
  srand(time(NULL));

  // Generate a random number between 0 and 3
  int r = rand() % 4;

  // Return the corresponding nucleotide base
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
      return '\0';
  }
}

// Function to generate a random DNA sequence
char *generate_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate the sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to write a DNA sequence to a file
void write_sequence_to_file(char *sequence, char *filename) {
  // Open the file
  FILE *file = fopen(filename, "w");

  // Write the sequence to the file
  fprintf(file, "%s", sequence);

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Generate the sequences
  char **sequences = malloc(NUM_SEQUENCES * sizeof(char *));
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    sequences[i] = generate_sequence(MAX_SEQUENCE_LENGTH);
  }

  // Write the sequences to files
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    char filename[256];
    sprintf(filename, "sequence%d.txt", i);
    write_sequence_to_file(sequences[i], filename);
  }

  // Free the memory allocated for the sequences
  for (int i = 0; i < NUM_SEQUENCES; i++) {
    free(sequences[i]);
  }
  free(sequences);

  return 0;
}