//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Percolation {
  int **grid;
  int size;
  int num_sites;
} Percolation;

Percolation* percol_new(int size) {
  Percolation* p = malloc(sizeof(Percolation));
  p->size = size;
  p->num_sites = size * size;
  p->grid = malloc(p->num_sites * sizeof(int));
  for (int i = 0; i < p->num_sites; i++) {
    p->grid[i] = 0;
  }
  return p;
}

void percol_set(Percolation* p, int site, int value) {
  p->grid[site] = value;
}

int percol_get(Percolation* p, int site) {
  return p->grid[site];
}

int percol_num_sites(Percolation* p) {
  return p->num_sites;
}

void percol_destroy(Percolation* p) {
  free(p->grid);
  free(p);
}

int main() {
  Percolation* p = percol_new(5);
  percol_set(p, 10, 1);
  percol_set(p, 15, 1);
  percol_set(p, 20, 1);
  percol_set(p, 25, 1);
  int num_sites = percol_num_sites(p);
  for (int i = 0; i < num_sites; i++) {
    printf("%d ", percol_get(p, i));
  }
  percol_destroy(p);
  return 0;
}