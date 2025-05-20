//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide sequence
char generate_nucleotide() {
  return nucleotides[rand() % 4];
}

// Function to generate a random DNA sequence of a given length
char *generate_dna_sequence(int length) {
  char *sequence = (char *)malloc(length + 1);
  for (int i = 0; i < length; i++) {
    sequence[i] = generate_nucleotide();
  }
  sequence[length] = '\0';
  return sequence;
}

// Function to simulate the sequencing of a DNA sequence
char **simulate_sequencing(char *sequence, int read_length) {
  int num_reads = (strlen(sequence) - read_length) / read_length + 1;
  char **reads = (char **)malloc(num_reads * sizeof(char *));
  for (int i = 0; i < num_reads; i++) {
    reads[i] = (char *)malloc(read_length + 1);
    for (int j = 0; j < read_length; j++) {
      int start_index = i * read_length;
      reads[i][j] = sequence[start_index + j];
    }
    reads[i][read_length] = '\0';
  }
  return reads;
}

// Function to print a DNA sequence
void print_dna_sequence(char *sequence) {
  printf("%s\n", sequence);
}

// Function to print a list of DNA reads
void print_dna_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence of length 1000
  char *sequence = generate_dna_sequence(1000);

  // Print the original DNA sequence
  printf("Original DNA sequence:\n");
  print_dna_sequence(sequence);

  // Simulate the sequencing of the DNA sequence with a read length of 100
  char **reads = simulate_sequencing(sequence, 100);

  // Print the simulated DNA reads
  printf("\nSimulated DNA reads:\n");
  print_dna_reads(reads, (strlen(sequence) - 100) / 100 + 1);

  // Free the allocated memory
  free(sequence);
  for (int i = 0; i < (strlen(sequence) - 100) / 100 + 1; i++) {
    free(reads[i]);
  }
  free(reads);

  return 0;
}