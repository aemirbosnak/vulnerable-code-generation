//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdlib.h>
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

int make_move(Board *board, int x, int y) {
  if (board->game_state != 0) {
    return -1;
  }
  if (board->board[x][y] != 0) {
    return -1;
  }

  board->board[x][y] = board->current_player;
  board->current_player *= -1;

  return 0;
}

int check_win(Board *board) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
      return board->board[0][i] * 2;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
      return board->board[j][0] * 2;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
    return board->board[0][0] * 2;
  }

  // If all cells are occupied and no winner, it's a draw
  return 3;
}

int main() {
  Board board;
  initialize_board(&board);

  // Play the game
  while (board.game_state == 0) {
    // Get the player's move
    int x, y;
    printf("Enter your move (x, y): ");
    scanf("%d %d", &x, &y);

    // Make the move
    if (make_move(&board, x, y) == -1) {
      printf("Invalid move.\n");
    }
  }

  // Check if the player won or it's a draw
  int winner = check_win(&board);

  // Print the winner or draw
  switch (winner) {
    case 1:
      printf("You won!\n");
      break;
    case -1:
      printf("Draw.\n");
      break;
    case 2:
      printf("The computer won.\n");
      break;
  }

  return 0;
}