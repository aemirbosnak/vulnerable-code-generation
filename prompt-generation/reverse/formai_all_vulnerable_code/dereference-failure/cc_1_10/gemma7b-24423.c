//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct invaders {
  int x, y;
  struct invaders* next;
} invaders;

invaders* create_invaders() {
  invaders* head = malloc(sizeof(invaders));
  head->x = WIDTH / 2;
  head->y = HEIGHT - 1;
  head->next = NULL;
  return head;
}

void move_invaders(invaders* head) {
  time_t t = time(NULL);
  int dx = 1;
  int dy = 0;

  if (t % 2 == 0) {
    dx = -dx;
  }

  head->x += dx;
  head->y -= dy;

  if (head->x < 0) {
    head->x = 0;
  } else if (head->x >= WIDTH - 1) {
    head->x = WIDTH - 1;
  }

  if (head->y < 0) {
    head->y = 0;
  }
}

void draw_invaders(invaders* head) {
  for (invaders* current = head; current; current = current->next) {
    printf("o ");
  }
  printf("\n");
}

int main() {
  invaders* head = create_invaders();

  while (1) {
    move_invaders(head);
    draw_invaders(head);

    if (head->y >= HEIGHT - 1) {
      printf("Game Over!\n");
      break;
    }
  }

  return 0;
}