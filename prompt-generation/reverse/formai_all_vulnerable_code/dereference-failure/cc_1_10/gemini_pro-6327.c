//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players and expenses
#define MAX_PLAYERS 4
#define MAX_EXPENSES 10

// Define the player struct
typedef struct {
  char name[20];
  double balance;
  double expenses[MAX_EXPENSES];
  int num_expenses;
} player_t;

// Define the game struct
typedef struct {
  player_t players[MAX_PLAYERS];
  int num_players;
  double total_expenses;
} game_t;

// Create a new game
game_t* new_game() {
  game_t* game = malloc(sizeof(game_t));
  game->num_players = 0;
  game->total_expenses = 0.0;
  return game;
}

// Add a player to the game
void add_player(game_t* game, char* name, double balance) {
  if (game->num_players >= MAX_PLAYERS) {
    printf("Error: Maximum number of players reached.\n");
    return;
  }

  player_t* player = &game->players[game->num_players++];
  strcpy(player->name, name);
  player->balance = balance;
  player->num_expenses = 0;
}

// Add an expense to a player
void add_expense(game_t* game, char* player_name, double amount) {
  player_t* player = NULL;

  // Find the player by name
  for (int i = 0; i < game->num_players; i++) {
    if (strcmp(game->players[i].name, player_name) == 0) {
      player = &game->players[i];
      break;
    }
  }

  // Check if the player was found
  if (player == NULL) {
    printf("Error: Player not found.\n");
    return;
  }

  // Add the expense to the player's list of expenses
  if (player->num_expenses >= MAX_EXPENSES) {
    printf("Error: Maximum number of expenses reached.\n");
    return;
  }

  player->expenses[player->num_expenses++] = amount;

  // Update the game's total expenses
  game->total_expenses += amount;
}

// Calculate the average expenses of all players
double average_expenses(game_t* game) {
  return game->total_expenses / game->num_players;
}

// Print the game summary
void print_summary(game_t* game) {
  printf("Game Summary:\n");
  for (int i = 0; i < game->num_players; i++) {
    player_t* player = &game->players[i];
    printf("  %s:\n", player->name);
    printf("    Balance: %.2f\n", player->balance);
    printf("    Expenses:\n");
    for (int j = 0; j < player->num_expenses; j++) {
      printf("      - %.2f\n", player->expenses[j]);
    }
    printf("\n");
  }

  printf("Total Expenses: %.2f\n", game->total_expenses);
  printf("Average Expenses: %.2f\n", average_expenses(game));
}

// Free the game memory
void free_game(game_t* game) {
  free(game);
}

// Main function
int main() {
  // Create a new game
  game_t* game = new_game();

  // Add some players to the game
  add_player(game, "Alice", 100.0);
  add_player(game, "Bob", 200.0);
  add_player(game, "Carol", 300.0);

  // Add some expenses to the players
  add_expense(game, "Alice", 20.0);
  add_expense(game, "Alice", 30.0);
  add_expense(game, "Bob", 40.0);
  add_expense(game, "Bob", 50.0);
  add_expense(game, "Carol", 60.0);
  add_expense(game, "Carol", 70.0);

  // Print the game summary
  print_summary(game);

  // Free the game memory
  free_game(game);

  return 0;
}