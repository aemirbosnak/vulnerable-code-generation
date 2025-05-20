//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the conspiracy theory categories
#define NUM_CATEGORIES 5
char *categories[] = {"Government", "Aliens", "Celebrities", "Technology", "Other"};

// Define the conspiracy theory types
#define NUM_TYPES 10
char *types[] = {"Cover-up", "Hoax", "Control", "Fraud", "Mind control", "Surveillance", "Manipulation", "Propaganda", "Illuminati", "New World Order"};

// Define the players
#define NUM_PLAYERS 4
char *players[] = {"Alice", "Bob", "Carol", "Dave"};

// Define the game state
typedef struct {
  int player_turn;
  int category;
  int type;
  char *theory;
} game_state;

// Initialize the game state
game_state state;

// Get a random number between 0 and max
int get_random(int max) {
  return rand() % max;
}

// Get a random category
int get_random_category() {
  return get_random(NUM_CATEGORIES);
}

// Get a random type
int get_random_type() {
  return get_random(NUM_TYPES);
}

// Get a random player
int get_random_player() {
  return get_random(NUM_PLAYERS);
}

// Generate a random conspiracy theory
char *generate_conspiracy_theory() {
  int category = get_random_category();
  int type = get_random_type();
  char *theory = malloc(100);
  sprintf(theory, "%s %s %s", types[type], categories[category], players[get_random_player()]);
  return theory;
}

// Print the game state
void print_game_state() {
  printf("Player turn: %s\n", players[state.player_turn]);
  printf("Category: %s\n", categories[state.category]);
  printf("Type: %s\n", types[state.type]);
  printf("Theory: %s\n", state.theory);
}

// Play the game
void play_game() {
  // Initialize the game state
  state.player_turn = get_random_player();
  state.category = get_random_category();
  state.type = get_random_type();
  state.theory = generate_conspiracy_theory();

  // Print the initial game state
  print_game_state();

  // Loop until the game is over
  while (1) {
    // Get the player's input
    char input[100];
    printf("Enter your guess: ");
    scanf("%s", input);

    // Check if the player's guess is correct
    if (strcmp(input, state.theory) == 0) {
      // The player guessed correctly, so they win the game
      printf("Congratulations, %s! You win the game!\n", players[state.player_turn]);
      break;
    } else {
      // The player guessed incorrectly, so they lose the game
      printf("Sorry, %s, that is incorrect. You lose the game.\n", players[state.player_turn]);
      break;
    }

    // Advance to the next player's turn
    state.player_turn = (state.player_turn + 1) % NUM_PLAYERS;

    // Generate a new conspiracy theory
    state.theory = generate_conspiracy_theory();

    // Print the updated game state
    print_game_state();
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Play the game
  play_game();

  return 0;
}