//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the possible nucleotides
#define A 0
#define C 1
#define G 2
#define T 3

// Define the length of the genome
#define GENOME_LENGTH 1000000

// Define the number of reads
#define READ_COUNT 100000

// Define the read length
#define READ_LENGTH 100

// Define the sequencing error rate
#define ERROR_RATE 0.01

// Generate a random nucleotide
int random_nucleotide() {
  return rand() % 4;
}

// Generate a random read
char *random_read() {
  char *read = malloc(READ_LENGTH + 1);
  for (int i = 0; i < READ_LENGTH; i++) {
    read[i] = "ACGT"[random_nucleotide()];
  }
  read[READ_LENGTH] = '\0';
  return read;
}

// Generate a simulated genome sequence
char *simulate_genome() {
  char *genome = malloc(GENOME_LENGTH + 1);
  for (int i = 0; i < GENOME_LENGTH; i++) {
    genome[i] = "ACGT"[random_nucleotide()];
  }
  genome[GENOME_LENGTH] = '\0';
  return genome;
}

// Generate a simulated read set
char **simulate_reads(char *genome) {
  char **reads = malloc(READ_COUNT * sizeof(char *));
  for (int i = 0; i < READ_COUNT; i++) {
    int start = rand() % (GENOME_LENGTH - READ_LENGTH);
    reads[i] = malloc(READ_LENGTH + 1);
    for (int j = 0; j < READ_LENGTH; j++) {
      reads[i][j] = genome[start + j];
      if (rand() < ERROR_RATE) {
        reads[i][j] = "ACGT"[random_nucleotide()];
      }
    }
    reads[i][READ_LENGTH] = '\0';
  }
  return reads;
}

// Print a genome sequence
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Print a read set
void print_reads(char **reads) {
  for (int i = 0; i < READ_COUNT; i++) {
    printf("%s\n", reads[i]);
  }
}

int main() {
  // Generate a simulated genome sequence
  char *genome = simulate_genome();

  // Generate a simulated read set
  char **reads = simulate_reads(genome);

  // Print the genome sequence
  print_genome(genome);

  // Print the read set
  print_reads(reads);

  return 0;
}