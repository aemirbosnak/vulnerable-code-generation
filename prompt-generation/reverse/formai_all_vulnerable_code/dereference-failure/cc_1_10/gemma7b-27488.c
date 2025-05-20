//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

  // Seed the random number generator
  srand(time(NULL));

  // Create an array of suspects
  char **suspects = malloc(10 * sizeof(char *));
  for (int i = 0; i < 10; i++) {
    suspects[i] = malloc(20 * sizeof(char));
  }

  // Fill the suspects with random names
  for (int i = 0; i < 10; i++) {
    sprintf(suspects[i], "Suspect %d", i + 1);
  }

  // Create a list of possible motives
  char **motives = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    motives[i] = malloc(20 * sizeof(char));
  }
  motives[0] = "Power";
  motives[1] = "Wealth";
  motives[2] = "Revenge";
  motives[3] = "Love";
  motives[4] = "Fear";

  // Randomly select a motive
  int motive_index = rand() % 5;

  // Create a plot outline
  char **plot_outline = malloc(100 * sizeof(char));
  plot_outline[0] = 'A';
  plot_outline[1] = 'B';
  plot_outline[2] = 'C';
  plot_outline[3] = 'D';
  plot_outline[4] = 'E';

  // Randomly select a plot point
  int plot_point_index = rand() % 4;

  // Write the conspiracy theory
  printf("The conspiracy unfolds as follows:\n");

  // Print the suspects
  for (int i = 0; i < 10; i++) {
    printf("%s, ", suspects[i]);
  }

  // Print the motive
  printf("had a motive of %s.\n", motives[motive_index]);

  // Print the plot outline
  printf("The plot outline is as follows:\n");

  for (int i = 0; i < plot_point_index + 1; i++) {
    printf("%c ", plot_outline[i]);
  }

  printf("\nThe truth is out...\n");

  return 0;
}