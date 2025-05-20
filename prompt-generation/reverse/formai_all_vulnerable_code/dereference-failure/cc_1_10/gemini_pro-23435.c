//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 5
#define MAX_ROLL 6

// Function to roll two dice
int roll_dice() {
  int roll1 = rand() % MAX_ROLL + 1;
  int roll2 = rand() % MAX_ROLL + 1;

  return roll1 + roll2;
}

// Function to move the player around the table
void move_player(int *player_position, int roll) {
  *player_position += roll;

  // Wrap around the table if necessary
  if (*player_position >= TABLE_SIZE) {
    *player_position -= TABLE_SIZE;
  }
}

// Function to print the table
void print_table(int *player_positions) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("|");

    for (int j = 0; j < TABLE_SIZE; j++) {
      if (player_positions[j] == i) {
        printf(" X ");
      } else {
        printf("   ");
      }
    }

    printf("|\n");
  }
}

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array to store the player positions
  int player_positions[2];

  // Set the initial player positions
  player_positions[0] = 0;
  player_positions[1] = 0;

  // Play the game until a player reaches the end of the table
  while (player_positions[0] < TABLE_SIZE && player_positions[1] < TABLE_SIZE) {
    // Roll the dice for each player
    int roll1 = roll_dice();
    int roll2 = roll_dice();

    // Move the players around the table
    move_player(&player_positions[0], roll1);
    move_player(&player_positions[1], roll2);

    // Print the table
    print_table(player_positions);

    // Check if either player has reached the end of the table
    if (player_positions[0] == TABLE_SIZE - 1) {
      printf("Player 1 wins!\n");
    } else if (player_positions[1] == TABLE_SIZE - 1) {
      printf("Player 2 wins!\n");
    }
  }

  return 0;
}