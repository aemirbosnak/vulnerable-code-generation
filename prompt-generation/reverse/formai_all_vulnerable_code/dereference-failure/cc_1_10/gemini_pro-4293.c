//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Define the sequencing error probabilities
#define ERROR_PROB_SUBSTITUTION 0.01
#define ERROR_PROB_INSERTION 0.001
#define ERROR_PROB_DELETION 0.001

// Generate a random nucleotide base
int random_base() {
  int r = rand() % 4;
  return r;
}

// Generate a random error type
int random_error_type() {
  double r = ((double) rand() / (RAND_MAX));
  if (r < ERROR_PROB_SUBSTITUTION) {
    return 0; // Substitution
  } else if (r < ERROR_PROB_SUBSTITUTION + ERROR_PROB_INSERTION) {
    return 1; // Insertion
  } else {
    return 2; // Deletion
  }
}

// Generate a random error position
int random_error_position(int length) {
  int r = rand() % length;
  return r;
}

// Generate a simulated C genome sequence
char *simulate_genome(int length) {
  // Allocate memory for the genome sequence
  char *genome = (char *) malloc(sizeof(char) * length);

  // Generate a random sequence of nucleotide bases
  for (int i = 0; i < length; i++) {
    genome[i] = random_base();
  }

  // Introduce sequencing errors
  for (int i = 0; i < length; i++) {
    // Generate a random error type
    int error_type = random_error_type();

    // Generate a random error position
    int error_position = random_error_position(length);

    // Apply the error
    switch (error_type) {
      case 0: // Substitution
        genome[error_position] = random_base();
        break;
      case 1: // Insertion
        genome[error_position] = random_base();
        break;
      case 2: // Deletion
        genome[error_position] = '\0';
        break;
    }
  }

  return genome;
}

// Print the simulated C genome sequence
void print_genome(char *genome, int length) {
  for (int i = 0; i < length; i++) {
    switch (genome[i]) {
      case A:
        printf("A");
        break;
      case C:
        printf("C");
        break;
      case G:
        printf("G");
        break;
      case T:
        printf("T");
        break;
      default:
        printf("N");
        break;
    }
  }

  printf("\n");
}

int main() {
  // Set the random seed
  srand(42);

  // Generate a simulated C genome sequence
  char *genome = simulate_genome(1000);

  // Print the simulated C genome sequence
  print_genome(genome, 1000);

  // Free the memory allocated for the genome sequence
  free(genome);

  return 0;
}