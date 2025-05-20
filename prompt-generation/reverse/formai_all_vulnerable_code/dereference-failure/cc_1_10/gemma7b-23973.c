//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

// Define a structure to represent the tic tac toe board
typedef struct Board {
  char board[BOARD_SIZE][BOARD_SIZE];
  char current_player;
  int game_status;
} Board;

// Function to initialize the tic tac toe board
void initialize_board(Board *board) {
  board->board[0][0] = board->board[0][1] = board->board[0][2] = ' ';
  board->board[1][0] = board->board[1][1] = board->board[1][2] = ' ';
  board->board[2][0] = board->board[2][1] = board->board[2][2] = ' ';
  board->current_player = PLAYER_X;
  board->game_status = 0;
}

// Function to place a piece on the tic tac toe board
void place_piece(Board *board, int row, int col) {
  if (board->board[row][col] != ' ') {
    return;
  }
  board->board[row][col] = board->current_player;
  board->current_player = (board->current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

// Function to check if the player has won the game
int has_won(Board *board, char player) {
  // Check rows
  for (int r = 0; r < BOARD_SIZE; r++) {
    if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < BOARD_SIZE; c++) {
    if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] == player) {
    return 1;
  }

  // If all else fails, the game is still on
  return 0;
}

// Function to play the tic tac toe game
void play_game(Board *board) {
  // Initialize the board
  initialize_board(board);

  // Loop until one of the players wins or it's a draw
  while (!has_won(board, board->current_player) && board->game_status == 0) {
    // Get the player's move
    int row, col;
    printf("Enter row and column (1-3): ");
    scanf("%d %d", &row, &col);

    // Place the piece on the board
    place_piece(board, row, col);
  }

  // Check if the player has won or it's a draw
  if (has_won(board, board->current_player)) {
    printf("Congratulations! %c has won!", board->current_player);
  } else if (board->game_status == 1) {
    printf("It's a draw!");
  }
}

int main() {
  Board board;
  play_game(&board);

  return 0;
}