//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct invader_t {
  int x;
  int y;
  struct invader_t* next;
} invader_t;

invader_t* invaders_head = NULL;

void init_invaders() {
  invader_t* new_invader = malloc(sizeof(invader_t));
  new_invader->x = WIDTH / 2;
  new_invader->y = HEIGHT - 1;
  new_invader->next = NULL;

  if (invaders_head == NULL) {
    invaders_head = new_invader;
  } else {
    invaders_head->next = new_invader;
  }
}

void move_invaders() {
  invader_t* current_invader = invaders_head;

  while (current_invader) {
    current_invader->x++;

    if (current_invader->x == WIDTH) {
      current_invader->y--;
      current_invader->x = WIDTH / 2;
    }

    current_invader = current_invader->next;
  }
}

int main() {
  init_invaders();

  for (int i = 0; i < 10; i++) {
    move_invaders();
  }

  return 0;
}