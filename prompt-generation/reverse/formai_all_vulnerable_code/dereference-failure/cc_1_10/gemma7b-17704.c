//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef struct invader {
  int x;
  int y;
  int dir;
  struct invader* next;
} invader;

invader* create_invader() {
  invader* new_invader = malloc(sizeof(invader));
  new_invader->x = 0;
  new_invader->y = 0;
  new_invader->dir = 1;
  new_invader->next = NULL;
  return new_invader;
}

void draw_map(int** map) {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      printf("%c ", map[y][x]);
    }
    printf("\n");
  }
}

void move_invaders(invader* head) {
  while (head) {
    switch (head->dir) {
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

    if (head->x == MAP_WIDTH - 1) {
      head->dir = 2;
    } else if (head->x == 0) {
      head->dir = 1;
    }

    if (head->y == MAP_HEIGHT - 1) {
      head->dir = 4;
    } else if (head->y == 0) {
      head->dir = 3;
    }

    head = head->next;
  }
}

int main() {
  int** map = malloc(MAP_HEIGHT * sizeof(int*));
  for (int i = 0; i < MAP_HEIGHT; i++) {
    map[i] = malloc(MAP_WIDTH * sizeof(int));
  }

  invader* head = create_invader();
  head->next = create_invader();
  head->next->next = create_invader();

  while (!head->next) {
    move_invaders(head);
    draw_map(map);
    sleep(1);
  }

  return 0;
}