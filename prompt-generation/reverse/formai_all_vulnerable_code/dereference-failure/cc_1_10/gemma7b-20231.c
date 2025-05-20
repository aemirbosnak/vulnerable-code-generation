//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define PAC_SIZE 5

typedef struct Pacman {
  int x, y;
  int dir;
  int speed;
  struct Pacman* next;
} Pacman;

Pacman* createPacman() {
  Pacman* p = (Pacman*)malloc(sizeof(Pacman));
  p->x = MAP_SIZE / 2;
  p->y = MAP_SIZE - 1;
  p->dir = 0;
  p->speed = 1;
  p->next = NULL;
  return p;
}

void movePacman(Pacman* p) {
  switch (p->dir) {
    case 0:
      p->x--;
      break;
    case 1:
      p->y--;
      break;
    case 2:
      p->x++;
      break;
    case 3:
      p->y++;
      break;
  }
}

void drawPacman(Pacman* p) {
  printf("(");
  for (int y = p->y; y < MAP_SIZE; y++) {
    for (int x = p->x; x < MAP_SIZE; x++) {
      if (x == p->x && y == p->y) {
        printf("o");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf(")\n");
}

void playPacman(Pacman* p) {
  movePacman(p);
  drawPacman(p);
  if (p->next) {
    playPacman(p->next);
  }
}

int main() {
  Pacman* p = createPacman();
  playPacman(p);
  return 0;
}