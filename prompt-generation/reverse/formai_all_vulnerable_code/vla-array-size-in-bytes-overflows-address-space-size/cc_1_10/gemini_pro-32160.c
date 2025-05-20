//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to roll a die with a given number of sides
int roll_die(int sides) {
  return random_number(1, sides);
}

// Function to play a game of dice
void play_dice_game() {
  // Get the number of players and the number of sides on the die
  int num_players, num_sides;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);
  printf("Enter the number of sides on the die: ");
  scanf("%d", &num_sides);

  // Create an array to store the scores of each player
  int scores[num_players];

  // Initialize the scores of each player to 0
  for (int i = 0; i < num_players; i++) {
    scores[i] = 0;
  }

  // Play the game for a specified number of rounds
  int num_rounds;
  printf("Enter the number of rounds: ");
  scanf("%d", &num_rounds);

  for (int i = 0; i < num_rounds; i++) {
    // Roll the die for each player
    for (int j = 0; j < num_players; j++) {
      scores[j] += roll_die(num_sides);
    }
  }

  // Print the scores of each player
  for (int i = 0; i < num_players; i++) {
    printf("Player %d: %d\n", i + 1, scores[i]);
  }

  // Find the player with the highest score
  int max_score = 0;
  int winner = -1;
  for (int i = 0; i < num_players; i++) {
    if (scores[i] > max_score) {
      max_score = scores[i];
      winner = i;
    }
  }

  // Print the winner
  if (winner != -1) {
    printf("Player %d wins!\n", winner + 1);
  } else {
    printf("Tie!\n");
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Play the game
  play_dice_game();

  return 0;
}