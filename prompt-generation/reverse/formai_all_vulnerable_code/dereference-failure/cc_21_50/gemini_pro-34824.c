//GEMINI-pro DATASET v1.0 Category: Breakout Game Clone ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24

int main() {
  char *f;
  if (!(f = calloc(WIDTH * HEIGHT, sizeof(char)))) return 1;

  char *dir;
  if (!(dir = malloc(2))) return 2;
  *dir = 1;

  int x = WIDTH / 2;
  int y = HEIGHT - 1;

  *f = 1;

  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  int p;

  while (1) {
    char in[2];
    in[0] = getchar();
    if (in[0] == -1) in[0] = in[1];
    in[1] = getchar();
    if (in[0] == 'q') break;
    if (in[0] == 'r') {
      *f = 1;
      x = WIDTH / 2;
      y = HEIGHT - 1;
      continue;
    }
    if (in[0] == 'l' || in[0] == 'h')
      *dir = (*dir + 3) % 4;
    else if (in[0] == 'j')
      *dir = (*dir + 1) % 4;

    int nx = x + dx[*dir];
    int ny = y + dy[*dir];

    if (in[1] && in[1] == '\n') {
      p = nx + ny * WIDTH;
      if (f[p]) {
        f[p] = 0;
        if (!*f) {
          puts("Victory!");
          break;
        }
      }
    }

    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
      if (f[p = nx + ny * WIDTH] == 1) {
        dir[0] = (dir[0] + 2) % 4;
      }

      if (p != x + y * WIDTH) {
        x = nx;
        y = ny;
      }
    }

    int i;
    for (i = 0; i < WIDTH * HEIGHT; i++) {
      putchar(f[i] ? '#' : '.');
      if (i % WIDTH == WIDTH - 1) putchar('\n');
    }
    putchar('\n');
  }

  free(f);
  free(dir);

  return 0;
}