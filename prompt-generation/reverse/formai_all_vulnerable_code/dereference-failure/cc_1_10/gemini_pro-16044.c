//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome
#define GENOME_LENGTH 1000000

// Define the number of reads
#define READ_COUNT 100000

// Define the maximum read length
#define READ_LENGTH 100

// Define the probability of an error in a read
#define ERROR_PROBABILITY 0.01

// Generate a random nucleotide
char generate_nucleotide() {
  // Get a random number between 0 and 3
  int random_number = rand() % 4;

  // Return the corresponding nucleotide
  switch (random_number) {
    case 0:
      return A;
    case 1:
      return C;
    case 2:
      return G;
    case 3:
      return T;
  }
}

// Generate a random genome
char *generate_genome() {
  // Allocate memory for the genome
  char *genome = malloc(GENOME_LENGTH + 1);

  // Generate each nucleotide in the genome
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = generate_nucleotide();
  }

  // Add a null terminator to the end of the genome
  genome[GENOME_LENGTH] = '\0';

  // Return the genome
  return genome;
}

// Generate a random read from the genome
char *generate_read(char *genome) {
  // Get a random start position for the read
  int start_position = rand() % GENOME_LENGTH;

  // Get a random length for the read
  int read_length = rand() % READ_LENGTH + 1;

  // Allocate memory for the read
  char *read = malloc(read_length + 1);

  // Copy the nucleotides from the genome into the read
  for (int i = 0; i < read_length; i++) {
    read[i] = genome[start_position + i];
  }

  // Add a null terminator to the end of the read
  read[read_length] = '\0';

  // Return the read
  return read;
}

// Introduce errors into a read
void introduce_errors(char *read) {
  // Get the length of the read
  int read_length = strlen(read);

  // Iterate over each nucleotide in the read
  for (int i = 0; i < read_length; i++) {
    // Get a random number between 0 and 1
    double random_number = (double)rand() / RAND_MAX;

    // If the random number is less than the error probability, then introduce an error
    if (random_number < ERROR_PROBABILITY) {
      // Get a random nucleotide
      char new_nucleotide = generate_nucleotide();

      // Replace the nucleotide in the read with the new nucleotide
      read[i] = new_nucleotide;
    }
  }
}

// Print the genome and the reads
void print_genome_and_reads(char *genome, char **reads) {
  // Print the genome
  printf("Genome:\n%s\n", genome);

  // Print the reads
  printf("Reads:\n");
  for (int i = 0; i < READ_COUNT; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the genome and the reads
void free_genome_and_reads(char *genome, char **reads) {
  // Free the memory allocated for the genome
  free(genome);

  // Free the memory allocated for the reads
  for (int i = 0; i < READ_COUNT; i++) {
    free(reads[i]);
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_genome();

  // Generate the reads
  char **reads = malloc(READ_COUNT * sizeof(char *));
  for (int i = 0; i < READ_COUNT; i++) {
    reads[i] = generate_read(genome);
  }

  // Introduce errors into the reads
  for (int i = 0; i < READ_COUNT; i++) {
    introduce_errors(reads[i]);
  }

  // Print the genome and the reads
  print_genome_and_reads(genome, reads);

  // Free the memory allocated for the genome and the reads
  free_genome_and_reads(genome, reads);

  return 0;
}