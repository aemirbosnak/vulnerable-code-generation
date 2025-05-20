//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the random number generator
void initialize_random() {
  srand(time(NULL));
}

// Roll a dice with a given number of sides
int roll_dice(int sides) {
  return rand() % sides + 1;
}

// Print a dice roll result
void print_dice_roll(int result) {
  printf("The dice roll result is: %d\n", result);
}

// Play a dice rolling game with the user
void play_dice_rolling_game() {
  // Initialize the random number generator
  initialize_random();

  // Get the number of sides of the dice from the user
  int sides;
  printf("Enter the number of sides of the dice: ");
  scanf("%d", &sides);

  // Roll the dice and print the result
  int result = roll_dice(sides);
  print_dice_roll(result);

  // Ask the user if they want to play again
  char again;
  printf("Do you want to play again? (y/n) ");
  scanf(" %c", &again);

  // Play again if the user wants to
  if (again == 'y') {
    play_dice_rolling_game();
  }
}

int main() {
  // Play the dice rolling game
  play_dice_rolling_game();

  return 0;
}