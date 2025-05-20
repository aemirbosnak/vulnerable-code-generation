//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

// Error probabilities
#define ERROR_RATE 0.01

// Function to generate a random nucleotide base
char generate_base() {
  int random_number = rand() % 4;
  switch (random_number) {
    case A:
      return 'A';
    case C:
      return 'C';
    case G:
      return 'G';
    case T:
      return 'T';
    default:
      return 'N';  // Invalid base
  }
}

// Function to generate a read with errors
char* generate_read(int length) {
  // Allocate memory for the read
  char* read = malloc(length + 1);

  // Generate the read
  for (int i = 0; i < length; i++) {
    // Generate a random base
    char base = generate_base();

    // Introduce an error with a probability of ERROR_RATE
    if ((double)rand() / RAND_MAX < ERROR_RATE) {
      // Generate a random error
      int error_type = rand() % 3;
      switch (error_type) {
        case 0:  // Substitution error
          base = generate_base();
          break;
        case 1:  // Insertion error
          read[i + 1] = base;
          length++;
          break;
        case 2:  // Deletion error
          i--;
          break;
      }
    }

    // Store the base in the read
    read[i] = base;
  }

  // Terminate the read with a null character
  read[length] = '\0';

  return read;
}

// Function to print a read
void print_read(char* read) {
  printf("%s\n", read);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a read of length 100
  char* read = generate_read(100);

  // Print the read
  print_read(read);

  // Free the memory allocated for the read
  free(read);

  return 0;
}