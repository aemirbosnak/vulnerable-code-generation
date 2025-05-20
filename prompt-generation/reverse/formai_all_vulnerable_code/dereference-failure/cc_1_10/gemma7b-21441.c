//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define GRID_SIZE 10
#define SHIP_SIZE 5

typedef struct Ship {
  int x;
  int y;
  int direction;
  int speed;
  struct Ship* next;
} Ship;

Ship* head = NULL;

void initShip(int x, int y, int direction, int speed) {
  Ship* newShip = malloc(sizeof(Ship));
  newShip->x = x;
  newShip->y = y;
  newShip->direction = direction;
  newShip->speed = speed;
  newShip->next = head;
  head = newShip;
}

void moveShip() {
  Ship* currentShip = head;
  while (currentShip) {
    switch (currentShip->direction) {
      case LEFT:
        currentShip->x--;
        break;
      case RIGHT:
        currentShip->x++;
        break;
      case UP:
        currentShip->y--;
        break;
      case DOWN:
        currentShip->y++;
        break;
    }

    currentShip = currentShip->next;
  }
}

void drawGrid() {
  for (int x = 0; x < GRID_SIZE; x++) {
    for (int y = 0; y < GRID_SIZE; y++) {
      Ship* currentShip = head;
      while (currentShip) {
        if (currentShip->x == x && currentShip->y == y) {
          printf("O ");
        } else {
          printf(". ");
        }
      }
    }

    printf("\n");
  }
}

int main() {
  initShip(5, 5, RIGHT, 1);
  initShip(2, 2, LEFT, 1);
  initShip(7, 0, UP, 1);

  drawGrid();

  moveShip();

  drawGrid();

  return 0;
}