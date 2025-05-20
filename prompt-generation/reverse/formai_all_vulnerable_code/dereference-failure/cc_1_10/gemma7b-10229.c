//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROLLS 1000

int main() {
  int rolls = 0;
  int total = 0;
  int face;
  int number;

  // Allocate memory for the array of rolls
  int *rollHistory = malloc(MAX_ROLLS * sizeof(int));

  // Loop until the user wants to quit
  while (1) {
    // Get the number of rolls
    printf("Enter the number of rolls: ");
    scanf("%d", &number);

    // Roll the dice
    for (rolls = 0; rolls < number; rolls++) {
      face = rand() % 6 + 1;
      rollHistory[rolls] = face;
      total += face;
    }

    // Print the results
    printf("Total: %d\n", total);

    // Print the roll history
    printf("Roll history:\n");
    for (rolls = 0; rolls < number; rolls++) {
      printf("%d ", rollHistory[rolls]);
    }

    // Free the memory
    free(rollHistory);

    // Check if the user wants to quit
    printf("Do you want to quit? (y/n): ");
    char quit;
    scanf("%c", &quit);

    // Break out of the loop if the user wants to quit
    if (quit == 'y') {
      break;
    }
  }

  return 0;
}