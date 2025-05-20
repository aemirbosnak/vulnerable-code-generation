//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 20

void draw_map(int **map) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c ", map[y][x] ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  int **map = NULL;
  map = (int **)malloc(HEIGHT * sizeof(int *));
  for (int y = 0; y < HEIGHT; y++) {
    map[y] = (int *)malloc(WIDTH * sizeof(int));
  }

  // Map initialization
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = 0;
    }
  }

  // Player position
  int px = 0, py = 0;

  // Game loop
  while (!map[py][px]) {
    draw_map(map);

    // Move the player
    int dx = 0, dy = 0;
    printf("Enter direction (h/w/a/s): ");
    char dir = getchar();

    switch (dir) {
      case 'h':
        dx = -1;
        break;
      case 'w':
        dy = 1;
        break;
      case 'a':
        dx = 1;
        break;
      case 's':
        dy = -1;
        break;
    }

    // Boundary checks
    if (px + dx < 0 || px + dx >= WIDTH) {
      dx = 0;
    }
    if (py + dy < 0 || py + dy >= HEIGHT) {
      dy = 0;
    }

    // Dig the block
    map[py][px] = 1;

    // Update player position
    px += dx;
    py += dy;
  }

  draw_map(map);
  printf("Congratulations! You won!");

  free(map);
  return 0;
}