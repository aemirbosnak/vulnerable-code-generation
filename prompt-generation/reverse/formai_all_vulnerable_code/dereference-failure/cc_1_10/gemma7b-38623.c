//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CONSPIRACY_THEORIES 5

typedef struct ConspiracyTheory {
  char* title;
  char** evidence;
  int num_evidence;
} ConspiracyTheory;

ConspiracyTheory* generateConspiracyTheory(int index) {
  ConspiracyTheory* theory = malloc(sizeof(ConspiracyTheory));

  theory->title = malloc(20 * index);
  sprintf(theory->title, "Conspiracy Theory %d", index);

  theory->evidence = malloc(10 * index * sizeof(char*));
  theory->num_evidence = index;

  for (int i = 0; i < theory->num_evidence; i++) {
    theory->evidence[i] = malloc(20 * index);
  }

  return theory;
}

void printConspiracyTheory(ConspiracyTheory* theory) {
  printf("**%s:**\n", theory->title);

  for (int i = 0; i < theory->num_evidence; i++) {
    printf("- %s\n", theory->evidence[i]);
  }
}

int main() {
  time_t t = time(NULL);
  srand(t);

  ConspiracyTheory** theories = malloc(NUM_CONSPIRACY_THEORIES * sizeof(ConspiracyTheory*));

  for (int i = 0; i < NUM_CONSPIRACY_THEORIES; i++) {
    theories[i] = generateConspiracyTheory(i + 1);
  }

  for (int i = 0; i < NUM_CONSPIRACY_THEORIES; i++) {
    printConspiracyTheory(theories[i]);
  }

  return 0;
}