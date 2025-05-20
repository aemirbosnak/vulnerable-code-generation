//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 20
#define MAX_HEIGHT 10

typedef struct invaders_s {
  int x, y, direction, speed;
  struct invaders_s* next;
} invaders_t;

void draw_invaders(invaders_t* head) {
  invaders_t* current = head;
  while (current) {
    printf("%c", current->x + 1);
    printf("%c", current->y + 1);
    printf(" ");
  }
  printf("\n");
}

void move_invaders(invaders_t* head) {
  invaders_t* current = head;
  switch (head->direction) {
    case 0:
      current->x++;
      break;
    case 1:
      current->x--;
      break;
    case 2:
      current->y++;
      break;
    case 3:
      current->y--;
      break;
  }

  if (current->x >= MAX_WIDTH - 1) {
    current->direction = 1;
  } else if (current->x <= 0) {
    current->direction = 0;
  }

  if (current->y >= MAX_HEIGHT - 1) {
    current->direction = 3;
  } else if (current->y <= 0) {
    current->direction = 2;
  }
}

int main() {
  invaders_t* head = malloc(sizeof(invaders_t));
  head->x = 0;
  head->y = 0;
  head->direction = 0;
  head->speed = 1;
  head->next = NULL;

  draw_invaders(head);

  for (int i = 0; i < 100; i++) {
    move_invaders(head);
    draw_invaders(head);
  }

  return 0;
}