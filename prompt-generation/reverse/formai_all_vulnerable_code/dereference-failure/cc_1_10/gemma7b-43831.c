//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **board;
  int current_player;
  int game_state;
} Board;

void initialize_board(Board *board) {
  board->board = (int **)malloc(BOARD_SIZE * sizeof(int *));
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->board[i] = (int *)malloc(BOARD_SIZE * sizeof(int));
  }
  board->current_player = 1;
  board->game_state = 0;
}

void play_game(Board *board) {
  int move_made = 0;
  while (!board->game_state && !move_made) {
    int row, column;
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &column);

    if (board->board[row][column] == 0) {
      board->board[row][column] = board->current_player;
      move_made = 1;
    } else {
      printf("That move has already been made.\n");
    }
  }

  if (board->game_state == 1) {
    printf("Player %d won!\n", board->current_player);
  } else if (board->game_state == 2) {
    printf("It's a draw.\n");
  }
}

int main() {
  Board board;
  initialize_board(&board);
  play_game(&board);

  return 0;
}