//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

typedef struct invaders_s invaders_t;
struct invaders_s {
  int x;
  int y;
  int direction;
  invaders_t* next;
};

invaders_t* invaders_create(int x, int y) {
  invaders_t* invaders = malloc(sizeof(invaders_t));
  invaders->x = x;
  invaders->y = y;
  invaders->direction = 1;
  invaders->next = NULL;

  return invaders;
}

void invaders_move(invaders_t* invaders) {
  switch (invaders->direction) {
    case 1:
      invaders->x++;
      break;
    case 2:
      invaders->x--;
      break;
    case 3:
      invaders->y++;
      break;
    case 4:
      invaders->y--;
      break;
  }

  if (invaders->x >= MAX_WIDTH - 1) {
    invaders->direction = 2;
  } else if (invaders->x <= 0) {
    invaders->direction = 1;
  } else if (invaders->y >= MAX_HEIGHT - 1) {
    invaders->direction = 4;
  } else if (invaders->y <= 0) {
    invaders->direction = 3;
  }
}

int main() {
  invaders_t* invaders = invaders_create(0, 0);

  for (int i = 0; i < 100; i++) {
    invaders_move(invaders);
    printf("%d, %d\n", invaders->x, invaders->y);
  }

  return 0;
}