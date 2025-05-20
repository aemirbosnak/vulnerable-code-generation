//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>

#define MAX_N 100
#define MAX_COLORS 10
#define MAX_TRIES 10000

int n, m, num_colors, best_score, best_colors[MAX_N];

struct edge {
  int u, v;
} edges[MAX_N * MAX_N];

void read_graph() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &edges[i].u, &edges[i].v);
  }
}

int try_coloring(int colors[MAX_N]) {
  int score = 0;
  for (int i = 0; i < m; i++) {
    if (colors[edges[i].u] == colors[edges[i].v]) {
      score++;
    }
  }
  return score;
}

void color_graph() {
  for (int i = 0; i < num_colors; i++) {
    for (int j = 0; j < n; j++) {
      if (best_colors[j] == i) {
        printf("%d ", j + 1);
      }
    }
  }
  printf("\n");
}

int main() {
  read_graph();
  scanf("%d", &num_colors);
  int colors[MAX_N];
  best_score = INT_MAX;
  for (int i = 0; i < MAX_TRIES; i++) {
    for (int j = 0; j < n; j++) {
      colors[j] = rand() % num_colors;
    }
    int score = try_coloring(colors);
    if (score < best_score) {
      best_score = score;
      memcpy(best_colors, colors, sizeof(colors));
    }
  }
  color_graph();
  return 0;
}