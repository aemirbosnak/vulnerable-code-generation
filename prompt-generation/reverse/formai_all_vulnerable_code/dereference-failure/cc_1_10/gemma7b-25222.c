//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20

typedef struct Cell {
  int x;
  int y;
  int state;
} Cell;

Cell **create_board(int size) {
  Cell **board = (Cell **)malloc(size * sizeof(Cell *));
  for (int i = 0; i < size; i++) {
    board[i] = (Cell *)malloc(size * sizeof(Cell));
    for (int j = 0; j < size; j++) {
      board[i][j].x = i;
      board[i][j].y = j;
      board[i][j].state = 0;
    }
  }
  return board;
}

void simulate_game(Cell **board) {
  int neighbor_count;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      neighbor_count = 0;
      if (board[i][j].state == 1) {
        continue;
      }
      // Check neighbors
      for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
          if (x == 0 && y == 0) {
            continue;
          }
          if (board[i + x][j + y].state == 1) {
            neighbor_count++;
          }
        }
      }

      // Apply the Game of Life rules
      if (neighbor_count == 3) {
        board[i][j].state = 1;
      } else if (neighbor_count == 2) {
        board[i][j].state = 0;
      }
    }
  }
}

int main() {
  Cell **board = create_board(BOARD_SIZE);

  // Seed the random number generator
  srand(time(NULL));

  // Randomly assign some cells to be alive
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j].state = rand() % 2;
    }
  }

  // Simulate the game for 10 generations
  for (int gen = 0; gen < 10; gen++) {
    simulate_game(board);
  }

  // Print the final board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%d ", board[i][j].state);
    }
    printf("\n");
  }

  return 0;
}