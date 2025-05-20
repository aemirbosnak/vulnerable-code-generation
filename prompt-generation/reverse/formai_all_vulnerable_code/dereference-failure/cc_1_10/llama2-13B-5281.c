//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Function to draw the game board
void draw_board(char** board) {
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    for (int j = 0; j < WINDOW_HEIGHT; j++) {
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }
}

// Function to update the game board
void update_board(char** board) {
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    for (int j = 0; j < WINDOW_HEIGHT; j++) {
      int alive_neighbors = 0;
      for (int k = i - 1; k <= i + 1; k++) {
        for (int l = j - 1; l <= j + 1; l++) {
          if (board[k][l] == '1') {
            alive_neighbors++;
          }
        }
      }
      if (alive_neighbors < 2 && board[i][j] == '1') {
        board[i][j] = '0';
      } else if (alive_neighbors > 3 && board[i][j] == '0') {
        board[i][j] = '1';
      }
    }
  }
}

// Function to run the game
void game_of_life(char** board) {
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    for (int j = 0; j < WINDOW_HEIGHT; j++) {
      board[i][j] = '0';
    }
  }
  for (int generation = 0; generation < 100; generation++) {
    update_board(board);
    draw_board(board);
  }
}

int main() {
  char** board = (char**) malloc(WINDOW_WIDTH * sizeof(char*));
  for (int i = 0; i < WINDOW_WIDTH; i++) {
    board[i] = (char*) malloc(WINDOW_HEIGHT * sizeof(char));
    for (int j = 0; j < WINDOW_HEIGHT; j++) {
      board[i][j] = '0';
    }
  }
  game_of_life(board);
  return 0;
}