//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads
#define READ_COUNT 10000

// Define the maximum read length
#define MAX_READ_LENGTH 100

// Define the probability of a sequencing error
#define ERROR_PROBABILITY 0.01

// Define the alphabet of DNA bases
char alphabet[] = {'A', 'C', 'G', 'T'};

// Generate a random DNA sequence of the given size
char *generate_genome(int size) {
  // Allocate memory for the genome
  char *genome = malloc(size + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome
  for (int i = 0; i < size; i++) {
    genome[i] = alphabet[rand() % 4];
  }

  // Terminate the genome with a null character
  genome[size] = '\0';

  // Return the genome
  return genome;
}

// Generate a random read of the given length
char *generate_read(int length) {
  // Allocate memory for the read
  char *read = malloc(length + 1);

  // Initialize the random number generator
  srand(time(NULL));

  // Generate the read
  for (int i = 0; i < length; i++) {
    read[i] = alphabet[rand() % 4];
  }

  // Terminate the read with a null character
  read[length] = '\0';

  // Return the read
  return read;
}

// Introduce sequencing errors into the given read
void introduce_errors(char *read, double error_probability) {
  // Initialize the random number generator
  srand(time(NULL));

  // Iterate over the read
  for (int i = 0; i < strlen(read); i++) {
    // Generate a random number
    double r = (double)rand() / RAND_MAX;

    // If the random number is less than the error probability, change the base
    if (r < error_probability) {
      read[i] = alphabet[rand() % 4];
    }
  }
}

// Print the given genome
void print_genome(char *genome, int size) {
  // Iterate over the genome
  for (int i = 0; i < size; i++) {
    // Print the base
    printf("%c", genome[i]);
  }

  // Print a newline
  printf("\n");
}

// Print the given read
void print_read(char *read, int length) {
  // Iterate over the read
  for (int i = 0; i < length; i++) {
    // Print the base
    printf("%c", read[i]);
  }

  // Print a newline
  printf("\n");
}

// Main function
int main() {
  // Generate the genome
  char *genome = generate_genome(GENOME_SIZE);

  // Print the genome
  printf("Genome:\n");
  print_genome(genome, GENOME_SIZE);

  // Generate the reads
  char **reads = malloc(READ_COUNT * sizeof(char *));
  for (int i = 0; i < READ_COUNT; i++) {
    reads[i] = generate_read(MAX_READ_LENGTH);
  }

  // Introduce sequencing errors into the reads
  for (int i = 0; i < READ_COUNT; i++) {
    introduce_errors(reads[i], ERROR_PROBABILITY);
  }

  // Print the reads
  printf("Reads:\n");
  for (int i = 0; i < READ_COUNT; i++) {
    print_read(reads[i], MAX_READ_LENGTH);
  }

  // Free the memory
  free(genome);
  for (int i = 0; i < READ_COUNT; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}