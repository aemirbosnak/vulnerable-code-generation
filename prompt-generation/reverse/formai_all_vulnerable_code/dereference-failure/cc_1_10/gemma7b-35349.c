//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 25

typedef struct invader {
  int x, y, direction, speed;
  struct invader *next;
} invader_t;

invader_t *create_invader(int x, int y) {
  invader_t *invader = malloc(sizeof(invader_t));
  invader->x = x;
  invader->y = y;
  invader->direction = rand() % 2;
  invader->speed = rand() % 3 + 1;
  invader->next = NULL;
  return invader;
}

void move_invaders(invader_t *invaders) {
  for (invader_t *invader = invaders; invader; invader = invader->next) {
    switch (invader->direction) {
      case 0:
        invader->x++;
        break;
      case 1:
        invader->x--;
        break;
    }
    invader->y++;
  }
}

void draw_invaders(invader_t *invaders) {
  for (invader_t *invader = invaders; invader; invader = invader->next) {
    printf(" ");
    for (int i = 0; i < invader->speed; i++) {
      printf("=");
    }
    printf("o");
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  invader_t *invaders = create_invader(0, 0);
  invaders = create_invader(MAX_WIDTH - 1, 0);

  while (1) {
    move_invaders(invaders);
    draw_invaders(invaders);
    if (invaders->y == MAX_HEIGHT - 1) {
      printf("Game Over!\n");
      break;
    }
    sleep(1);
  }

  return 0;
}