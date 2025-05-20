//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define BOARD_SIZE 3

// Define the board structure
typedef struct Board {
  int **grid;
  int current_player;
  int winner;
} Board;

// Initialize a new board
Board *init_board() {
  Board *board = malloc(sizeof(Board));
  board->grid = malloc(sizeof(int *) * BOARD_SIZE);
  for (int i = 0; i < BOARD_SIZE; i++) {
    board->grid[i] = malloc(sizeof(int) * BOARD_SIZE);
  }
  board->current_player = 1;
  board->winner = 0;
  return board;
}

// Place a mark on the board
void place_mark(Board *board, int x, int y) {
  if (board->grid[x][y] == 0) {
    board->grid[x][y] = board->current_player;
  }
}

// Check if the player has won
int check_win(Board *board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->grid[0][i] == player && board->grid[1][i] == player && board->grid[2][i] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->grid[j][0] == player && board->grid[j][1] == player && board->grid[j][2] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board->grid[0][0] == player && board->grid[1][1] == player && board->grid[2][2] == player) {
    return 1;
  }

  // If all cells are occupied and there is no winner, it's a draw
  return 2;
}

// Play a game of Tic Tac Toe
int main() {
  Board *board = init_board();

  // Game loop
  while (!board->winner) {
    // Get the player's move
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Place the mark
    place_mark(board, x, y);

    // Check if the player has won
    board->winner = check_win(board, board->current_player);

    // Switch to the next player
    board->current_player = (board->current_player == 1) ? 2 : 1;
  }

  // Game over
  switch (board->winner) {
    case 1:
      printf("You won!\n");
      break;
    case 2:
      printf("It's a draw.\n");
      break;
  }

  return 0;
}