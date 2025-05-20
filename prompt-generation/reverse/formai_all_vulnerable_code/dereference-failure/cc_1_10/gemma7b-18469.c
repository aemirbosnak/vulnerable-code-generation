//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_status;
} Board;

void initialize_board(Board *board) {
  board->board = (int **)malloc(MAX_BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    board->board[i] = (int *)malloc(MAX_BOARD_SIZE * sizeof(int));
  }

  board->current_player = 1;
  board->game_status = 0;
}

void display_board(Board *board) {
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    for (int j = 0; j < MAX_BOARD_SIZE; j++) {
      printf("%d ", board->board[i][j]);
    }
    printf("\n");
  }
}

int make_move(Board *board, int row, int column) {
  if (board->board[row][column] != 0) {
    return -1;
  }

  board->board[row][column] = board->current_player;
  board->current_player = (board->current_player == 1) ? 2 : 1;

  return 0;
}

int check_win(Board *board) {
  // Check rows
  for (int i = 0; i < MAX_BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i];
    }
  }

  // Check columns
  for (int j = 0; j < MAX_BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0];
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0];
  }

  // If all cells are filled and no winner, it's a draw
  return 3;
}

int main() {
  Board board;
  initialize_board(&board);

  // Game loop
  while (!board.game_status) {
    // Get the player's move
    int row, column;
    printf("Enter row: ");
    scanf("%d", &row);

    printf("Enter column: ");
    scanf("%d", &column);

    // Make the move
    if (make_move(&board, row, column) == -1) {
      printf("Error: Invalid move.\n");
    }

    // Display the board
    display_board(&board);

    // Check if the player won or there's a draw
    board.game_status = check_win(&board);
  }

  // Game over
  if (board.game_status == 1) {
    printf("Player 1 won!\n");
  } else if (board.game_status == 2) {
    printf("Player 2 won!\n");
  } else {
    printf("It's a draw.\n");
  }

  return 0;
}