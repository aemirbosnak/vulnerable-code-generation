//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the maximum length of a read
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
      return 'N';
  }
}

// Generate a random read
char *generate_read() {
  // Allocate memory for the read
  char *read = (char *)malloc(MAX_READ_LENGTH + 1);

  // Generate the read
  for (int i = 0; i < MAX_READ_LENGTH; i++) {
    read[i] = generate_nucleotide();
  }

  // Add the null terminator
  read[MAX_READ_LENGTH] = '\0';

  // Return the read
  return read;
}

// Print a read
void print_read(char *read) {
  printf("%s\n", read);
}

// Free the memory allocated for a read
void free_read(char *read) {
  free(read);
}

// Generate a random genome
char *generate_genome(int length) {
  // Allocate memory for the genome
  char *genome = (char *)malloc(length + 1);

  // Generate the genome
  for (int i = 0; i < length; i++) {
    genome[i] = generate_nucleotide();
  }

  // Add the null terminator
  genome[length] = '\0';

  // Return the genome
  return genome;
}

// Print a genome
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Free the memory allocated for a genome
void free_genome(char *genome) {
  free(genome);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random genome
  char *genome = generate_genome(1000);

  // Print the genome
  print_genome(genome);

  // Generate a random read
  char *read = generate_read();

  // Print the read
  print_read(read);

  // Free the memory allocated for the genome and the read
  free_genome(genome);
  free_read(read);

  return 0;
}