//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

#define LEFT_BOUND 0
#define RIGHT_BOUND MAX_WIDTH - 1
#define TOP_BOUND 0
#define BOTTOM_BOUND MAX_HEIGHT - 1

typedef struct invader {
  int x, y;
  char direction;
  struct invader* next;
} invader;

invader* create_invader(int x, int y) {
  invader* new_invader = malloc(sizeof(invader));
  new_invader->x = x;
  new_invader->y = y;
  new_invader->direction = 'H';
  new_invader->next = NULL;
  return new_invader;
}

void draw_invaders(invader* head) {
  invader* current = head;
  while (current) {
    printf("%c", current->x + 1);
    printf("%c", current->y + 1);
    printf(" ");
  }
  printf("\n");
}

void move_invaders(invader* head) {
  invader* current = head;
  switch (current->direction) {
    case 'H':
      current->x++;
      break;
    case 'V':
      current->y++;
      break;
    case 'L':
      current->x--;
      break;
    case 'U':
      current->y--;
      break;
  }

  if (current->x < LEFT_BOUND) {
    current->direction = 'R';
  } else if (current->x > RIGHT_BOUND) {
    current->direction = 'L';
  }

  if (current->y < TOP_BOUND) {
    current->direction = 'U';
  } else if (current->y > BOTTOM_BOUND) {
    current->direction = 'V';
  }
}

int main() {
  invader* head = create_invader(0, 0);
  draw_invaders(head);
  move_invaders(head);
  draw_invaders(head);
  return 0;
}