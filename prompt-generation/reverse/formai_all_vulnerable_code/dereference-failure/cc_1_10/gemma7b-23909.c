//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 20
#define BOARD_HEIGHT 10

typedef struct invader {
  int x, y, direction, speed, state;
} Invader;

Invader invaders[50];

void draw_board(int **board) {
  for (int y = 0; y < BOARD_HEIGHT; y++) {
    for (int x = 0; x < BOARD_WIDTH; x++) {
      printf("%c ", board[x][y] ? '#' : '.');
    }
    printf("\n");
  }
}

void move_invaders(Invader *invaders) {
  for (int i = 0; i < 50; i++) {
    switch (invaders[i].direction) {
      case 0:
        invaders[i].x++;
        break;
      case 1:
        invaders[i].x--;
        break;
      case 2:
        invaders[i].y++;
        break;
      case 3:
        invaders[i].y--;
        break;
    }

    if (invaders[i].x >= BOARD_WIDTH - 1 || invaders[i].x <= 0) {
      invaders[i].direction *= -1;
    }

    if (invaders[i].y >= BOARD_HEIGHT - 1) {
      invaders[i].state = 2;
    }
  }
}

int main() {
  int **board = malloc(BOARD_WIDTH * sizeof(int *));
  for (int i = 0; i < BOARD_WIDTH; i++) {
    board[i] = malloc(BOARD_HEIGHT * sizeof(int));
  }

  for (int i = 0; i < 50; i++) {
    invaders[i].x = rand() % BOARD_WIDTH;
    invaders[i].y = 0;
    invaders[i].direction = rand() % 4;
  }

  time_t t = time(NULL);
  while (time(NULL) - t < 10) {
    move_invaders(invaders);
    draw_board(board);

    for (int i = 0; i < 50; i++) {
      if (invaders[i].state == 2) {
        printf("Game Over!\n");
        return 0;
      }
    }

    sleep(0.1);
  }

  printf("Time's up!\n");
  return 0;
}