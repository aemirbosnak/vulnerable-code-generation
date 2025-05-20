//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void drawBoard(char **board, int size) {
  for (int r = 0; r < size; r++) {
    for (int c = 0; c < size; c++) {
      printf("%c ", board[r][c]);
    }
    printf("\n");
  }
}

int main() {
  char **board = (char **)malloc(MAX_SIZE * sizeof(char *));
  for (int r = 0; r < MAX_SIZE; r++) {
    board[r] = (char *)malloc(MAX_SIZE * sizeof(char));
  }

  // Initialize the game board
  for (int r = 0; r < MAX_SIZE; r++) {
    for (int c = 0; c < MAX_SIZE; c++) {
      board[r][c] = '-';
    }
  }

  // Place the initial living organisms
  board[10][10] = 'o';
  board[10][11] = 'o';
  board[11][10] = 'o';
  board[11][11] = 'o';

  // Simulate the game of life
  for (int t = 0; t < 20; t++) {
    drawBoard(board, MAX_SIZE);

    // Calculate the number of living neighbors for each organism
    for (int r = 0; r < MAX_SIZE; r++) {
      for (int c = 0; c < MAX_SIZE; c++) {
        int neighbors = 0;
        if (board[r-1][c] == 'o') neighbors++;
        if (board[r+1][c] == 'o') neighbors++;
        if (board[r][c-1] == 'o') neighbors++;
        if (board[r][c+1] == 'o') neighbors++;

        // Apply the rules of life
        if (board[r][c] == 'o' && neighbors < 2) board[r][c] = '-';
        if (board[r][c] == '-' && neighbors == 3) board[r][c] = 'o';
      }
    }
  }

  drawBoard(board, MAX_SIZE);

  free(board);

  return 0;
}