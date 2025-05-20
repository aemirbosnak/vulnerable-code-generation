//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
  int **data;
  int size;
} Board;

Board *board_init(int size) {
  Board *b = malloc(sizeof(Board));
  b->size = size;
  b->data = malloc(size * size * sizeof(int));
  for (int i = 0; i < size * size; i++) {
    b->data[i] = 0;
  }
  return b;
}

void board_draw(Board *b) {
  for (int r = 0; r < b->size; r++) {
    for (int c = 0; c < b->size; c++) {
      printf("%d ", b->data[r * b->size + c]);
    }
    printf("\n");
  }
}

int board_check_win(Board *b, int player) {
  // Check rows
  for (int r = 0; r < b->size; r++) {
    if (b->data[r * b->size] == player &&
        b->data[r * b->size + 1] == player &&
        b->data[r * b->size + 2] == player) {
      return 1;
    }
  }

  // Check columns
  for (int c = 0; c < b->size; c++) {
    if (b->data[c] == player &&
        b->data[c + b->size] == player &&
        b->data[c + 2 * b->size] == player) {
      return 1;
    }
  }

  // Check diagonals
  if (b->data[0] == player &&
    b->data[b->size + 1] == player &&
    b->data[2 * b->size - 1] == player) {
    return 1;
  }

  // No win
  return 0;
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Board *b = board_init(BOARD_SIZE);

  int player = rand() % 2 + 1;

  // Game loop
  while (!board_check_win(b, player) && board_check_win(b, player) != -1) {
    int move = rand() % (b->size * b->size);

    if (b->data[move] == 0) {
      b->data[move] = player;
    }
  }

  board_draw(b);

  // Game over
  if (board_check_win(b, player) == 1) {
    printf("Player %d won!", player);
  } else {
    printf("It's a draw!");
  }

  free(b->data);
  free(b);

  return 0;
}