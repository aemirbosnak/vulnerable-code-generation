//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PAC_SIZE 4
#define DOT_SIZE 2

typedef struct Pacman {
  int x;
  int y;
  int direction;
  struct Pacman* next;
} Pacman;

Pacman* pacman_init() {
  Pacman* p = malloc(sizeof(Pacman));
  p->x = MAP_SIZE / 2;
  p->y = MAP_SIZE / 2;
  p->direction = 0;
  p->next = NULL;
  return p;
}

void pacman_move(Pacman* p) {
  switch (p->direction) {
    case 0:
      p->x++;
      break;
    case 1:
      p->y++;
      break;
    case 2:
      p->x--;
      break;
    case 3:
      p->y--;
      break;
  }
}

void draw_map(Pacman* p) {
  for (int y = 0; y < MAP_SIZE; y++) {
    for (int x = 0; x < MAP_SIZE; x++) {
      if (x == p->x && y == p->y) {
        printf("O");
      } else if (rand() % DOT_SIZE == 0) {
        printf(".");
      } else {
        printf("#");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  Pacman* p = pacman_init();

  while (1) {
    pacman_move(p);
    draw_map(p);

    if (p->x == MAP_SIZE - 1) {
      p->direction = 3;
    } else if (p->x == 0) {
      p->direction = 2;
    } else if (p->y == MAP_SIZE - 1) {
      p->direction = 0;
    } else if (p->y == 0) {
      p->direction = 1;
    }
  }

  return 0;
}