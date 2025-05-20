//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_state;
} Board;

void initialize_board(Board *board) {
  board->board = malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = malloc(BOARD_SIZE * sizeof(int));
  }

  board->current_player = 1;
  board->game_state = 0;
}

void print_board(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }

    printf("\n");
  }
}

int is_board_full(Board *board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (board->board[i][j] == 0) {
        return 0;
      }
    }
  }

  return 1;
}

int has_player_won(Board *board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == player && board->board[1][i] == player && board->board[2][i] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == player && board->board[j][1] == player && board->board[j][2] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
    return 1;
  }

  if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
    return 1;
  }

  return 0;
}

int main() {
  Board board;
  initialize_board(&board);

  print_board(&board);

  // Game loop
  while (!is_board_full(&board) && !has_player_won(&board, board.current_player)) {
    // Get player move
    int row, column;
    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &column);

    // Place piece on board
    board.board[row][column] = board.current_player;

    print_board(&board);

    // Switch current player
    board.current_player *= -1;
  }

  // Game over
  print_board(&board);

  if (has_player_won(&board, board.current_player)) {
    printf("Winner: Player %d\n", board.current_player);
  } else {
    printf("It's a draw!\n");
  }

  return 0;
}