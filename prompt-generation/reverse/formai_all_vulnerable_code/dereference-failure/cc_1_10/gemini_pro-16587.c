//GEMINI-pro DATASET v1.0 Category: Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_NAME_LENGTH 20
#define MAX_BOARD_SIZE 10

// Player struct
typedef struct {
  char name[MAX_NAME_LENGTH];
  int score;
} Player;

// Game board struct
typedef struct {
  int size;
  char **cells;
} Board;

// Game state struct
typedef struct {
  Board board;
  Player players[MAX_PLAYERS];
  int num_players;
  int current_player;
} GameState;

// Function to create a new game state
GameState *new_game_state() {
  GameState *state = malloc(sizeof(GameState));
  state->board.size = MAX_BOARD_SIZE;
  state->board.cells = malloc(state->board.size * sizeof(char *));
  for (int i = 0; i < state->board.size; i++) {
    state->board.cells[i] = malloc(state->board.size * sizeof(char));
    for (int j = 0; j < state->board.size; j++) {
      state->board.cells[i][j] = ' ';
    }
  }
  state->num_players = 0;
  return state;
}

// Function to free a game state
void free_game_state(GameState *state) {
  for (int i = 0; i < state->board.size; i++) {
    free(state->board.cells[i]);
  }
  free(state->board.cells);
  free(state);
}

// Function to add a player to the game state
void add_player(GameState *state, char *name) {
  if (state->num_players >= MAX_PLAYERS) {
    printf("Error: Maximum number of players reached.\n");
    return;
  }
  strcpy(state->players[state->num_players].name, name);
  state->players[state->num_players].score = 0;
  state->num_players++;
}

// Function to print the game board
void print_board(GameState *state) {
  printf("\n");
  for (int i = 0; i < state->board.size; i++) {
    for (int j = 0; j < state->board.size; j++) {
      printf("%c ", state->board.cells[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

// Function to check if a move is valid
int is_valid_move(GameState *state, int row, int col) {
  return row >= 0 && row < state->board.size && col >= 0 && col < state->board.size && state->board.cells[row][col] == ' ';
}

// Function to make a move
void make_move(GameState *state, int row, int col) {
  if (!is_valid_move(state, row, col)) {
    printf("Error: Invalid move.\n");
    return;
  }
  state->board.cells[row][col] = 'X';
}

// Function to check if the game is over
int is_game_over(GameState *state) {
  // Check for horizontal wins
  for (int i = 0; i < state->board.size; i++) {
    int count = 0;
    for (int j = 0; j < state->board.size; j++) {
      if (state->board.cells[i][j] == 'X') {
        count++;
      }
    }
    if (count == state->board.size) {
      return 1;
    }
  }

  // Check for vertical wins
  for (int i = 0; i < state->board.size; i++) {
    int count = 0;
    for (int j = 0; j < state->board.size; j++) {
      if (state->board.cells[j][i] == 'X') {
        count++;
      }
    }
    if (count == state->board.size) {
      return 1;
    }
  }

  // Check for diagonal wins
  int count1 = 0;
  for (int i = 0; i < state->board.size; i++) {
    if (state->board.cells[i][i] == 'X') {
      count1++;
    }
  }
  if (count1 == state->board.size) {
    return 1;
  }

  int count2 = 0;
  for (int i = 0; i < state->board.size; i++) {
    if (state->board.cells[i][state->board.size - 1 - i] == 'X') {
      count2++;
    }
  }
  if (count2 == state->board.size) {
    return 1;
  }

  // Check for a tie
  int count = 0;
  for (int i = 0; i < state->board.size; i++) {
    for (int j = 0; j < state->board.size; j++) {
      if (state->board.cells[i][j] != ' ') {
        count++;
      }
    }
  }
  if (count == state->board.size * state->board.size) {
    return 2;
  }

  return 0;
}

// Function to get the winner of the game
Player *get_winner(GameState *state) {
  if (state->current_player == -1) {
    return NULL;
  }
  return &state->players[state->current_player];
}

// Function to play the game
void play_game(GameState *state) {
  while (1) {
    // Print the game board
    print_board(state);

    // Get the current player's move
    int row, col;
    printf("Player %s's turn (row, col): ", state->players[state->current_player].name);
    scanf("%d %d", &row, &col);

    // Make the move
    make_move(state, row, col);

    // Check if the game is over
    int result = is_game_over(state);
    if (result == 1) {
      // The game is over, announce the winner
      Player *winner = get_winner(state);
      printf("Player %s wins!\n", winner->name);
      break;
    } else if (result == 2) {
      // The game is over, it's a tie
      printf("The game is a tie!\n");
      break;
    }

    // Switch to the next player
    state->current_player = (state->current_player + 1) % state->num_players;
  }
}

int main() {
  // Create a new game state
  GameState *state = new_game_state();

  // Add players to the game
  add_player(state, "Player 1");
  add_player(state, "Player 2");

  // Play the game
  play_game(state);

  // Free the game state
  free_game_state(state);

  return 0;
}