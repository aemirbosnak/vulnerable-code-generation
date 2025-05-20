//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the dice
#define DICE_SIZE 6

// Function to roll a dice
int roll_dice() {
  // Get a random number between 1 and 6
  int number = rand() % DICE_SIZE + 1;

  // Return the random number
  return number;
}

// Function to play a game of dice
void play_game() {
  // Get the number of players
  int num_players;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  // Create an array to store the scores of the players
  int scores[num_players];

  // Initialize the scores of the players to 0
  for (int i = 0; i < num_players; i++) {
    scores[i] = 0;
  }

  // Play the game until one player reaches a score of 100
  while (1) {
    // Get the current player
    int current_player = 0;

    // Roll the dice for the current player
    int roll = roll_dice();

    // Add the roll to the score of the current player
    scores[current_player] += roll;

    // Check if the current player has reached a score of 100
    if (scores[current_player] >= 100) {
      // The current player has won the game
      printf("Player %d has won the game!\n", current_player + 1);

      // Break out of the game loop
      break;
    }

    // Print the scores of the players
    printf("Scores:\n");
    for (int i = 0; i < num_players; i++) {
      printf("Player %d: %d\n", i + 1, scores[i]);
    }

    // Move to the next player
    current_player++;
    if (current_player >= num_players) {
      current_player = 0;
    }
  }
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}