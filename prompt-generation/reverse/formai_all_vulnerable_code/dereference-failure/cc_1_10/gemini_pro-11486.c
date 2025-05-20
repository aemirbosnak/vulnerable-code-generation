//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Define the genome length
int genome_length = 1000000;

// Define the mutation rate
double mutation_rate = 0.01;

// Define the sequencing error rate
double sequencing_error_rate = 0.02;

// Generate a random nucleotide
char generate_nucleotide() {
  return nucleotides[rand() % 4];
}

// Generate a random genome
char *generate_genome() {
  char *genome = malloc(genome_length + 1);
  for (int i = 0; i < genome_length; i++) {
    genome[i] = generate_nucleotide();
  }
  genome[genome_length] = '\0';
  return genome;
}

// Mutate a genome
void mutate_genome(char *genome) {
  for (int i = 0; i < genome_length; i++) {
    if (rand() / (RAND_MAX + 1.0) < mutation_rate) {
      genome[i] = generate_nucleotide();
    }
  }
}

// Sequence a genome
char *sequence_genome(char *genome) {
  char *sequence = malloc(genome_length + 1);
  for (int i = 0; i < genome_length; i++) {
    if (rand() / (RAND_MAX + 1.0) < sequencing_error_rate) {
      sequence[i] = generate_nucleotide();
    } else {
      sequence[i] = genome[i];
    }
  }
  sequence[genome_length] = '\0';
  return sequence;
}

// Print a genome
void print_genome(char *genome) {
  printf("%s\n", genome);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a genome
  char *genome = generate_genome();

  // Mutate the genome
  mutate_genome(genome);

  // Sequence the genome
  char *sequence = sequence_genome(genome);

  // Print the original genome
  printf("Original genome:\n");
  print_genome(genome);

  // Print the mutated genome
  printf("Mutated genome:\n");
  print_genome(sequence);

  // Free the allocated memory
  free(genome);
  free(sequence);

  return 0;
}