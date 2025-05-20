//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a DNA sequence
#define MAX_SEQUENCE_LENGTH 1000

// Define the probability of a mutation
#define MUTATION_PROBABILITY 0.01

// Define the four DNA bases
char bases[] = {'A', 'C', 'G', 'T'};

// Function to generate a random DNA sequence
char *generate_sequence(int length) {
  // Allocate memory for the sequence
  char *sequence = malloc(length + 1);

  // Generate a random sequence of bases
  for (int i = 0; i < length; i++) {
    sequence[i] = bases[rand() % 4];
  }

  // Terminate the sequence with a null character
  sequence[length] = '\0';

  // Return the sequence
  return sequence;
}

// Function to simulate a mutation
char *mutate_sequence(char *sequence) {
  // Allocate memory for the mutated sequence
  char *mutated_sequence = malloc(strlen(sequence) + 1);

  // Copy the original sequence into the mutated sequence
  strcpy(mutated_sequence, sequence);

  // Mutate each base in the sequence with a probability of MUTATION_PROBABILITY
  for (int i = 0; i < strlen(sequence); i++) {
    if (rand() % 100 < MUTATION_PROBABILITY * 100) {
      mutated_sequence[i] = bases[rand() % 4];
    }
  }

  // Return the mutated sequence
  return mutated_sequence;
}

// Function to print a DNA sequence
void print_sequence(char *sequence) {
  // Print the sequence to the console
  printf("%s\n", sequence);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random DNA sequence
  char *sequence = generate_sequence(MAX_SEQUENCE_LENGTH);

  // Print the original sequence
  printf("Original sequence:\n");
  print_sequence(sequence);

  // Simulate a mutation
  char *mutated_sequence = mutate_sequence(sequence);

  // Print the mutated sequence
  printf("Mutated sequence:\n");
  print_sequence(mutated_sequence);

  // Free the memory allocated for the sequences
  free(sequence);
  free(mutated_sequence);

  return 0;
}