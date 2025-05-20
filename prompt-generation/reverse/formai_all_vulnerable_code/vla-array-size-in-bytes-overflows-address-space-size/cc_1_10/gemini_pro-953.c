//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of sides for the dice
#define NUM_SIDES 6

// Function to roll the dice
int roll_dice(void) {
  // Get a random number between 1 and NUM_SIDES
  int num = rand() % NUM_SIDES + 1;

  // Return the random number
  return num;
}

// Function to play the game
void play_game(void) {
  // Get the number of players
  int num_players;
  printf("How many players are playing? ");
  scanf("%d", &num_players);

  // Create an array to store the scores for each player
  int scores[num_players];

  // Roll the dice for each player
  for (int i = 0; i < num_players; i++) {
    scores[i] = roll_dice();
  }

  // Find the highest score
  int highest_score = scores[0];
  for (int i = 1; i < num_players; i++) {
    if (scores[i] > highest_score) {
      highest_score = scores[i];
    }
  }

  // Print the results
  printf("The scores are:\n");
  for (int i = 0; i < num_players; i++) {
    printf("Player %d: %d\n", i + 1, scores[i]);
  }

  printf("The highest score is: %d\n", highest_score);
}

// Main function
int main(void) {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}