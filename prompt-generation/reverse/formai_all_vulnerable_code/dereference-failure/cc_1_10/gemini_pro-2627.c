//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C Genome Sequencing Simulator

// Constants
#define NUM_BASES 4
#define BASE_A 'A'
#define BASE_C 'C'
#define BASE_G 'G'
#define BASE_T 'T'

// Function prototypes
void generateSequence(char *sequence, int length);
void printSequence(char *sequence, int length);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the length of the sequence from the user
  int length;
  printf("Enter the length of the sequence: ");
  scanf("%d", &length);

  // Allocate memory for the sequence
  char *sequence = (char *)malloc(length + 1);

  // Generate the sequence
  generateSequence(sequence, length);

  // Print the sequence
  printSequence(sequence, length);

  // Free the memory allocated for the sequence
  free(sequence);

  return 0;
}

// Function to generate a random sequence of bases
void generateSequence(char *sequence, int length) {
  for (int i = 0; i < length; i++) {
    // Generate a random number between 0 and 3
    int randomNumber = rand() % NUM_BASES;

    // Convert the random number to a base
    switch (randomNumber) {
    case 0:
      sequence[i] = BASE_A;
      break;
    case 1:
      sequence[i] = BASE_C;
      break;
    case 2:
      sequence[i] = BASE_G;
      break;
    case 3:
      sequence[i] = BASE_T;
      break;
    }
  }

  // Terminate the string with a null character
  sequence[length] = '\0';
}

// Function to print a sequence of bases
void printSequence(char *sequence, int length) {
  for (int i = 0; i < length; i++) {
    printf("%c", sequence[i]);
  }

  printf("\n");
}