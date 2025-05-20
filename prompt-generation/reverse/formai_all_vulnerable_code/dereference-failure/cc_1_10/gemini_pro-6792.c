//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define NUM_ROWS 6
#define NUM_COLS 7
#define NUM_COLORS 6
#define MAX_NAME_LENGTH 20

// Data structures
typedef struct {
  char name[MAX_NAME_LENGTH];
  int score;
  int turn;
} Player;

typedef struct {
  char color;
  int x;
  int y;
} Chip;

typedef struct {
  Player players[4];
  Chip board[NUM_ROWS][NUM_COLS];
  int current_player;
} Game;

// Function prototypes
void initialize_game(Game *game);
void print_board(Game *game);
void get_player_move(Game *game);
void place_chip(Game *game, int x, int y);
void check_for_winner(Game *game);
void print_winner(Game *game);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Initialize the game
  Game game;
  initialize_game(&game);

  // Print the board
  print_board(&game);

  // Get the player's move
  get_player_move(&game);

  // Place the chip
  place_chip(&game, game.players[game.current_player].turn, NUM_ROWS - 1);

  // Check for a winner
  check_for_winner(&game);

  // Print the winner
  print_winner(&game);

  return 0;
}

// Function definitions
void initialize_game(Game *game) {
  // Initialize the players
  for (int i = 0; i < 4; i++) {
    strcpy(game->players[i].name, "Player");
    game->players[i].score = 0;
    game->players[i].turn = i + 1;
  }

  // Initialize the board
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      game->board[i][j].color = ' ';
      game->board[i][j].x = j;
      game->board[i][j].y = i;
    }
  }

  // Set the current player
  game->current_player = 0;
}

void print_board(Game *game) {
  // Print the header
  printf("  ");
  for (int i = 0; i < NUM_COLS; i++) {
    printf("%d ", i + 1);
  }
  printf("\n");

  // Print the board
  for (int i = 0; i < NUM_ROWS; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%c ", game->board[i][j].color);
    }
    printf("\n");
  }
}

void get_player_move(Game *game) {
  // Get the player's input
  int x;
  printf("Player %d, enter a column (1-%d): ", game->current_player + 1, NUM_COLS);
  scanf("%d", &x);

  // Validate the input
  while (x < 1 || x > NUM_COLS) {
    printf("Invalid input. Please enter a column (1-%d): ", NUM_COLS);
    scanf("%d", &x);
  }

  // Set the player's turn
  game->players[game->current_player].turn = x;
}

void place_chip(Game *game, int x, int y) {
  // Find the first empty cell in the column
  while (y >= 0 && game->board[y][x].color != ' ') {
    y--;
  }

  // Place the chip in the cell
  game->board[y][x].color = game->players[game->current_player].name[0];
}

void check_for_winner(Game *game) {
  // Check for a horizontal win
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS - 3; j++) {
      if (game->board[i][j].color != ' ' &&
          game->board[i][j].color == game->board[i][j + 1].color &&
          game->board[i][j].color == game->board[i][j + 2].color &&
          game->board[i][j].color == game->board[i][j + 3].color) {
        game->players[game->current_player].score += 1;
        return;
      }
    }
  }

  // Check for a vertical win
  for (int i = 0; i < NUM_ROWS - 3; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (game->board[i][j].color != ' ' &&
          game->board[i][j].color == game->board[i + 1][j].color &&
          game->board[i][j].color == game->board[i + 2][j].color &&
          game->board[i][j].color == game->board[i + 3][j].color) {
        game->players[game->current_player].score += 1;
        return;
      }
    }
  }

  // Check for a diagonal win (top-left to bottom-right)
  for (int i = 0; i < NUM_ROWS - 3; i++) {
    for (int j = 0; j < NUM_COLS - 3; j++) {
      if (game->board[i][j].color != ' ' &&
          game->board[i][j].color == game->board[i + 1][j + 1].color &&
          game->board[i][j].color == game->board[i + 2][j + 2].color &&
          game->board[i][j].color == game->board[i + 3][j + 3].color) {
        game->players[game->current_player].score += 1;
        return;
      }
    }
  }

  // Check for a diagonal win (top-right to bottom-left)
  for (int i = 0; i < NUM_ROWS - 3; i++) {
    for (int j = NUM_COLS - 1; j >= 3; j--) {
      if (game->board[i][j].color != ' ' &&
          game->board[i][j].color == game->board[i + 1][j - 1].color &&
          game->board[i][j].color == game->board[i + 2][j - 2].color &&
          game->board[i][j].color == game->board[i + 3][j - 3].color) {
        game->players[game->current_player].score += 1;
        return;
      }
    }
  }
}

void print_winner(Game *game) {
  // Find the player with the highest score
  int max_score = 0;
  int winner = -1;
  for (int i = 0; i < 4; i++) {
    if (game->players[i].score > max_score) {
      max_score = game->players[i].score;
      winner = i;
    }
  }

  // Print the winner
  if (winner == -1) {
    printf("Tie!\n");
  } else {
    printf("Player %d wins!\n", winner + 1);
  }
}