//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to roll a dice with num_sides sides
int roll_dice(int num_sides) {
  return random_number(1, num_sides);
}

// Function to play a dice rolling game
void play_dice_game(int num_players, int num_rolls) {
  // Initialize the players' scores
  int scores[num_players];
  for (int i = 0; i < num_players; i++) {
    scores[i] = 0;
  }

  // Roll the dice for each player num_rolls times
  for (int i = 0; i < num_rolls; i++) {
    for (int j = 0; j < num_players; j++) {
      // Roll the dice and add the result to the player's score
      int roll = roll_dice(6);
      scores[j] += roll;
    }
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
  printf("The winner is player %d with a score of %d\n", winner + 1, max_score);
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Get the number of players and the number of rolls from the user
  int num_players;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);

  int num_rolls;
  printf("Enter the number of rolls: ");
  scanf("%d", &num_rolls);

  // Play the dice rolling game
  play_dice_game(num_players, num_rolls);

  return 0;
}