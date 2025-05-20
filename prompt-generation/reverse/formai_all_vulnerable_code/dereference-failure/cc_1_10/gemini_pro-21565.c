//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FORV(i, n) for (size_t i = 0; i < (n); ++i)
#define FORVP(i, p) for (size_t i = 0; p[i] != 0; ++i)
#define SAFE_REALLOC(ptr, nmemb, size) ptr = realloc(ptr, (nmemb) * (size));
#define FREE_IF(ptr) if (ptr) { free(ptr); }

typedef struct {
  size_t width, height;
  bool *cells;
} grid_t;

static inline bool get(const grid_t *g, size_t x, size_t y) {
  return g->cells[y * g->width + x];
}

static inline void set(grid_t *g, size_t x, size_t y, bool v) {
  g->cells[y * g->width + x] = v;
}

static void init(grid_t *g, size_t width, size_t height, float density) {
  g->width = width;
  g->height = height;
  g->cells = malloc(sizeof(bool) * width * height);
  srand(time(NULL));
  FORV(i, width * height) g->cells[i] = rand() < RAND_MAX * density;
}

static void free_grid(grid_t *g) { FREE_IF(g->cells); }

static void render(const grid_t *g, FILE *fp) {
  FORV(y, g->height) {
    FORV(x, g->width) fprintf(fp, "%s", get(g, x, y) ? "#" : " ");
    fprintf(fp, "\n");
  }
}

static size_t count_neighbors(const grid_t *g, size_t x, size_t y) {
  size_t sum = 0;
  for (size_t dx = -1; dx <= 1; ++dx)
    for (size_t dy = -1; dy <= 1; ++dy)
      if (!dx && !dy)
        continue;
      else if (x + dx < 0 || y + dy < 0 || x + dx >= g->width || y + dy >= g->height)
        sum += get(g, x + dx, y + dy);
  return sum;
}

static void update(grid_t *g) {
  bool *prev = g->cells;
  size_t n = g->width * g->height;
  SAFE_REALLOC(g->cells, n, sizeof(bool));
  FORV(i, n) {
    size_t c = count_neighbors(g, i % g->width, i / g->width);
    switch (c) {
      case 2:
        g->cells[i] = prev[i];
        break;
      case 3:
        g->cells[i] = true;
        break;
      default:
        g->cells[i] = false;
    }
  }
  free(prev);
}

int main(void) {
  grid_t g;
  init(&g, 100, 50, 0.5);
  FORV(i, 100) {
    render(&g, stdout);
    update(&g);
  }
  free_grid(&g);
  return 0;
}