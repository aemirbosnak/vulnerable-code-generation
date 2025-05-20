//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Seed the random number generator.
  srand(time(NULL));

  // Create a list of suspects.
  char **suspects = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    suspects[i] = malloc(20 * sizeof(char));
  }

  // Populate the suspects' names.
  suspects[0] = "Mr. Jones";
  suspects[1] = "Ms. Smith";
  suspects[2] = "Mr. Brown";
  suspects[3] = "Ms. Johnson";
  suspects[4] = "Mr. White";
  suspects[5] = "Ms. Brown";
  suspects[6] = "Mr. Davis";
  suspects[7] = "Ms. Green";
  suspects[8] = "Mr. Lee";
  suspects[9] = "Ms. Taylor";

  // Create a list of potential motives.
  char **motivations = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    motivations[i] = malloc(20 * sizeof(char));
  }

  // Populate the motivations.
  motivations[0] = "Money";
  motivations[1] = "Power";
  motivations[2] = "Revenge";
  motivations[3] = "Love";
  motivations[4] = "Fear";

  // Select a random suspect and motive.
  int suspectIndex = rand() % 10;
  int motivationIndex = rand() % 5;

  // Print the suspect and motive.
  printf("Suspect: %s\n", suspects[suspectIndex]);
  printf("Motivation: %s\n", motivations[motivationIndex]);

  // Free the memory allocated for the suspects and motivations.
  for (int i = 0; i < 10; i++) {
    free(suspects[i]);
  }
  free(suspects);

  for (int i = 0; i < 5; i++) {
    free(motivations[i]);
  }
  free(motivations);

  return 0;
}