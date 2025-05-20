//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
  int x, y;
  int direction;
  char **map;
} Pacman;

Pacman createPacman() {
  Pacman pacman;
  pacman.x = 0;
  pacman.y = 0;
  pacman.direction = 0;
  pacman.map = (char**)malloc(MAP_SIZE * sizeof(char*));
  for (int i = 0; i < MAP_SIZE; i++) {
    pacman.map[i] = (char*)malloc(MAP_SIZE * sizeof(char));
  }
  return pacman;
}

void movePacman(Pacman *pacman) {
  switch (pacman->direction) {
    case 0:
      pacman->x++;
      break;
    case 1:
      pacman->y++;
      break;
    case 2:
      pacman->x--;
      break;
    case 3:
      pacman->y--;
      break;
  }

  if (pacman->map[pacman->x][pacman->y] == '#') {
    pacman->direction = (pacman->direction + 1) % 4;
  }
}

void drawPacman(Pacman *pacman) {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (pacman->map[i][j] == 'p') {
        printf("%c ", pacman->map[i][j]);
      } else {
        printf("%c ", pacman->map[i][j]);
      }
    }
    printf("\n");
  }
}

int main() {
  Pacman pacman = createPacman();

  for (int i = 0; i < 10; i++) {
    movePacman(&pacman);
    drawPacman(&pacman);
    sleep(1);
  }

  return 0;
}