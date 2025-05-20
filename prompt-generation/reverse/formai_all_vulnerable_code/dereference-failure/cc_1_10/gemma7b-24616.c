//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct invader {
  int x;
  int y;
  int direction;
  struct invader* next;
} invader;

invader* head = NULL;

void initialize() {
  head = (invader*)malloc(sizeof(invader));
  head->x = WIDTH / 2;
  head->y = HEIGHT - 1;
  head->direction = 1;
  head->next = NULL;
}

void move() {
  invader* current = head;
  while (current) {
    switch (current->direction) {
      case 1:
        current->x++;
        break;
      case 2:
        current->x--;
        break;
      case 3:
        current->y--;
        break;
      case 4:
        current->y++;
        break;
    }

    if (current->x > WIDTH - 1) {
      current->direction = 2;
    } else if (current->x < 0) {
      current->direction = 1;
    }

    if (current->y < 0) {
      current->direction = 4;
    } else if (current->y > HEIGHT - 1) {
      current->direction = 3;
    }

    current = current->next;
  }
}

void draw() {
  system("cls");
  invader* current = head;
  while (current) {
    switch (current->direction) {
      case 1:
        printf("-> ");
        break;
      case 2:
        printf("<- ");
        break;
      case 3:
        printf("^ ");
        break;
      case 4:
        printf("V ");
        break;
    }

    current = current->next;
  }
  printf("\n");
}

int main() {
  initialize();

  for (int i = 0; i < 100; i++) {
    move();
    draw();
  }

  return 0;
}