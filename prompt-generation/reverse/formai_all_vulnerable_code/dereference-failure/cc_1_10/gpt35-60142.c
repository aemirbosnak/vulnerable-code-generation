//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* define the genome sequencing matrix */
char seq_matrix[4][4] = {{'A', 'C', 'G', 'T'},
                         {'C', 'A', 'T', 'G'},
                         {'G', 'T', 'A', 'C'},
                         {'T', 'G', 'C', 'A'}};

/* function to generate a random number between 0 and max */ 
int rand_range(int max) {
  return rand() % max;
}

/* function to generate a DNA sequence of length n */
char* generate_sequence(int n) {
  /* allocate memory for the sequence */
  char* sequence = malloc(sizeof(char) * (n + 1));
  sequence[n] = '\0'; // null terminate the string

  /* generate the sequence by randomly selecting a character from the sequence matrix */
  for (int i = 0; i < n; i++) {
    int row = rand_range(4);
    int col = rand_range(4);
    sequence[i] = seq_matrix[row][col];
  }

  return sequence;
}

/* function to simulate genome sequencing using a DNA sequence */
char* simulate_sequencing(char* sequence, int n_read, int overlap) {
  int n_seq = strlen(sequence);
  int n_reads = n_seq / (n_read - overlap);

  /* allocate memory for the reads */
  char* reads = malloc(sizeof(char) * (n_reads * (n_read + 1)));
  int index = 0;

  /* generate the reads by leaving an overlap of length overlap between each read */
  for (int i = 0; i < n_seq; i += n_read - overlap) {
    strncpy(reads + index, sequence + i, n_read);
    index += n_read;
  }

  return reads;
}

int main() {
  srand(time(NULL)); // seed the random number generator

  /* generate a random DNA sequence */
  char* sequence = generate_sequence(1000);
  
  /* simulate genome sequencing using the sequence */
  char* reads = simulate_sequencing(sequence, 100, 10);

  /* print out the original sequence and the reads */
  printf("Original Sequence:\n%s\n\n", sequence);
  printf("Reads:\n%s\n", reads);

  /* free memory allocated for the sequence and reads */
  free(sequence);
  free(reads);

  return 0;
}