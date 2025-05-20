//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
  int x;
  int y;
  int direction;
} Pacman;

Pacman pacman;

void drawBoard(int **board) {
  for (int r = 0; r < BOARD_SIZE; r++) {
    for (int c = 0; c < BOARD_SIZE; c++) {
      printf("%c ", board[r][c] ? '#' : '.');
    }
    printf("\n");
  }
}

void movePacman(int direction) {
  switch (direction) {
    case 0:
      pacman.x++;
      break;
    case 1:
      pacman.y++;
      break;
    case 2:
      pacman.x--;
      break;
    case 3:
      pacman.y--;
      break;
  }

  if (pacman.x < 0 || pacman.x >= BOARD_SIZE - PACMAN_SIZE) {
    pacman.direction = (pacman.direction + 1) % 4;
  }

  if (pacman.y < 0 || pacman.y >= BOARD_SIZE - PACMAN_SIZE) {
    pacman.direction = (pacman.direction + 1) % 4;
  }
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {0};
  board[pacman.x][pacman.y] = 1;

  drawBoard(board);

  for (int i = 0; i < 100; i++) {
    movePacman(pacman.direction);
    drawBoard(board);
  }

  return 0;
}