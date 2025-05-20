//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_INvaders 10
#define invader_WIDTH 5
#define invader_HEIGHT 3

typedef struct Invader {
  int x;
  int y;
  int direction;
  struct Invader* next;
} Invader;

Invader* invader_create(int x, int y, int direction) {
  Invader* invader = malloc(sizeof(Invader));
  invader->x = x;
  invader->y = y;
  invader->direction = direction;
  invader->next = NULL;
  return invader;
}

void invader_move(Invader* invader) {
  switch (invader->direction) {
    case 0:
      invader->x++;
      break;
    case 1:
      invader->x--;
      break;
    case 2:
      invader->y++;
      break;
    case 3:
      invader->y--;
      break;
  }
}

void invader_draw(Invader* invader) {
  printf("%c", invader->x * invader_WIDTH + invader->y);
}

int main() {
  Invader* head = invader_create(0, 0, 0);
  for (int i = 0; i < MAX_INvaders; i++) {
    invader_create(i, 0, 0);
  }

  for (int i = 0; i < 100; i++) {
    invader_move(head);
    invader_draw(head);
    printf("\n");
  }

  return 0;
}