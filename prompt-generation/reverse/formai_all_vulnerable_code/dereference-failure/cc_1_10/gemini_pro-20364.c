//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 10000
#define MAX_GENOME_LENGTH 1000000

// Define the four DNA bases
#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'

// Define the quality scores for each base
#define MIN_QUALITY_SCORE 0
#define MAX_QUALITY_SCORE 40

// Define the error rate for each base
#define ERROR_RATE 0.01

// Generate a random DNA sequence
char *generate_random_dna_sequence(int length) {
  char *sequence = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    int random_number = rand() % 4;
    switch (random_number) {
      case 0:
        sequence[i] = A;
        break;
      case 1:
        sequence[i] = C;
        break;
      case 2:
        sequence[i] = G;
        break;
      case 3:
        sequence[i] = T;
        break;
    }
  }
  sequence[length] = '\0';
  return sequence;
}

// Simulate sequencing errors
char *simulate_sequencing_errors(char *sequence, double error_rate) {
  char *sequenced_sequence = malloc(sizeof(char) * (strlen(sequence) + 1));
  strcpy(sequenced_sequence, sequence);
  for (int i = 0; i < strlen(sequence); i++) {
    if (rand() / (RAND_MAX + 1.0) < error_rate) {
      int random_number = rand() % 4;
      switch (random_number) {
        case 0:
          sequenced_sequence[i] = A;
          break;
        case 1:
          sequenced_sequence[i] = C;
          break;
        case 2:
          sequenced_sequence[i] = G;
          break;
        case 3:
          sequenced_sequence[i] = T;
          break;
      }
    }
  }
  sequenced_sequence[strlen(sequence)] = '\0';
  return sequenced_sequence;
}

// Generate a random quality score for a base
int generate_random_quality_score() {
  return rand() % (MAX_QUALITY_SCORE - MIN_QUALITY_SCORE + 1) + MIN_QUALITY_SCORE;
}

// Simulate sequencing reads
char **simulate_sequencing_reads(char *genome, int read_length, int num_reads) {
  char **reads = malloc(sizeof(char *) * num_reads);
  for (int i = 0; i < num_reads; i++) {
    int start_position = rand() % (strlen(genome) - read_length + 1);
    char *read = malloc(sizeof(char) * (read_length + 1));
    strncpy(read, genome + start_position, read_length);
    read[read_length] = '\0';
    reads[i] = read;
  }
  return reads;
}

// Print the sequencing reads
void print_sequencing_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    printf("%s\n", reads[i]);
  }
}

// Free the memory allocated for the sequencing reads
void free_sequencing_reads(char **reads, int num_reads) {
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]);
  }
  free(reads);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Generate a random DNA sequence
  char *genome = generate_random_dna_sequence(MAX_GENOME_LENGTH);

  // Simulate sequencing errors
  char *sequenced_genome = simulate_sequencing_errors(genome, ERROR_RATE);

  // Generate sequencing reads
  char **reads = simulate_sequencing_reads(sequenced_genome, MAX_READ_LENGTH, MAX_NUM_READS);

  // Print the sequencing reads
  print_sequencing_reads(reads, MAX_NUM_READS);

  // Free the memory allocated for the sequencing reads
  free_sequencing_reads(reads, MAX_NUM_READS);

  // Free the memory allocated for the genome
  free(genome);

  // Free the memory allocated for the sequenced genome
  free(sequenced_genome);

  return 0;
}