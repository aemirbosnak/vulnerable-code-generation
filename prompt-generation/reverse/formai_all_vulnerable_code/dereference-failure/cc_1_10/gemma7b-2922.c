//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

#define LEFT 0
#define RIGHT 49

typedef struct invader {
  int x, y;
  char direction;
  struct invader* next;
} invader;

invader** create_invaders() {
  invader** head = malloc(sizeof(invader*) * WIDTH);
  for (int i = 0; i < WIDTH; i++) {
    head[i] = malloc(sizeof(invader));
    head[i]->x = i;
    head[i]->y = HEIGHT - 1;
    head[i]->direction = 'a';
    head[i]->next = NULL;
  }
  return head;
}

void draw_invaders(invader** head) {
  for (invader* invader = head[0]; invader; invader = invader->next) {
    printf("%c ", invader->x + 1, invader->y + 1);
  }
  printf("\n");
}

void move_invaders(invader** head) {
  time_t t = time(NULL);
  if (time(NULL) - t >= 0.5) {
    for (invader* invader = head[0]; invader; invader = invader->next) {
      switch (invader->direction) {
        case 'a':
          invader->x--;
          break;
        case 'd':
          invader->x++;
          break;
        case 'u':
          invader->y--;
          break;
        case 'b':
          invader->y++;
          break;
      }
      if (invader->x < LEFT || invader->x > RIGHT) {
        invader->direction = 'u';
      }
    }
    t = time(NULL);
  }
}

int main() {
  invader** invaders = create_invaders();
  draw_invaders(invaders);

  while (!invaders[0]->direction == 'b') {
    move_invaders(invaders);
    draw_invaders(invaders);
  }

  return 0;
}