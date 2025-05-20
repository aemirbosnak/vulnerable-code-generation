//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **cells;
  int current_player;
  int game_status;
} Board;

void initialize_board(Board *board) {
  board->cells = (int **)malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->cells[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
  }
  board->current_player = 1;
  board->game_status = 0;
}

void display_board(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->cells[i][j]);
    }
    printf("\n");
  }
}

int is_board_full(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->cells[i][j] == 0) {
        return 0;
      }
    }
  }
  return 1;
}

int is_player_won(Board *board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->cells[0][i] == player && board->cells[1][i] == player && board->cells[2][i] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->cells[j][0] == player && board->cells[j][1] == player && board->cells[j][2] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board->cells[0][0] == player && board->cells[1][1] == player && board->cells[2][2] == player) {
    return 1;
  }
  if (board->cells[0][2] == player && board->cells[1][1] == player && board->cells[2][0] == player) {
    return 1;
  }

  return 0;
}

int main() {
  Board board;
  initialize_board(&board);

  // Game loop
  while (!is_board_full(&board) && !is_player_won(&board, board.current_player)) {
    display_board(&board);

    // Get the player's move
    int move_x, move_y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &move_x, &move_y);

    // Validate the move
    if (move_x < 0 || move_x >= BOARD_SIZE || move_y < 0 || move_y >= BOARD_SIZE) {
      printf("Invalid move.\n");
      continue;
    }

    // Place the move
    board.cells[move_x][move_y] = board.current_player;

    // Switch the player
    board.current_player *= -1;
  }

  display_board(&board);

  // Game over
  if (is_player_won(&board, board.current_player)) {
    printf("Congratulations! You won!\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}