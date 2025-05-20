//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  point pos;
  int hp;
  int atk;
  int def;
} character;

typedef struct {
  char **grid;
  int width;
  int height;
} world;

world *create_world(int width, int height) {
  world *w = malloc(sizeof(world));
  w->width = width;
  w->height = height;
  w->grid = malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    w->grid[i] = malloc(sizeof(char) * width);
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      w->grid[i][j] = '.';
    }
  }
  return w;
}

void free_world(world *w) {
  for (int i = 0; i < w->height; i++) {
    free(w->grid[i]);
  }
  free(w->grid);
  free(w);
}

void draw_world(world *w) {
  for (int i = 0; i < w->height; i++) {
    for (int j = 0; j < w->width; j++) {
      printf("%c", w->grid[i][j]);
    }
    printf("\n");
  }
}

character *create_character(int x, int y) {
  character *c = malloc(sizeof(character));
  c->pos.x = x;
  c->pos.y = y;
  c->hp = 100;
  c->atk = 10;
  c->def = 10;
  return c;
}

void free_character(character *c) {
  free(c);
}

void update_world(world *w, character *c) {
  w->grid[c->pos.y][c->pos.x] = '@';
}

void move_character(world *w, character *c, int dx, int dy) {
  if (c->pos.x + dx < 0 || c->pos.x + dx >= w->width || c->pos.y + dy < 0 ||
      c->pos.y + dy >= w->height) {
    return;
  }
  w->grid[c->pos.y][c->pos.x] = '.';
  c->pos.x += dx;
  c->pos.y += dy;
  update_world(w, c);
}

int main() {
  srand(time(NULL));
  world *w = create_world(80, 24);
  character *c = create_character(w->width / 2, w->height / 2);
  update_world(w, c);
  draw_world(w);
  while (1) {
    char input = getchar();
    switch (input) {
      case 'w':
        move_character(w, c, 0, -1);
        break;
      case 'a':
        move_character(w, c, -1, 0);
        break;
      case 's':
        move_character(w, c, 0, 1);
        break;
      case 'd':
        move_character(w, c, 1, 0);
        break;
      case 'q':
        free_world(w);
        free_character(c);
        return 0;
    }
    draw_world(w);
  }
  return 0;
}