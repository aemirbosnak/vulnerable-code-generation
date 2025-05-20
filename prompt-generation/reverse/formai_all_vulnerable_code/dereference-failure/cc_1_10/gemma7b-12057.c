//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
  int x;
  int y;
  int direction;
  struct Pacman* next;
} Pacman;

Pacman* head = NULL;

void initPacman() {
  head = malloc(sizeof(Pacman));
  head->x = MAP_SIZE / 2;
  head->y = MAP_SIZE - 1;
  head->direction = 0;
  head->next = NULL;
}

void movePacman() {
  switch (head->direction) {
    case 0:
      head->x++;
      break;
    case 1:
      head->y--;
      break;
    case 2:
      head->x--;
      break;
    case 3:
      head->y++;
      break;
  }

  if (head->x < 0) {
    head->direction = 2;
  } else if (head->x >= MAP_SIZE - 1) {
    head->direction = 0;
  }

  if (head->y < 0) {
    head->direction = 3;
  } else if (head->y >= MAP_SIZE - 1) {
    head->direction = 1;
  }
}

void drawPacman() {
  for (Pacman* current = head; current; current = current->next) {
    printf("o");
  }
  printf("\n");
}

int main() {
  initPacman();

  for (int i = 0; i < 100; i++) {
    movePacman();
    drawPacman();
    sleep(0.1);
  }

  return 0;
}