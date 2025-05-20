//Gemma-7B DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the number of players
#define NUM_PLAYERS 2

// Define the number of rounds
#define NUM_ROUNDS 3

// Define the game board
#define BOARD_SIZE 5

// Define the winning condition
#define WIN_CONDITION 3

// Game pieces
#define EMPTY 0
#define PLAYER_1 1
#define PLAYER_2 2

// Function to initialize the game board
void initializeBoard(int **board) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

// Function to place a piece on the board
void placePiece(int **board, int player, int row, int column) {
  if (board[row][column] != EMPTY) {
    return;
  }
  board[row][column] = player;
}

// Function to check if the player has won
int hasWon(int **board, int player) {
  // Check rows
  for (int i = 0; i < BOARD_SIZE; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int j = 0; j < BOARD_SIZE; j++) {
    if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return 1;
  }
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return 1;
  }

  return 0;
}

// Function to play a round
void playRound(int **board, int player) {
  int row, column;

  // Get the player's move
  printf("Enter row and column (e.g. 0 0): ");
  scanf("%d %d", &row, &column);

  // Place the piece on the board
  placePiece(board, player, row, column);

  // Check if the player has won
  if (hasWon(board, player)) {
    printf("You have won!");
  } else if (board[row][column] == EMPTY) {
    printf("Invalid move.");
  }
}

// Main game loop
int main() {
  int **board = NULL;
  int player = PLAYER_1;

  // Initialize the game board
  initializeBoard(&board);

  // Play the rounds
  for (int i = 0; i < NUM_ROUNDS; i++) {
    playRound(board, player);

    // Switch players
    player = (player == PLAYER_1) ? PLAYER_2 : PLAYER_1;
  }

  // Check if there has been a winner or if the board is full
  if (hasWon(board, EMPTY) || board[0][0] == EMPTY && board[0][1] == EMPTY && board[0][2] == EMPTY) {
    printf("It's a draw.");
  }

  return 0;
}