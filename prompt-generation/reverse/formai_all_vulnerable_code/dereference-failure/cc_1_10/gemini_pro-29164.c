//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated genome sequence
char *genome;

// Simulated sequencing reads
char **reads;

// Number of reads
int num_reads;

// Read length
int read_length;

// Error rate
double error_rate;

// Initialize the genome sequence
void init_genome(int length) {
  genome = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    genome[i] = 'A' + rand() % 4;
  }
  genome[length] = '\0';
}

// Initialize the sequencing reads
void init_reads(int num_reads, int read_length) {
  reads = malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = malloc(read_length + 1);
  }
}

// Generate a simulated sequencing read
void generate_read(char *read, int start, int length) {
  for (int i = 0; i < length; i++) {
    read[i] = genome[start + i];
    if (rand() / (double)RAND_MAX < error_rate) {
      read[i] = 'A' + rand() % 4;
    }
  }
  read[length] = '\0';
}

// Print the genome sequence
void print_genome() {
  printf("Genome sequence:\n%s\n", genome);
}

// Print the sequencing reads
void print_reads() {
  printf("Sequencing reads:\n");
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the genome sequence and sequencing reads
void free_memory() {
  free(genome);
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);
}

// Main function
int main(int argc, char *argv[]) {
  // Get the command line arguments
  if (argc != 5) {
    printf("Usage: %s <genome_length> <num_reads> <read_length> <error_rate>\n", argv[0]);
    return 1;
  }

  // Parse the command line arguments
  int genome_length = atoi(argv[1]);
  num_reads = atoi(argv[2]);
  read_length = atoi(argv[3]);
  error_rate = atof(argv[4]);

  // Initialize the random number generator
  srand(time(NULL));

  // Initialize the genome sequence
  init_genome(genome_length);

  // Initialize the sequencing reads
  init_reads(num_reads, read_length);

  // Generate the simulated sequencing reads
  for (int i = 0; i < num_reads; i++) {
    int start = rand() % (genome_length - read_length);
    generate_read(reads[i], start, read_length);
  }

  // Print the genome sequence
  print_genome();

  // Print the sequencing reads
  print_reads();

  // Free the memory allocated for the genome sequence and sequencing reads
  free_memory();

  return 0;
}