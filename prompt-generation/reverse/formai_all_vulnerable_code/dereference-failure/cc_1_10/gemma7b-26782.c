//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: medieval
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define MAX_WATER 10

typedef struct Warrior {
  int x, y;
  int water;
  char state;
} Warrior;

void simulate_percolation(Warrior **warriors) {
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      if (warriors[i][j].water > MAX_WATER) {
        warriors[i][j].state = 'S';
      } else {
        warriors[i][j].state = 'H';
      }
    }
  }
}

int main() {
  Warrior **warriors = (Warrior**)malloc(WIDTH * HEIGHT * sizeof(Warrior));
  for (int i = 0; i < WIDTH * HEIGHT; i++) {
    warriors[i] = (Warrior*)malloc(sizeof(Warrior));
    warriors[i]->x = -1;
    warriors[i]->y = -1;
    warriors[i]->water = 0;
    warriors[i]->state = 'N';
  }

  // Fill the warriors with water
  warriors[0][0].water = MAX_WATER;
  warriors[1][0].water = MAX_WATER;
  warriors[2][0].water = MAX_WATER;

  simulate_percolation(warriors);

  // Print the results
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < HEIGHT; j++) {
      printf("%c ", warriors[i][j].state);
    }
    printf("\n");
  }

  free(warriors);

  return 0;
}