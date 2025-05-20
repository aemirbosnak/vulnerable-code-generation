//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_SIZE 1000000
#define MAX_READ_LENGTH 100

// Nucleotide types
typedef enum {
  A, C, G, T
} Nucleotide;

// Read structure
typedef struct {
  char* sequence;
  int length;
} Read;

// Genome structure
typedef struct {
  char* sequence;
  int length;
} Genome;

// Function to generate a random nucleotide
Nucleotide random_nucleotide() {
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
      return A;
  }
}

// Function to generate a random genome
Genome generate_genome(int length) {
  Genome genome;
  genome.sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome.sequence[i] = random_nucleotide();
  }
  genome.sequence[length] = '\0';
  genome.length = length;
  return genome;
}

// Function to generate a random read from a genome
Read generate_read(Genome genome) {
  int start = rand() % (genome.length - MAX_READ_LENGTH);
  int length = rand() % (MAX_READ_LENGTH - 1) + 1;
  Read read;
  read.sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read.sequence[i] = genome.sequence[start + i];
  }
  read.sequence[length] = '\0';
  read.length = length;
  return read;
}

// Function to print a genome
void print_genome(Genome genome) {
  printf("Genome:\n");
  for (int i = 0; i < genome.length; i++) {
    printf("%c", genome.sequence[i]);
  }
  printf("\n");
}

// Function to print a read
void print_read(Read read) {
  printf("Read:\n");
  for (int i = 0; i < read.length; i++) {
    printf("%c", read.sequence[i]);
  }
  printf("\n");
}

// Main function
int main() {
  srand(time(NULL));

  // Generate a genome
  Genome genome = generate_genome(MAX_GENOME_SIZE);

  // Print the genome
  print_genome(genome);

  // Generate a read from the genome
  Read read = generate_read(genome);

  // Print the read
  print_read(read);

  return 0;
}