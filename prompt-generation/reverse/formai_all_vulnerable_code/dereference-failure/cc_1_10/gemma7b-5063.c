//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct ship {
  int x, y, orientation, size;
  char **board;
} ship_t;

ship_t *create_ship(int size) {
  ship_t *ship = malloc(sizeof(ship_t));
  ship->size = size;
  ship->board = malloc(MAX_SIZE * sizeof(char *));
  for (int i = 0; i < MAX_SIZE; i++) {
    ship->board[i] = malloc(MAX_SIZE * sizeof(char));
  }
  ship->x = ship->y = -1;
  ship->orientation = 0;
  return ship;
}

void place_ship(ship_t *ship, int x, int y, int orientation) {
  ship->x = x;
  ship->y = y;
  ship->orientation = orientation;
}

void shoot(ship_t *ship, int x, int y) {
  if (ship->board[x][y] == 'S') {
    ship->board[x][y] = 'H';
  } else {
    ship->board[x][y] = 'M';
  }
}

int main() {
  ship_t *ship = create_ship(5);
  place_ship(ship, 3, 4, 0);

  shoot(ship, 2, 3);
  shoot(ship, 3, 3);
  shoot(ship, 4, 3);

  for (int i = 0; i < MAX_SIZE; i++) {
    for (int j = 0; j < MAX_SIZE; j++) {
      printf("%c ", ship->board[i][j]);
    }
    printf("\n");
  }

  return 0;
}