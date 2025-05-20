//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the size of the genome
#define GENOME_SIZE 1000000

// Define the number of reads
#define NUM_READS 10000

// Define the length of the reads
#define READ_LENGTH 100

// Create a function to generate a random nucleotide
char generate_nucleotide() {
  int r = rand() % 4;
  switch (r) {
    case 0:
      return 'A';
    case 1:
      return 'C';
    case 2:
      return 'G';
    case 3:
      return 'T';
  }
  return 'N';
}

// Create a function to generate a random genome
char *generate_genome() {
  char *genome = malloc(GENOME_SIZE + 1);
  for (int i = 0; i < GENOME_SIZE; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[GENOME_SIZE] = '\0';
  return genome;
}

// Create a function to generate a random read
char *generate_read(char *genome) {
  int start = rand() % (GENOME_SIZE - READ_LENGTH);
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = genome[start + i];
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Create a function to simulate genome sequencing
char **simulate_genome_sequencing(char *genome) {
  char **reads = malloc(NUM_READS * sizeof(char *));
  for (int i = 0; i < NUM_READS; i++) {
    reads[i] = generate_read(genome);
  }
  return reads;
}

// Create a function to print the genome and reads
void print_genome_and_reads(char *genome, char **reads) {
  printf("Genome:\n%s\n", genome);
  printf("Reads:\n");
  for (int i = 0; i < NUM_READS; i++) {
    printf("%s\n", reads[i]);
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate the genome
  char *genome = generate_genome();

  // Simulate genome sequencing
  char **reads = simulate_genome_sequencing(genome);

  // Print the genome and reads
  print_genome_and_reads(genome, reads);

  // Free the memory
  free(genome);
  for (int i = 0; i < NUM_READS; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}