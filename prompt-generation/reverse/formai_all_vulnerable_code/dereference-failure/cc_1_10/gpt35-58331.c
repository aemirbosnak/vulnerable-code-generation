//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
/*
  C Percolation Simulator
  This program simulates percolation in a given system of cells.
  Each cell has an equal probability of being opened or closed.
  The program keeps on trying to open cells until the system percolates.

  Author: [Your Name]
*/

// Essential header files

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize a given N x N system

void initialize(int *system, int n) {
  srand(time(0)); // to get random number sequence every time

  int i, j;

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      *(system + i*n + j) = rand() % 2;  // random cell value (0 or 1)
    }
  }
}

// Function to print the system

void print_system(int *system, int n) {
  int i, j;

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      printf("%d ", *(system + i*n + j));
    }
    printf("\n");
  }
}

// Function to check if the system percolates

int percolates(int *system, int n) {
  int i, j;

  // Create two dummy nodes, top and bottom, and check if they are connected
  int top = n*n, bottom = n*n + 1;

  // Create disjoint set and initialize with dummy nodes
  int *set = (int *) malloc((n*n + 2) * sizeof(int));

  for(i = 0; i < n*n; i++) {
    *(set + i) = i;
  }

  *(set + top) = top;
  *(set + bottom) = bottom;

  for(i = 0; i < n; i++) {
    if(*system == 0) {
      *(set + i) = top;
    }
    if(*(system + (n-1)*n + i) == 0) {
      *(set + (n-1)*n + i) = bottom;
    }
  }

  // Union-find algorithm to keep on connecting adjacent cells
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      if(*(system + i*n + j) == 0) { // connect adjacent open cells
        if(i > 0 && *(system + (i-1)*n + j) == 0) { // connect top cell
          int p = i*n + j;
          int q = (i-1)*n + j;
          while(p != *(set + p)) {
            *(set + p) = *(set + *(set + p)); // path compression
            p = *(set + p);
          }
          while(q != *(set + q)) {
            *(set + q) = *(set + *(set + q)); // path compression
            q = *(set + q);
          }
          if(p != q) { // connect
            *(set + p) = q;
          }
        }
        if(j > 0 && *(system + i*n + j-1) == 0) { // connect left cell
          int p = i*n + j;
          int q = i*n + j-1;
          while(p != *(set + p)) {
            *(set + p) = *(set + *(set + p)); // path compression
            p = *(set + p);
          }
          while(q != *(set + q)) {
            *(set + q) = *(set + *(set + q)); // path compression
            q = *(set + q);
          }
          if(p != q) { // connect
            *(set + p) = q;
          }
        }
        if(i < n-1 && *(system + (i+1)*n + j) == 0) { // connect bottom cell
          int p = i*n + j;
          int q = (i+1)*n + j;
          while(p != *(set + p)) {
            *(set + p) = *(set + *(set + p)); // path compression
            p = *(set + p);
          }
          while(q != *(set + q)) {
            *(set + q) = *(set + *(set + q)); // path compression
            q = *(set + q);
          }
          if(p != q) { // connect
            *(set + p) = q;
          }
        }
        if(j < n-1 && *(system + i*n + j+1) == 0) { // connect right cell
          int p = i*n + j;
          int q = i*n + j+1;
          while(p != *(set + p)) {
            *(set + p) = *(set + *(set + p)); // path compression
            p = *(set + p);
          }
          while(q != *(set + q)) {
            *(set + q) = *(set + *(set + q)); // path compression
            q = *(set + q);
          }
          if(p != q) { // connect
            *(set + p) = q;
          }
        }
      }
    }
  }

  // Check if top and bottom nodes are connected
  int perc = 0;

  while(top != *(set + top)) {
    *(set + top) = *(set + *(set + top));
    top = *(set + top);
  }

  while(bottom != *(set + bottom)) {
    *(set + bottom) = *(set + *(set + bottom));
    bottom = *(set + bottom);
  }

  if(top == bottom) { // percolates
    perc = 1;
  }

  free(set);
  return perc;
}

// Main driver code

int main() {
  int n = 5; // size of the system
  int *system = (int *) malloc(n * n * sizeof(int));

  initialize(system, n);

  printf("Initial system:\n");
  print_system(system, n);

  while(!percolates(system, n)) {
    initialize(system, n); // keep on trying
  }

  printf("Percolated system:\n");
  print_system(system, n);

  free(system);
  return 0;
}