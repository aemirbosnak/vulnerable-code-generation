//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY 10

typedef struct Conspiracy {
  char **members;
  char ** motives;
  int complexity;
  int target;
} Conspiracy;

Conspiracy **generate_conspiracy(int seed) {
  Conspiracy *conspiracy = malloc(sizeof(Conspiracy));
  conspiracy->members = malloc(MAX_CONSPIRACY * sizeof(char *));
  conspiracy->motives = malloc(MAX_CONSPIRACY * sizeof(char *));
  conspiracy->complexity = rand() % 5;
  conspiracy->target = rand() % 10;

  for (int i = 0; i < MAX_CONSPIRACY; i++) {
    conspiracy->members[i] = malloc(20 * sizeof(char));
    conspiracy->motives[i] = malloc(20 * sizeof(char));
  }

  return conspiracy;
}

int main() {
  srand(time(NULL));

  for (int i = 0; i < 10; i++) {
    Conspiracy *conspiracy = generate_conspiracy(i);

    printf("Conspiracy %d:\n", i);
    printf("  Members:\n");
    for (int j = 0; j < conspiracy->complexity; j++) {
      printf("    %s\n", conspiracy->members[j]);
    }

    printf("  Motives:\n");
    for (int j = 0; j < conspiracy->complexity; j++) {
      printf("    %s\n", conspiracy->motives[j]);
    }

    printf("  Target: %d\n", conspiracy->target);
    printf("\n");
  }

  return 0;
}