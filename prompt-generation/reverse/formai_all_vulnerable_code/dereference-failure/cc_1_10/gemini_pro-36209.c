//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// The game board is represented as a 2D array of cells.
// Each cell can be either alive or dead.
char **board;

// The size of the game board.
int board_size;

// The number of generations to simulate.
int generations;

// Function to create the game board.
void create_board() {
  // Allocate memory for the game board.
  board = malloc(board_size * sizeof(char *));
  for (int i = 0; i < board_size; i++) {
    board[i] = malloc(board_size * sizeof(char));
  }

  // Initialize the game board with random values.
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      board[i][j] = rand() % 2;
    }
  }
}

// Function to free the memory allocated for the game board.
void free_board() {
  for (int i = 0; i < board_size; i++) {
    free(board[i]);
  }
  free(board);
}

// Function to print the game board to the console.
void print_board() {
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      printf("%c", board[i][j] ? 'O' : '.');
    }
    printf("\n");
  }
}

// Function to count the number of living neighbors of a cell.
int count_neighbors(int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      int neighbor_x = x + i;
      int neighbor_y = y + j;
      if (neighbor_x < 0 || neighbor_x >= board_size || neighbor_y < 0 || neighbor_y >= board_size) {
        continue;
      }
      if (board[neighbor_x][neighbor_y]) {
        count++;
      }
    }
  }
  return count;
}

// Function to update the game board to the next generation.
void update_board() {
  // Create a temporary board to store the next generation.
  char **next_board = malloc(board_size * sizeof(char *));
  for (int i = 0; i < board_size; i++) {
    next_board[i] = malloc(board_size * sizeof(char));
  }

  // Update each cell of the game board.
  for (int i = 0; i < board_size; i++) {
    for (int j = 0; j < board_size; j++) {
      int neighbors = count_neighbors(i, j);
      if (board[i][j]) {
        // If a living cell has 2 or 3 living neighbors, it survives.
        if (neighbors == 2 || neighbors == 3) {
          next_board[i][j] = 1;
        } else {
          // Otherwise, it dies.
          next_board[i][j] = 0;
        }
      } else {
        // If a dead cell has exactly 3 living neighbors, it becomes alive.
        if (neighbors == 3) {
          next_board[i][j] = 1;
        } else {
          // Otherwise, it remains dead.
          next_board[i][j] = 0;
        }
      }
    }
  }

  // Copy the next generation board to the game board.
  for (int i = 0; i < board_size; i++) {
    memcpy(board[i], next_board[i], board_size * sizeof(char));
  }

  // Free the memory allocated for the temporary board.
  for (int i = 0; i < board_size; i++) {
    free(next_board[i]);
  }
  free(next_board);
}

// Main function.
int main() {
  // Set the size of the game board.
  board_size = 100;

  // Set the number of generations to simulate.
  generations = 100;

  // Create the game board.
  create_board();

  // Print the initial game board to the console.
  printf("Initial game board:\n");
  print_board();

  // Update the game board to the next generation.
  for (int i = 0; i < generations; i++) {
    update_board();
  }

  // Print the final game board to the console.
  printf("Final game board:\n");
  print_board();

  // Free the memory allocated for the game board.
  free_board();

  return 0;
}