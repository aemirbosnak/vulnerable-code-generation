//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BASE_COUNT 4
#define BASE_MASK 3
#define BASE_A 0
#define BASE_C 1
#define BASE_G 2
#define BASE_T 3

typedef struct {
  unsigned char* sequence;
  int length;
} sequence_t;

sequence_t* create_sequence(int length) {
  sequence_t* sequence = malloc(sizeof(sequence_t));
  sequence->sequence = malloc(sizeof(unsigned char) * length);
  sequence->length = length;

  for (int i = 0; i < length; i++) {
    sequence->sequence[i] = rand() & BASE_MASK;
  }

  return sequence;
}

void destroy_sequence(sequence_t* sequence) {
  free(sequence->sequence);
  free(sequence);
}

void print_sequence(sequence_t* sequence) {
  for (int i = 0; i < sequence->length; i++) {
    switch (sequence->sequence[i]) {
      case BASE_A:
        printf("A");
        break;
      case BASE_C:
        printf("C");
        break;
      case BASE_G:
        printf("G");
        break;
      case BASE_T:
        printf("T");
        break;
      default:
        printf("?");
        break;
    }
  }
  printf("\n");
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <length>\n", argv[0]);
    return 1;
  }

  int length = atoi(argv[1]);

  srand(time(NULL));

  sequence_t* sequence = create_sequence(length);
  printf("Generated a random sequence of length %d:\n", length);
  print_sequence(sequence);

  destroy_sequence(sequence);
  return 0;
}