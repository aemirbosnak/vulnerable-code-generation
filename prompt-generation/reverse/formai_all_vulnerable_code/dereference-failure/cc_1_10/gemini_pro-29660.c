//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

typedef struct PercolationLattice {
  unsigned short int **lattice;
  unsigned int size;
  unsigned int openSites;
  float threshold;
} PercolationLattice;

void initialise(PercolationLattice *lattice, unsigned int size, float threshold) {
  lattice->size = size;
  lattice->openSites = 0;
  lattice->threshold = threshold;
  lattice->lattice = (unsigned short int **) malloc(sizeof(unsigned short int *) * size);
  for (unsigned int row = 0; row < size; row++) {
    lattice->lattice[row] = (unsigned short int *) malloc(sizeof(unsigned short int) * size);
    memset(lattice->lattice[row], 0, sizeof(unsigned short int) * size);
  }
}

void display(PercolationLattice *lattice) {
  printf("\n");
  for (unsigned int row = 0; row < lattice->size; row++) {
    for (unsigned int col = 0; col < lattice->size; col++) {
      switch (lattice->lattice[row][col]) {
        case 0:
          printf("░░");
          break;
        case 1:
          printf("░░");
          break;
        case 2:
          printf("░░");
          break;
        case 3:
          printf("▒▒");
          break;
        case 4:
          printf("▓▓");
          break;
        case 5:
          printf("██");
          break;
        default:
          printf("  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

unsigned int isOpen(PercolationLattice *lattice, unsigned int row, unsigned int col) {
  if (row >= lattice->size || col >= lattice->size) return 0;
  return lattice->lattice[row][col];
}

void openSite(PercolationLattice *lattice, unsigned int row, unsigned int col) {
  if (isOpen(lattice, row, col)) return;
  lattice->lattice[row][col] = 1;
  lattice->openSites++;
}

void dfs(PercolationLattice *lattice, unsigned int row, unsigned int col, unsigned short int state) {
  if (isOpen(lattice, row, col)) return;
  lattice->lattice[row][col] = state;
  if (row > 0) dfs(lattice, row - 1, col, state);
  if (row < lattice->size - 1) dfs(lattice, row + 1, col, state);
  if (col > 0) dfs(lattice, row, col - 1, state);
  if (col < lattice->size - 1) dfs(lattice, row, col + 1, state);
}

void markClusters(PercolationLattice *lattice) {
  unsigned short int state = 2;
  for (unsigned int row = 0; row < lattice->size; row++) {
    for (unsigned int col = 0; col < lattice->size; col++) {
      if (isOpen(lattice, row, col) && lattice->lattice[row][col] == 1) {
        dfs(lattice, row, col, state);
        state++;
      }
    }
  }
}

void calculatePercolation(PercolationLattice *lattice) {
  for (unsigned int row = 0; row < lattice->size; row++) {
    if (lattice->lattice[row][0] >= 2) {
      dfs(lattice, row, 0, 4);
    }
    if (lattice->lattice[row][lattice->size - 1] >= 2) {
      dfs(lattice, row, lattice->size - 1, 5);
    }
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  PercolationLattice lattice;
  unsigned int size = 100;
  float threshold = 0.4;
  initialise(&lattice, size, threshold);
  for (unsigned int site = 0; site < size * size * threshold; site++) {
    unsigned int row = rand() % size;
    unsigned int col = rand() % size;
    openSite(&lattice, row, col);
  }
  markClusters(&lattice);
  calculatePercolation(&lattice);
  display(&lattice);
  return 0;
}