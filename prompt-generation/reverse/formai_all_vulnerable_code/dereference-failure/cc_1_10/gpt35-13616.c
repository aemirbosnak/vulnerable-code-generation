//FormAI DATASET v1.0 Category: Computer Biology ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random DNA sequences
char *generate_DNA_sequence(int n) {
  srand(time(NULL)); // seed the random number generator
  char *DNA_sequence = malloc((n+1)*sizeof(char)); // allocate memory for the sequence

  for (int i = 0; i < n; i++) {
    int rand_num = rand() % 4; // generates a random number between 0 and 3
    switch(rand_num) {
      case 0:
        DNA_sequence[i] = 'A';
        break;
      case 1:
        DNA_sequence[i] = 'T';
        break;
      case 2:
        DNA_sequence[i] = 'C';
        break;
      case 3:
        DNA_sequence[i] = 'G';
        break;
    }
  }

  DNA_sequence[n] = '\0'; // add null terminator at the end
  return DNA_sequence;
}

int main() {
  int n = 1000; // length of DNA sequence
  char *DNA_sequence = generate_DNA_sequence(n); // generate a random DNA sequence of length n
  int count_A = 0, count_T = 0, count_C = 0, count_G = 0;

  // Count the number of A's, T's, C's and G's in the generated DNA sequence
  for (int i = 0; i < n; i++) {
    if (DNA_sequence[i] == 'A') {
      count_A++;
    }
    else if (DNA_sequence[i] == 'T') {
      count_T++;
    }
    else if (DNA_sequence[i] == 'C') {
      count_C++;
    }
    else if (DNA_sequence[i] == 'G') {
      count_G++;
    }
  }

  // Print the count of each nucleotide
  printf("Generated DNA sequence: %s\n", DNA_sequence);
  printf("Count of A's: %d\n", count_A);
  printf("Count of T's: %d\n", count_T);
  printf("Count of C's: %d\n", count_C);
  printf("Count of G's: %d\n", count_G);

  free(DNA_sequence); // free the allocated memory
  return 0;
}