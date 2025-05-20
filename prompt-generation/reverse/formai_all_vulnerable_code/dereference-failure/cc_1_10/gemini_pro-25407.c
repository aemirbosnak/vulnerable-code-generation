//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the DNA sequence alphabet
char alphabet[] = {'A', 'C', 'G', 'T'};

// Define the probability distribution for each nucleotide
double probabilities[] = {0.25, 0.25, 0.25, 0.25};

// Define the length of the genome to be sequenced
int genome_length = 1000000;

// Define the number of reads to be generated
int num_reads = 10000;

// Define the maximum read length
int max_read_length = 100;

// Define the minimum read length
int min_read_length = 50;

// Define the probability of an error in a read
double error_rate = 0.01;

// Define the function to generate a random integer between two values
int rand_int(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Define the function to generate a random nucleotide
char rand_nucleotide() {
  double r = (double)rand() / RAND_MAX;
  int i;
  for (i = 0; i < 4; i++) {
    if (r < probabilities[i]) {
      return alphabet[i];
    }
    r -= probabilities[i];
  }
  return 'N';
}

// Define the function to generate a random read
char *rand_read() {
  int read_length = rand_int(min_read_length, max_read_length);
  char *read = malloc(read_length + 1);
  for (int i = 0; i < read_length; i++) {
    read[i] = rand_nucleotide();
  }
  read[read_length] = '\0';
  return read;
}

// Define the function to insert errors into a read
void insert_errors(char *read) {
  int read_length = strlen(read);
  for (int i = 0; i < read_length; i++) {
    if ((double)rand() / RAND_MAX < error_rate) {
      read[i] = rand_nucleotide();
    }
  }
}

// Define the function to print a read
void print_read(char *read) {
  int read_length = strlen(read);
  for (int i = 0; i < read_length; i++) {
    printf("%c", read[i]);
  }
  printf("\n");
}

// Define the main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate the genome to be sequenced
  char *genome = malloc(genome_length + 1);
  for (int i = 0; i < genome_length; i++) {
    genome[i] = rand_nucleotide();
  }
  genome[genome_length] = '\0';

  // Generate the reads
  char **reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = rand_read();
    insert_errors(reads[i]);
  }

  // Print the reads
  for (int i = 0; i < num_reads; i++) {
    print_read(reads[i]);
  }

  // Free the memory allocated for the genome and reads
  free(genome);
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}