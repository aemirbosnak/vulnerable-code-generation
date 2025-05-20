//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to create a new game board
int** create_board() {
  // Allocate memory for the game board
  int** board = (int**)malloc(SIZE * sizeof(int*));
  for (int i = 0; i < SIZE; i++) {
    board[i] = (int*)malloc(SIZE * sizeof(int));
  }

  // Initialize the game board with random numbers
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = rand() % 10;
    }
  }

  return board;
}

// Function to print the game board
void print_board(int** board) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to check if the game is over
int is_game_over(int** board) {
  // Check if there are any empty cells
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }

  // Check if there are any moves left
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i > 0 && board[i-1][j] == board[i][j]) {
        return 0;
      }
      if (i < SIZE - 1 && board[i+1][j] == board[i][j]) {
        return 0;
      }
      if (j > 0 && board[i][j-1] == board[i][j]) {
        return 0;
      }
      if (j < SIZE - 1 && board[i][j+1] == board[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to make a move
void make_move(int** board, int x, int y) {
  // Check if the move is valid
  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
    printf("Invalid move!\n");
    return;
  }
  if (board[x][y] != 0) {
    printf("Cell is not empty!\n");
    return;
  }

  // Make the move
  board[x][y] = 2;

  // Merge any adjacent cells with the same number
  if (x > 0 && board[x-1][y] == board[x][y]) {
    board[x-1][y] = 0;
    board[x][y] = 4;
  }
  if (x < SIZE - 1 && board[x+1][y] == board[x][y]) {
    board[x+1][y] = 0;
    board[x][y] = 4;
  }
  if (y > 0 && board[x][y-1] == board[x][y]) {
    board[x][y-1] = 0;
    board[x][y] = 4;
  }
  if (y < SIZE - 1 && board[x][y+1] == board[x][y]) {
    board[x][y+1] = 0;
    board[x][y] = 4;
  }
}

// Function to get the player's move
void get_move(int** board, int* x, int* y) {
  // Prompt the player for a move
  printf("Enter the coordinates of your move (x, y): ");
  scanf("%d %d", x, y);
}

// Function to play the game
void play_game() {
  // Create a new game board
  int** board = create_board();

  // Print the game board
  print_board(board);

  // Get the player's move
  int x, y;
  get_move(board, &x, &y);

  // Make the move
  make_move(board, x, y);

  // Print the game board
  print_board(board);

  // Check if the game is over
  if (is_game_over(board)) {
    printf("Game over!\n");
  } else {
    // Continue playing the game
    play_game();
  }

  // Free the memory allocated for the game board
  for (int i = 0; i < SIZE; i++) {
    free(board[i]);
  }
  free(board);
}

int main() {
  // Play the game
  play_game();

  return 0;
}