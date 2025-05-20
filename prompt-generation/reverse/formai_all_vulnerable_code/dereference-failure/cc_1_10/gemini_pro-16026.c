//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 6
#define NUM_COLS 7
#define NUM_COLORS 6
#define MIN_WIN_LENGTH 3

typedef struct {
  int row;
  int col;
  int color;
} Move;

typedef struct {
  Move moves[NUM_ROWS * NUM_COLS];
  int num_moves;
} Game;

// Create a new game.
Game* new_game() {
  Game* game = malloc(sizeof(Game));
  game->num_moves = 0;
  return game;
}

// Free a game.
void free_game(Game* game) {
  free(game);
}

// Add a move to a game.
void add_move(Game* game, Move move) {
  game->moves[game->num_moves] = move;
  game->num_moves++;
}

// Check if a move is valid.
int is_valid_move(Game* game, Move move) {
  if (move.row < 0 || move.row >= NUM_ROWS) {
    return 0;
  }
  if (move.col < 0 || move.col >= NUM_COLS) {
    return 0;
  }
  if (move.color < 0 || move.color >= NUM_COLORS) {
    return 0;
  }
  if (game->moves[game->num_moves - 1].row != move.row) {
    return 0;
  }
  return 1;
}

// Check if a game is over.
int is_game_over(Game* game) {
  if (game->num_moves == NUM_ROWS * NUM_COLS) {
    return 1;
  }
  return 0;
}

// Check if a player has won the game.
int has_won(Game* game) {
  for (int i = 0; i < game->num_moves; i++) {
    Move move = game->moves[i];
    int row = move.row;
    int col = move.col;
    int color = move.color;
    int count = 1;
    // Check to the right.
    for (int j = col + 1; j < NUM_COLS; j++) {
      if (game->moves[i + j].color == color) {
        count++;
      } else {
        break;
      }
    }
    // Check to the left.
    for (int j = col - 1; j >= 0; j--) {
      if (game->moves[i + j].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check down.
    count = 1;
    for (int j = row + 1; j < NUM_ROWS; j++) {
      if (game->moves[i + j * NUM_COLS].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check up.
    count = 1;
    for (int j = row - 1; j >= 0; j--) {
      if (game->moves[i + j * NUM_COLS].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check down and to the right.
    count = 1;
    for (int j = 1; j < NUM_ROWS && j < NUM_COLS; j++) {
      if (game->moves[i + j * NUM_COLS + j].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check down and to the left.
    count = 1;
    for (int j = 1; j < NUM_ROWS && j < NUM_COLS; j++) {
      if (game->moves[i + j * NUM_COLS - j].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check up and to the right.
    count = 1;
    for (int j = -1; j >= -NUM_ROWS && j >= -NUM_COLS; j--) {
      if (game->moves[i + j * NUM_COLS + j].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
    // Check up and to the left.
    count = 1;
    for (int j = -1; j >= -NUM_ROWS && j >= -NUM_COLS; j--) {
      if (game->moves[i + j * NUM_COLS - j].color == color) {
        count++;
      } else {
        break;
      }
    }
    if (count >= MIN_WIN_LENGTH) {
      return 1;
    }
  }
  return 0;
}

// Print the game board.
void print_board(Game* game) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      Move move = game->moves[i * NUM_COLS + j];
      printf("%d ", move.color);
    }
    printf("\n");
  }
}

// Get a random move from the list of valid moves.
Move get_random_move(Game* game) {
  int valid_moves[NUM_ROWS * NUM_COLS];
  int num_valid_moves = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      Move move = {i, j, rand() % NUM_COLORS};
      if (is_valid_move(game, move)) {
        valid_moves[num_valid_moves] = i * NUM_COLS + j;
        num_valid_moves++;
      }
    }
  }
  int random_index = rand() % num_valid_moves;
  int move_index = valid_moves[random_index];
  Move move = game->moves[move_index];
  return move;
}

// Play the game.
void play_game() {
  Game* game = new_game();
  while (!is_game_over(game) && !has_won(game)) {
    Move move = get_random_move(game);
    add_move(game, move);
  }
  if (has_won(game)) {
    printf("Player has won!\n");
  } else {
    printf("Tie game.\n");
  }
  print_board(game);
  free_game(game);
}

int main() {
  srand(time(NULL));
  play_game();
  return 0;
}