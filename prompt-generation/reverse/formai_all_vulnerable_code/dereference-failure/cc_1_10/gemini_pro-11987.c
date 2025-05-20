//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NUM_BASES 4
#define BASE_LENGTH 50000

// Nucleotide sequences
char bases[] = {'A', 'C', 'G', 'T'};

// Generate a random sequence of nucleotides
void generateSequence(char *sequence) {
  for (int i = 0; i < BASE_LENGTH; i++) {
    sequence[i] = bases[rand() % NUM_BASES];
  }
}

// Read a sequence of nucleotides from a file
void readSequenceFromFile(char *sequence, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }

  char line[BASE_LENGTH];
  while (fgets(line, BASE_LENGTH, file) != NULL) {
    strcat(sequence, line);
  }

  fclose(file);
}

// Write a sequence of nucleotides to a file
void writeSequenceToFile(char *sequence, char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    fprintf(stderr, "Error opening file: %s\n", filename);
    exit(1);
  }

  fprintf(file, "%s", sequence);

  fclose(file);
}

// Main function
int main(int argc, char **argv) {
  // Initialize random seed
  srand(time(NULL));

  // Check if a filename was provided
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  char *filename = argv[1];

  // Create a buffer for the sequence
  char *sequence = malloc(BASE_LENGTH * sizeof(char));

  // Generate a random sequence
  generateSequence(sequence);

  // Write the sequence to a file
  writeSequenceToFile(sequence, filename);

  // Read the sequence back from the file
  readSequenceFromFile(sequence, filename);

  // Print the sequence to the console
  printf("%s\n", sequence);

  // Free the buffer
  free(sequence);

  return 0;
}