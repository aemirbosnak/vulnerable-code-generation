//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random nucleotide
char generate_nucleotide() {
  int rand_num = rand() % 4;
  switch (rand_num) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
  return 'N'; // Should never reach here
}

// Function to generate a random DNA sequence of a given length
char *generate_dna_sequence(int length) {
  char *sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate a sequencing run of a given length
char *simulate_sequencing_run(int length) {
  char *sequence = generate_dna_sequence(length);
  // Introduce some sequencing errors
  int num_errors = rand() % 10;
  for (int i = 0; i < num_errors; i++) {
    int error_index = rand() % length;
    sequence[error_index] = generate_nucleotide();
  }
  return sequence;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Specify the length of the DNA sequence to be simulated
  int length = 1000;

  // Generate a random DNA sequence and simulate a sequencing run
  char *sequence = simulate_sequencing_run(length);

  // Print the simulated sequencing data
  printf("Simulated sequencing data:\n%s\n", sequence);

  // Free the allocated memory
  free(sequence);

  return 0;
}