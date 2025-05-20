//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 10000

// Define the four DNA bases
char bases[] = {'A', 'C', 'G', 'T'};

// Function to generate a random DNA sequence
char* generate_dna_sequence(int length) {
  // Allocate memory for the DNA sequence
  char* sequence = malloc(length + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the DNA sequence
  for (int i = 0; i < length; i++) {
    sequence[i] = bases[rand() % 4];
  }

  // Add the null terminator to the end of the sequence
  sequence[length] = '\0';

  // Return the DNA sequence
  return sequence;
}

// Function to write a DNA sequence to a file
void write_dna_sequence_to_file(char* sequence, char* filename) {
  // Open the file for writing
  FILE* file = fopen(filename, "w");

  // Write the DNA sequence to the file
  fprintf(file, "%s", sequence);

  // Close the file
  fclose(file);
}

// Main function
int main() {
  // Get the length of the DNA sequence from the user
  int length;
  printf("Enter the length of the DNA sequence: ");
  scanf("%d", &length);

  // Generate a random DNA sequence
  char* sequence = generate_dna_sequence(length);

  // Write the DNA sequence to a file
  write_dna_sequence_to_file(sequence, "dna_sequence.txt");

  // Free the memory allocated for the DNA sequence
  free(sequence);

  // Return 0 to indicate successful execution
  return 0;
}