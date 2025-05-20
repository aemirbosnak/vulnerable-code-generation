//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size
#define TABLE_SIZE 5

// Define the number of players
#define NUM_PLAYERS 4

// Define the number of dice
#define NUM_DICE 2

// Define the winning score
#define WINNING_SCORE 20

// Define the player types
typedef enum {
  HUMAN,
  COMPUTER
} player_type;

// Define the game state
typedef enum {
  PLAYING,
  FINISHED
} game_state;

// Define the player struct
typedef struct {
  player_type type;
  int score;
  int position;
} player;

// Define the table struct
typedef struct {
  int spaces[TABLE_SIZE];
} table;

// Create a new table
table* create_table() {
  table* t = malloc(sizeof(table));
  for (int i = 0; i < TABLE_SIZE; i++) {
    t->spaces[i] = 0;
  }
  return t;
}

// Free the table
void free_table(table* t) {
  free(t);
}

// Create a new player
player* create_player(player_type type) {
  player* p = malloc(sizeof(player));
  p->type = type;
  p->score = 0;
  p->position = 0;
  return p;
}

// Free the player
void free_player(player* p) {
  free(p);
}

// Roll the dice
int roll_dice() {
  return rand() % 6 + 1;
}

// Move the player
void move_player(player* p, int spaces) {
  p->position = (p->position + spaces) % TABLE_SIZE;
}

// Add to the player's score
void add_to_score(player* p, int points) {
  p->score += points;
}

// Check if the player has won
int has_won(player* p) {
  return p->score >= WINNING_SCORE;
}

// Get the next player
player* get_next_player(player* players[], int current_player) {
  return players[(current_player + 1) % NUM_PLAYERS];
}

// Play the game
void play_game() {
  // Create the table
  table* t = create_table();

  // Create the players
  player* players[NUM_PLAYERS];
  for (int i = 0; i < NUM_PLAYERS; i++) {
    players[i] = create_player(i % 2 == 0 ? HUMAN : COMPUTER);
  }

  // Set the current player
  int current_player = 0;

  // Set the game state
  game_state state = PLAYING;

  // While the game is playing
  while (state == PLAYING) {
    // Get the current player
    player* p = players[current_player];

    // If the player is human
    if (p->type == HUMAN) {
      // Get the player's input
      int input;
      printf("It is your turn. Press enter to roll the dice: ");
      scanf("%d", &input);

      // Roll the dice
      int dice_roll = roll_dice();

      // Move the player
      move_player(p, dice_roll);

      // Add to the player's score
      add_to_score(p, t->spaces[p->position]);

      // Check if the player has won
      if (has_won(p)) {
        state = FINISHED;
      }
    }

    // If the player is a computer
    else {
      // Roll the dice
      int dice_roll = roll_dice();

      // Move the player
      move_player(p, dice_roll);

      // Add to the player's score
      add_to_score(p, t->spaces[p->position]);

      // Check if the player has won
      if (has_won(p)) {
        state = FINISHED;
      }
    }

    // Get the next player
    current_player = get_next_player(players, current_player);
  }

  // Print the winner
  printf("The winner is player %d!\n", current_player + 1);

  // Free the table
  free_table(t);

  // Free the players
  for (int i = 0; i < NUM_PLAYERS; i++) {
    free_player(players[i]);
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}