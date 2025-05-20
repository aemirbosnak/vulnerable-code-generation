//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  // Seed the RNG
  srand(time(NULL));

  // Create a list of suspects
  char **suspects = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    suspects[i] = malloc(20 * sizeof(char));
  }

  // Assign random names to each suspect
  for (int i = 0; i < 10; i++) {
    sprintf(suspects[i], "Suspect %d", i + 1);
  }

  // Create a list of potential motives
  char **motives = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    motives[i] = malloc(20 * sizeof(char));
  }

  // Assign random motives to each suspect
  for (int i = 0; i < 10; i++) {
    sprintf(motives[i], "Motive %d", rand() % 5 + 1);
  }

  // Create a list of circumstantial evidence
  char **evidence = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    evidence[i] = malloc(20 * sizeof(char));
  }

  // Assign random evidence to each suspect
  for (int i = 0; i < 10; i++) {
    sprintf(evidence[i], "Evidence %d", rand() % 10 + 1);
  }

  // Print the suspects, their motives, and their evidence
  for (int i = 0; i < 10; i++) {
    printf("%s: %s, %s\n", suspects[i], motives[i], evidence[i]);
  }

  // Free the memory allocated for the suspects, motives, and evidence
  for (int i = 0; i < 10; i++) {
    free(suspects[i]);
    free(motives[i]);
    free(evidence[i]);
  }

  free(suspects);
  free(motives);
  free(evidence);

  return 0;
}