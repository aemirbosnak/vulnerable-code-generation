//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40

typedef struct invader {
  int x, y;
  char direction;
  struct invader* next;
} invader;

void draw_invaders(invader* head) {
  invader* current = head;
  while (current) {
    printf(" ");
    for (int i = 0; i < current->x; i++) {
      printf("=");
    }
    printf("%c ", current->direction);
    for (int i = 0; i < current->y; i++) {
      printf("=");
    }
    printf("\n");
    current = current->next;
  }
}

int main() {
  invader* head = NULL;
  head = malloc(sizeof(invader));
  head->x = 0;
  head->y = 0;
  head->direction = 'r';
  head->next = NULL;

  invader* second = malloc(sizeof(invader));
  second->x = 1;
  second->y = 0;
  second->direction = 'r';
  second->next = NULL;

  invader* third = malloc(sizeof(invader));
  third->x = 2;
  third->y = 0;
  third->direction = 'r';
  third->next = NULL;

  head->next = second;
  second->next = third;

  draw_invaders(head);

  return 0;
}