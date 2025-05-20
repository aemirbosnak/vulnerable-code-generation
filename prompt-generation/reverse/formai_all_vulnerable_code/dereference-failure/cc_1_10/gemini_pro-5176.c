//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// generate random sequence
char *generate_seq(int len) {
  srand(time(NULL));
  char *seq = malloc(sizeof(char) * (len + 1));
  for (int i = 0; i < len; i++) {
    seq[i] = "ACGT"[rand() % 4];
  }
  seq[len] = '\0';
  return seq;
}

// print sequence
void print_seq(char *seq) {
  int len = strlen(seq);
  for (int i = 0; i < len; i++) {
    printf("%c", seq[i]);
  }
  printf("\n");
}

// simulate sequencing errors
char *simulate_errors(char *seq, double error_rate) {
  int len = strlen(seq);
  char *new_seq = malloc(sizeof(char) * (len + 1));
  for (int i = 0; i < len; i++) {
    if (rand() / (double)RAND_MAX < error_rate) {
      // introduce error
      new_seq[i] = "ACGT"[rand() % 4];
    } else {
      // no error
      new_seq[i] = seq[i];
    }
  }
  new_seq[len] = '\0';
  return new_seq;
}

int main() {
  // generate sequence
  int len = 1000;
  char *seq = generate_seq(len);

  // print original sequence
  printf("Original sequence:\n");
  print_seq(seq);

  // simulate sequencing errors
  double error_rate = 0.01;
  char *new_seq = simulate_errors(seq, error_rate);

  // print error-prone sequence
  printf("Error-prone sequence (error rate = %.2f%%):\n", error_rate * 100);
  print_seq(new_seq);

  // free memory
  free(seq);
  free(new_seq);
  return 0;
}