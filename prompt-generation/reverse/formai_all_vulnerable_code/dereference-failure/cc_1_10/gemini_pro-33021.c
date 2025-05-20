//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 3
#define NUM_COLS 3

// Function to create a new game board
char** create_board(void) {
  char** board = malloc(NUM_ROWS * sizeof(char*));
  for (int i = 0; i < NUM_ROWS; i++) {
    board[i] = malloc(NUM_COLS * sizeof(char));
  }
  return board;
}

// Function to free the game board
void free_board(char** board) {
  for (int i = 0; i < NUM_ROWS; i++) {
    free(board[i]);
  }
  free(board);
}

// Function to print the game board
void print_board(char** board) {
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the game is over
int game_over(char** board) {
  // Check for rows
  for (int i = 0; i < NUM_ROWS; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return 1;
    }
  }

  // Check for columns
  for (int i = 0; i < NUM_COLS; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return 1;
    }
  }

  // Check for diagonals
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return 1;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return 1;
  }

  // Check for a tie
  int num_empty = 0;
  for (int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < NUM_COLS; j++) {
      if (board[i][j] == ' ') {
        num_empty++;
      }
    }
  }
  if (num_empty == 0) {
    return 2;
  }

  // No winner yet
  return 0;
}

// Function to get the next move from the player
void get_move(char** board, char player) {
  int row, col;
  do {
    printf("Player %c's turn (enter row and column, 0-2): ", player);
    scanf("%d %d", &row, &col);
  } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ');

  board[row][col] = player;
}

// Main game loop
int main(void) {
  // Create the game board
  char** board = create_board();

  // Set the initial player to 'X'
  char player = 'X';

  // Game loop
  while (1) {
    // Print the game board
    print_board(board);

    // Get the next move from the player
    get_move(board, player);

    // Check if the game is over
    int result = game_over(board);
    if (result == 1) {
      // We have a winner!
      printf("Player %c wins!\n", player);
      break;
    } else if (result == 2) {
      // It's a tie!
      printf("Tie game!\n");
      break;
    }

    // Switch to the other player
    player = (player == 'X') ? 'O' : 'X';
  }

  // Free the game board
  free_board(board);

  return 0;
}