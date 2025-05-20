//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSPIRACY_THEORIES 10

typedef struct ConspiracyTheory {
  char *title;
  char *description;
  int suspicious_characters_count;
  char **suspicious_characters;
  int evidence_count;
  char **evidence;
} ConspiracyTheory;

ConspiracyTheory **generate_conspiracy_theory() {
  ConspiracyTheory **theory = malloc(sizeof(ConspiracyTheory *) * MAX_CONSPIRACY_THEORIES);
  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    theory[i] = malloc(sizeof(ConspiracyTheory));
    theory[i]->title = malloc(100);
    theory[i]->description = malloc(500);
    theory[i]->suspicious_characters_count = rand() % 10;
    theory[i]->suspicious_characters = malloc(sizeof(char *) * theory[i]->suspicious_characters_count);
    for (int j = 0; j < theory[i]->suspicious_characters_count; j++) {
      theory[i]->suspicious_characters[j] = malloc(20);
    }
    theory[i]->evidence_count = rand() % 5;
    theory[i]->evidence = malloc(sizeof(char *) * theory[i]->evidence_count);
    for (int j = 0; j < theory[i]->evidence_count; j++) {
      theory[i]->evidence[j] = malloc(20);
    }
  }
  return theory;
}

int main() {
  ConspiracyTheory **theories = generate_conspiracy_theory();
  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    printf("Title: %s\n", theories[i]->title);
    printf("Description: %s\n", theories[i]->description);
    printf("Suspicious Characters: ");
    for (int j = 0; j < theories[i]->suspicious_characters_count; j++) {
      printf("%s ", theories[i]->suspicious_characters[j]);
    }
    printf("\n");
    printf("Evidence: ");
    for (int j = 0; j < theories[i]->evidence_count; j++) {
      printf("%s ", theories[i]->evidence[j]);
    }
    printf("\n");
  }
  return 0;
}