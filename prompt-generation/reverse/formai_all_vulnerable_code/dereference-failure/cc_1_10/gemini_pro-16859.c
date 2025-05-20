//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the nucleotide bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the read length
#define READ_LENGTH 100

// Define the number of reads
#define NUM_READS 1000

// Define the error rate
#define ERROR_RATE 0.01

// Define the sequencing machine
typedef struct {
  char* sequence;
  int length;
} Read;

// Generate a random nucleotide base
char generate_base() {
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
  }
}

// Generate a random read
Read generate_read(int length) {
  Read read;
  read.sequence = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    read.sequence[i] = generate_base();
  }
  read.sequence[length] = '\0';
  read.length = length;
  return read;
}

// Introduce errors into a read
void introduce_errors(Read* read) {
  for (int i = 0; i < read->length; i++) {
    if (rand() < ERROR_RATE) {
      read->sequence[i] = generate_base();
    }
  }
}

// Simulate the sequencing process
Read* simulate_sequencing(int num_reads, int length) {
  Read* reads = malloc(num_reads * sizeof(Read));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_read(length);
    introduce_errors(&reads[i]);
  }
  return reads;
}

// Print the reads
void print_reads(Read* reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i].sequence);
  }
}

// Free the reads
void free_reads(Read* reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i].sequence);
  }
  free(reads);
}

int main() {
  // Set the random seed
  srand(time(NULL));

  // Simulate the sequencing process
  Read* reads = simulate_sequencing(NUM_READS, READ_LENGTH);

  // Print the reads
  print_reads(reads, NUM_READS);

  // Free the reads
  free_reads(reads, NUM_READS);

  return 0;
}