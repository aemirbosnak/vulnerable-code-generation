//FormAI DATASET v1.0 Category: Computer Biology ; Style: curious
//Welcome to the Bio-Curious Program!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declare struct for DNA sequence
struct DNA {
  char* sequence;
  int length;
};

//Function to generate random DNA sequence
struct DNA generateDNA(int length) {
  //Allocate memory for DNA sequence
  struct DNA new_dna;
  new_dna.sequence = (char*)malloc(sizeof(char) * length);

  //Generate random nucleotides (A,C,T,G)
  for (int i = 0; i < length; i++) {
    int random_num = rand() % 4;

    if (random_num == 0) {
      new_dna.sequence[i] = 'A';
    }
    else if (random_num == 1) {
      new_dna.sequence[i] = 'C';
    }
    else if (random_num == 2) {
      new_dna.sequence[i] = 'T';
    }
    else {
      new_dna.sequence[i] = 'G';
    }
  }

  //Set length of DNA sequence
  new_dna.length = length;

  return new_dna;
}

//Function to compare two DNA sequences
int compareDNA(struct DNA dna1, struct DNA dna2) {
  //Check if sequences are same length
  if (dna1.length != dna2.length) {
    return 0;
  }

  //Compare each nucleotide in sequence
  for (int i = 0; i < dna1.length; i++) {
    if (dna1.sequence[i] != dna2.sequence[i]) {
      return 0;
    }
  }

  //Sequences are identical
  return 1;
}

int main() {
  //Seed random number generator
  srand(time(NULL));

  //Generate two DNA sequences of length 10
  struct DNA dna1 = generateDNA(10);
  struct DNA dna2 = generateDNA(10);

  //Print out DNA sequences
  printf("DNA sequence 1: ");
  for (int i = 0; i < dna1.length; i++) {
    printf("%c", dna1.sequence[i]);
  }
  printf("\n");

  printf("DNA sequence 2: ");
  for (int i = 0; i < dna2.length; i++) {
    printf("%c", dna2.sequence[i]);
  }
  printf("\n");

  //Compare sequences
  int is_same = compareDNA(dna1, dna2);
  if (is_same) {
    printf("These DNA sequences are identical!\n");
  } else {
    printf("These DNA sequences are not identical.\n");
  }

  //Free memory allocated for DNA sequences
  free(dna1.sequence);
  free(dna2.sequence);

  return 0;
}