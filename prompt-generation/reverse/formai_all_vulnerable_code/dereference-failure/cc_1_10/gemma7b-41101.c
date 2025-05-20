//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

typedef struct invader_s {
  int x;
  int y;
  int direction;
  struct invader_s* next;
} invader_t;

invader_t* invader_create() {
  invader_t* invader = (invader_t*)malloc(sizeof(invader_t));
  invader->x = 0;
  invader->y = MAX_HEIGHT - 1;
  invader->direction = 1;
  invader->next = NULL;
  return invader;
}

void invader_move(invader_t* invader) {
  switch (invader->direction) {
    case 1:
      invader->x++;
      break;
    case 2:
      invader->x--;
      break;
    case 3:
      invader->y--;
      break;
  }

  if (invader->x >= MAX_WIDTH - 1) {
    invader->direction = 2;
  } else if (invader->x <= 0) {
    invader->direction = 1;
  }

  if (invader->y <= 0) {
    invader->direction = 3;
  }
}

int main() {
  invader_t* head = invader_create();

  for (int i = 0; i < 100; i++) {
    invader_move(head);
  }

  return 0;
}