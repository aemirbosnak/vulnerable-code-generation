//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

#define invader_SIZE 5

typedef struct invader {
  int x;
  int y;
  int direction;
  struct invader* next;
} invader;

invader* invader_create() {
  invader* new_invader = malloc(sizeof(invader));
  new_invader->x = 0;
  new_invader->y = 0;
  new_invader->direction = 1;
  new_invader->next = NULL;
  return new_invader;
}

void invader_move(invader* current) {
  switch (current->direction) {
    case 1:
      current->x++;
      break;
    case 2:
      current->x--;
      break;
    case 3:
      current->y++;
      break;
    case 4:
      current->y--;
      break;
  }

  if (current->x >= WIDTH - 1) {
    current->direction = 2;
  } else if (current->x <= 0) {
    current->direction = 1;
  }

  if (current->y >= HEIGHT - 1) {
    current->direction = 4;
  } else if (current->y <= 0) {
    current->direction = 3;
  }
}

int main() {
  invader* head = invader_create();
  invader* tail = head;

  for (int i = 0; i < invader_SIZE; i++) {
    tail = invader_create();
    tail->next = head;
    head = tail;
  }

  int score = 0;

  time_t start_time = time(NULL);

  while (!head->next) {
    invader_move(head);
    printf("Invader position: (%d, %d)\n", head->x, head->y);
    sleep(1);
  }

  time_t end_time = time(NULL);

  score = (end_time - start_time) * 10;

  printf("Your score: %d\n", score);

  return 0;
}