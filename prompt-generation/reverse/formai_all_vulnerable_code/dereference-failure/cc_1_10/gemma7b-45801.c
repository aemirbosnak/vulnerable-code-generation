//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define oracle_bone_size 12
#define oracle_bone_threshold 4

typedef struct oracle_bone {
  int number;
  struct oracle_bone *next;
} oracle_bone;

oracle_bone *oracle_bone_init(int size) {
  oracle_bone *head = malloc(sizeof(oracle_bone) * size);
  for (int i = 0; i < size; i++) {
    head[i].number = 0;
    head[i].next = NULL;
  }
  return head;
}

int oracle_bone_rand_fill(oracle_bone *head) {
  for (int i = 0; i < oracle_bone_size; i++) {
    head[i].number = rand() % oracle_bone_threshold;
  }
  return 0;
}

int oracle_bone_interpret(oracle_bone *head) {
  int sum = 0;
  for (int i = 0; i < oracle_bone_size; i++) {
    sum += head[i].number;
  }
  if (sum % 3 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  srand(time(NULL));
  oracle_bone *bones = oracle_bone_init(oracle_bone_size);
  oracle_bone_rand_fill(bones);
  if (oracle_bone_interpret(bones)) {
    printf("The stars align in your favor.\n");
  } else {
    printf("Fortune favors the bold.\n");
  }
  return 0;
}