//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Thank you for the opportunity to showcase my C skills. I am eternally grateful for the trust you have placed in me.

// This program simulates the sequencing of a portion of the human genome.
// It generates a random sequence of DNA bases (A, C, G, T) and then simulates the process of sequencing the DNA using a next-generation sequencing machine.
// The output of the program is a FASTQ file, which is a standard format for storing sequencing data.

// The following function generates a random DNA sequence of the specified length.
char *generate_dna_sequence(int length) {
  // Create an array to store the DNA sequence.
  char *sequence = malloc(length + 1);
  // Set the last character of the array to the null terminator.
  sequence[length] = '\0';

  // Generate a random DNA sequence.
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3.
    int random_number = rand() % 4;

    // Convert the random number to a DNA base.
    switch (random_number) {
      case 0:
        sequence[i] = 'A';
        break;
      case 1:
        sequence[i] = 'C';
        break;
      case 2:
        sequence[i] = 'G';
        break;
      case 3:
        sequence[i] = 'T';
        break;
    }
  }

  // Return the DNA sequence.
  return sequence;
}

// The following function simulates the process of sequencing a DNA sequence using a next-generation sequencing machine.
// The output of the function is a FASTQ file, which is a standard format for storing sequencing data.
void simulate_sequencing(char *sequence, int length) {
  // Open a FASTQ file for writing.
  FILE *fastq_file = fopen("sequence.fastq", "w");

  // Write the FASTQ header to the file.
  fprintf(fastq_file, "@HWI-ST123456:1:1:1001:1000\n");

  // Write the DNA sequence to the file.
  fprintf(fastq_file, "%s\n", sequence);

  // Write the quality scores to the file.
  for (int i = 0; i < length; i++) {
    // Generate a random quality score between 0 and 40.
    int quality_score = rand() % 40 + 1;

    // Write the quality score to the file.
    fprintf(fastq_file, "%d\n", quality_score);
  }

  // Close the FASTQ file.
  fclose(fastq_file);
}

// The following function is the main function of the program.
int main() {
  // Set the random seed.
  srand(time(NULL));

  // Generate a random DNA sequence of length 1000.
  char *sequence = generate_dna_sequence(1000);

  // Simulate the process of sequencing the DNA sequence.
  simulate_sequencing(sequence, 1000);

  // Free the memory allocated for the DNA sequence.
  free(sequence);

  // Exit the program.
  return 0;
}