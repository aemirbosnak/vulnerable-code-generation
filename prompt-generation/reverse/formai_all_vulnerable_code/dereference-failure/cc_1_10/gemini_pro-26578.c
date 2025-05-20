//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_READ_LENGTH 1000

typedef struct {
  char *seq;
  int length;
} Sequence;

typedef struct {
  char *read;
  int length;
  int start;
  int end;
} Read;

void generate_sequence(Sequence *seq) {
  int i;

  seq->seq = malloc(MAX_SEQ_LENGTH);
  seq->length = 0;

  for (i = 0; i < MAX_SEQ_LENGTH; i++) {
    int r = rand() % 4;

    switch (r) {
      case 0:
        seq->seq[i] = 'A';
        break;
      case 1:
        seq->seq[i] = 'C';
        break;
      case 2:
        seq->seq[i] = 'G';
        break;
      case 3:
        seq->seq[i] = 'T';
        break;
    }

    seq->length++;
  }
}

void generate_read(Sequence *seq, Read *read) {
  int i;

  read->read = malloc(MAX_READ_LENGTH);
  read->length = 0;
  read->start = rand() % (seq->length - MAX_READ_LENGTH);
  read->end = read->start + MAX_READ_LENGTH;

  for (i = read->start; i < read->end; i++) {
    read->read[i - read->start] = seq->seq[i];
    read->length++;
  }
}

void print_sequence(Sequence *seq) {
  int i;

  for (i = 0; i < seq->length; i++) {
    printf("%c", seq->seq[i]);
  }

  printf("\n");
}

void print_read(Read *read) {
  int i;

  for (i = 0; i < read->length; i++) {
    printf("%c", read->read[i]);
  }

  printf("\n");
}

int main() {
  srand(time(NULL));

  Sequence seq;
  Read read;

  generate_sequence(&seq);
  generate_read(&seq, &read);

  print_sequence(&seq);
  print_read(&read);

  return 0;
}