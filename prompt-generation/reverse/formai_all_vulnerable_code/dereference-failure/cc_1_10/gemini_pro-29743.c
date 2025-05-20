//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Watson's DNA sequencing machine
char *sequence(char *dna) {
  int len = strlen(dna);
  char *result = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    switch (dna[i]) {
    case 'A':
      result[i] = 'T';
      break;
    case 'T':
      result[i] = 'A';
      break;
    case 'C':
      result[i] = 'G';
      break;
    case 'G':
      result[i] = 'C';
      break;
    default:
      result[i] = dna[i];
      break;
    }
  }
  result[len] = '\0';
  return result;
}

// Holmes' deductive reasoning engine
char *deduce(char *dna1, char *dna2) {
  int len = strlen(dna1);
  char *result = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    if (dna1[i] == dna2[i]) {
      result[i] = dna1[i];
    } else {
      result[i] = 'N';
    }
  }
  result[len] = '\0';
  return result;
}

// The Baker Street Irregulars' data analysis
int main() {
  char *dna1 = "ACTGATCGATTACGTATCGATCGATCG";
  char *dna2 = "ACTGATCGATTACTATCGATCGATCG";

  char *sequenced1 = sequence(dna1);
  char *sequenced2 = sequence(dna2);

  char *deduced = deduce(sequenced1, sequenced2);

  printf("Watson's sequencing: %s\n", sequenced1);
  printf("Holmes' deduction: %s\n", deduced);

  return 0;
}