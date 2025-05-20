//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

#define LEFT_BOUND 0
#define RIGHT_BOUND WIDTH - 1

typedef struct invader_s {
  int x, y;
  struct invader_s* next;
} invader_t;

invader_t* invader_create() {
  invader_t* invader = malloc(sizeof(invader_t));
  invader->x = rand() % WIDTH;
  invader->y = 0;
  invader->next = NULL;
  return invader;
}

void invader_move(invader_t* invader) {
  if (invader->x < LEFT_BOUND) {
    invader->x = LEFT_BOUND;
  } else if (invader->x > RIGHT_BOUND) {
    invader->x = RIGHT_BOUND;
  }
  invader->y++;
}

int main() {
  srand(time(NULL));

  invader_t* head = invader_create();

  while (1) {
    invader_move(head);

    // Draw the invaders
    for (invader_t* invader = head; invader; invader = invader->next) {
      printf("%c", '*');
    }

    printf("\n");

    // Check if the invaders have reached the bottom
    if (head->y == HEIGHT - 1) {
      printf("Game over!");
      break;
    }
  }

  return 0;
}