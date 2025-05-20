//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSPIRACY_THEORIES 10

struct ConspiracyTheory {
  char *title;
  char *description;
  int suspiciousCharacters;
  char **suspiciousActivities;
  int likelihood;
};

void generateConspiracyTheory(struct ConspiracyTheory *theory) {
  theory->title = malloc(20);
  snprintf(theory->title, 20, "The %s Conspiracy", rand() % MAX_CONSPIRACY_THEORIES);

  theory->description = malloc(100);
  snprintf(theory->description, 100, "A nefarious %s plot involving...", rand() % MAX_CONSPIRACY_THEORIES);

  theory->suspiciousCharacters = rand() % 5;
  theory->suspiciousActivities = malloc(theory->suspiciousCharacters * sizeof(char *));
  for (int i = 0; i < theory->suspiciousActivities; i++) {
    theory->suspiciousActivities[i] = malloc(20);
    snprintf(theory->suspiciousActivities[i], 20, "Something fishy %s", rand() % MAX_CONSPIRACY_THEORIES);
  }

  theory->likelihood = rand() % 100;
}

int main() {
  struct ConspiracyTheory theories[MAX_CONSPIRACY_THEORIES];
  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    generateConspiracyTheory(&theories[i]);
  }

  for (int i = 0; i < MAX_CONSPIRACY_THEORIES; i++) {
    printf("%s\n", theories[i].title);
    printf("%s\n", theories[i].description);
    printf("Suspicious characters: %d\n", theories[i].suspiciousCharacters);
    printf("Suspicious activities: ");
    for (int j = 0; j < theories[i].suspiciousActivities; j++) {
      printf("%s, ", theories[i].suspiciousActivities[j]);
    }
    printf("\nLikelihood: %d%%\n", theories[i].likelihood);
    printf("\n");
  }

  return 0;
}