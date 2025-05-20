//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides, num_rolls, i, j, k;
  int *rolls;

  // Get input from the user.
  printf("Enter the number of sides on the dice: ");
  scanf("%d", &sides);
  printf("Enter the number of rolls: ");
  scanf("%d", &num_rolls);

  // Allocate memory for the array of rolls.
  rolls = malloc(num_rolls * sizeof(int));

  // Seed the random number generator.
  srand(time(NULL));

  // Roll the dice and store the results in the array.
  for (i = 0; i < num_rolls; i++) {
    rolls[i] = rand() % sides + 1;
  }

  // Print the results of the rolls.
  printf("The rolls are:\n");
  for (i = 0; i < num_rolls; i++) {
    printf("%d ", rolls[i]);
  }
  printf("\n");

  // Calculate the frequency of each roll.
  int *frequencies = malloc(sides * sizeof(int));
  for (i = 0; i < sides; i++) {
    frequencies[i] = 0;
  }
  for (i = 0; i < num_rolls; i++) {
    frequencies[rolls[i] - 1]++;
  }

  // Print the frequency of each roll.
  printf("The frequency of each roll is:\n");
  for (i = 0; i < sides; i++) {
    printf("%d: %d\n", i + 1, frequencies[i]);
  }

  // Calculate the average roll.
  int average_roll = 0;
  for (i = 0; i < num_rolls; i++) {
    average_roll += rolls[i];
  }
  average_roll /= num_rolls;

  // Print the average roll.
  printf("The average roll is: %.2f\n", (float) average_roll);

  // Calculate the standard deviation of the rolls.
  float standard_deviation = 0.0;
  for (i = 0; i < num_rolls; i++) {
    standard_deviation += (rolls[i] - average_roll) * (rolls[i] - average_roll);
  }
  standard_deviation /= num_rolls;
  standard_deviation = sqrt(standard_deviation);

  // Print the standard deviation of the rolls.
  printf("The standard deviation of the rolls is: %.2f\n", standard_deviation);

  // Free the memory allocated for the array of rolls.
  free(rolls);

  // Free the memory allocated for the array of frequencies.
  free(frequencies);

  return 0;
}