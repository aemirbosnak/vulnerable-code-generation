//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

typedef struct invader {
  int x, y;
  char direction;
  struct invader* next;
} invader;

invader* createInvader() {
  invader* newInvader = malloc(sizeof(invader));
  newInvader->x = 0;
  newInvader->y = 0;
  newInvader->direction = 'r';
  newInvader->next = NULL;
  return newInvader;
}

void moveInvader(invader* invader) {
  switch (invader->direction) {
    case 'r':
      invader->x++;
      break;
    case 'l':
      invader->x--;
      break;
    case 'u':
      invader->y--;
      break;
    case 'd':
      invader->y++;
      break;
  }

  if (invader->x >= MAX_WIDTH - 1) {
    invader->direction = 'l';
  } else if (invader->x <= 0) {
    invader->direction = 'r';
  }

  if (invader->y >= MAX_HEIGHT - 1) {
    invader->direction = 'u';
  } else if (invader->y <= 0) {
    invader->direction = 'd';
  }
}

int main() {
  invader* head = createInvader();
  head->next = createInvader();
  head->next->next = createInvader();

  while (1) {
    moveInvader(head);
    printf("Invader position: (%d, %d)\n", head->x, head->y);
    sleep(1);
  }

  return 0;
}