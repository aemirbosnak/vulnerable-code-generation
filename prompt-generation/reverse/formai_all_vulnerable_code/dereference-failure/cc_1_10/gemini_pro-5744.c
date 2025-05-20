//GEMINI-pro DATASET v1.0 Category: Sudoku solver ; Style: paranoid
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

typedef struct {
  int v[N];
  int n;
} stack;

typedef struct {
  int g[N][N];
  int m[N][N];
  stack s[N * N];
  int sp;
} sudoku;

int sudoku_init(sudoku *s, int **g) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      s->g[i][j] = g[i][j];
      if (g[i][j] != 0) {
        s->m[i][j] = 1;
      } else {
        s->m[i][j] = 0;
      }
    }
  }
  s->sp = 0;
  return 0;
}

int sudoku_push(sudoku *s, int x, int y) {
  if (s->sp >= N * N) {
    return -1;
  }
  s->s[s->sp].v[0] = x;
  s->s[s->sp].v[1] = y;
  s->s[s->sp].n = 1;
  s->sp++;
  return 0;
}

int sudoku_pop(sudoku *s, int *x, int *y) {
  if (s->sp <= 0) {
    return -1;
  }
  s->sp--;
  *x = s->s[s->sp].v[0];
  *y = s->s[s->sp].v[1];
  return 0;
}

int sudoku_next(sudoku *s, int *x, int *y) {
  if (s->sp <= 0) {
    return -1;
  }
  int n = s->s[s->sp - 1].n;
  int *v = s->s[s->sp - 1].v;
  if (n >= N) {
    if (sudoku_pop(s, x, y) != 0) {
      return -1;
    }
    return sudoku_next(s, x, y);
  }
  v[n] = s->g[*x][*y];
  s->s[s->sp - 1].n++;
  return 0;
}

int sudoku_valid(sudoku *s, int x, int y, int v) {
  for (int i = 0; i < N; i++) {
    if (s->g[x][i] == v || s->g[i][y] == v) {
      return 0;
    }
  }
  int sx = (x / 3) * 3;
  int sy = (y / 3) * 3;
  for (int i = sx; i < sx + 3; i++) {
    for (int j = sy; j < sy + 3; j++) {
      if (s->g[i][j] == v) {
        return 0;
      }
    }
  }
  return 1;
}

int sudoku_solve(sudoku *s) {
  int x, y;
  while (sudoku_next(s, &x, &y) == 0) {
    if (s->m[x][y] == 1) {
      continue;
    }
    int v = s->s[s->sp - 1].v[s->s[s->sp - 1].n];
    if (sudoku_valid(s, x, y, v) == 0) {
      continue;
    }
    s->g[x][y] = v;
    s->m[x][y] = 1;
    if (sudoku_push(s, x, y) != 0) {
      return -1;
    }
  }
  return 0;
}

int sudoku_print(sudoku *s) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", s->g[i][j]);
    }
    printf("\n");
  }
  return 0;
}

int main(int argc, char **argv) {
  int **g = malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++) {
    g[i] = malloc(N * sizeof(int));
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      g[i][j] = 0;
    }
  }
  sudoku s;
  sudoku_init(&s, g);
  sudoku_solve(&s);
  sudoku_print(&s);
  return 0;
}