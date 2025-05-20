//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Nucleotide codes
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Error probability
#define ERROR_PROB 0.01

// Maximum read length
#define MAX_READ_LENGTH 100

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
    default:
      return A;  // Default to A if something goes wrong
  }
}

// Introduce errors into a read
void introduce_errors(char *read, int length) {
  for (int i = 0; i < length; i++) {
    if ((double)rand() / (double)RAND_MAX < ERROR_PROB) {
      int r = rand() % 4;
      switch (r) {
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
}

// Generate a random read
char *generate_read() {
  int length = rand() % MAX_READ_LENGTH + 1;  // Read length between 1 and MAX_READ_LENGTH
  char *read = malloc(length + 1);  // Allocate memory for the read
  for (int i = 0; i < length; i++) {
    read[i] = generate_nucleotide();
  }
  read[length] = '\0';  // Terminate the string
  introduce_errors(read, length);  // Introduce errors into the read
  return read;
}

// Generate a simulated genome
char *generate_genome(int length) {
  char *genome = malloc(length + 1);  // Allocate memory for the genome
  for (int i = 0; i < length; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[length] = '\0';  // Terminate the string
  return genome;
}

// Print a sequence
void print_sequence(char *sequence, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", sequence[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a simulated genome
  char *genome = generate_genome(10000);

  // Generate 100 reads from the genome
  for (int i = 0; i < 100; i++) {
    char *read = generate_read();
    print_sequence(read, strlen(read));
    free(read);  // Free the memory allocated for the read
  }

  // Free the memory allocated for the genome
  free(genome);

  return 0;
}