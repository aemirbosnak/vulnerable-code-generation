//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible nucleotides
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the length of the genome
#define GENOME_LENGTH 100

// Define the number of reads
#define READ_LENGTH 10
#define NUM_READS 100

// Function to generate a random nucleotide
char generate_nucleotide() {
  int rand_num = rand() % 4;
  switch (rand_num) {
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

// Function to generate a random genome
char *generate_genome() {
  char *genome = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[GENOME_LENGTH] = '\0';
  return genome;
}

// Function to generate a random read
char *generate_read(char *genome) {
  int start_index = rand() % (GENOME_LENGTH - READ_LENGTH + 1);
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = genome[start_index + i];
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Function to generate a set of reads
char **generate_reads(char *genome) {
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(genome);
  }
  return reads;
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random genome
  char *genome = generate_genome();

  // Generate a set of reads
  char **reads = generate_reads(genome);

  // Print the genome
  printf("Genome:\n%s\n", genome);

  // Print the reads
  printf("Reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }

  // Free the memory
  free(genome);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}