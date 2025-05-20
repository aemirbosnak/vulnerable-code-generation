//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Dennis Ritchie
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *seq;
  int len;
} Sequence;

Sequence *new_sequence(char *seq) {
  Sequence *s = malloc(sizeof(Sequence));
  s->seq = strdup(seq);
  s->len = strlen(seq);
  return s;
}

void free_sequence(Sequence *s) {
  free(s->seq);
  free(s);
}

char *generate_random_sequence(int len) {
  char *seq = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    seq[i] = "ACGT"[rand() % 4];
  }
  seq[len] = '\0';
  return seq;
}

int main() {
  srand(time(NULL));

  // Generate a random sequence of length 1000
  Sequence *seq = new_sequence(generate_random_sequence(1000));

  // Print the sequence
  printf("Sequence: %s\n", seq->seq);

  // Reverse complement the sequence
  for (int i = 0; i < seq->len / 2; i++) {
    char tmp = seq->seq[i];
    seq->seq[i] = seq->seq[seq->len - i - 1];
    seq->seq[seq->len - i - 1] = tmp;
  }
  for (int i = 0; i < seq->len; i++) {
    switch (seq->seq[i]) {
      case 'A':
        seq->seq[i] = 'T';
        break;
      case 'T':
        seq->seq[i] = 'A';
        break;
      case 'C':
        seq->seq[i] = 'G';
        break;
      case 'G':
        seq->seq[i] = 'C';
        break;
    }
  }

  // Print the reverse complement
  printf("Reverse complement: %s\n", seq->seq);

  // Free the sequence
  free_sequence(seq);

  return 0;
}