//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 5
#define UP_BOUND 0
#define DOWN_BOUND 3

typedef struct invaders_s {
  int x;
  int y;
  int direction;
  struct invaders_s* next;
} invaders_t;

void initialize_invaders(invaders_t** head) {
  *head = malloc(sizeof(invaders_t));
  (*head)->x = RIGHT_BOUND;
  (*head)->y = UP_BOUND;
  (*head)->direction = 1;
  (*head)->next = NULL;
}

void move_invaders(invaders_t* head) {
  switch (head->direction) {
    case 1:
      head->x++;
      break;
    case 2:
      head->x--;
      break;
    case 3:
      head->y++;
      break;
    case 4:
      head->y--;
      break;
  }

  if (head->x == LEFT_BOUND || head->x == RIGHT_BOUND) {
    head->direction *= -1;
  }

  if (head->y == UP_BOUND || head->y == DOWN_BOUND) {
    head->direction *= -1;
  }
}

void draw_invaders(invaders_t* head) {
  system("clear");
  for (invaders_t* current = head; current; current = current->next) {
    printf("%c", current->x + 1);
  }
  printf("\n");
}

int main() {
  invaders_t* head = NULL;
  initialize_invaders(&head);

  for (int i = 0; i < 10; i++) {
    move_invaders(head);
    draw_invaders(head);
    sleep(1);
  }

  return 0;
}