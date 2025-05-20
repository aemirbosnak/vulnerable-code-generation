//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define WIDTH 20
#define HEIGHT 10

/* Function declarations */
void initialize(int **grid);
void printGrid(int **grid);
void generatePixelArt(int **grid);

int main() {
  /* Seed the random number generator */
  srand(time(NULL));
  
  /* Allocate memory for the grid */
  int **grid = malloc(sizeof(int*) * HEIGHT);
  for (int i = 0; i < HEIGHT; i++) {
    grid[i] = malloc(sizeof(int) * WIDTH);
  }
  
  /* Initialize the grid */
  initialize(grid);
  
  /* Generate some pixel art */
  generatePixelArt(grid);
  
  /* Print the final grid */
  printGrid(grid);
  
  /* Free the memory */
  for (int i = 0; i < HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);
  
  return 0;
}

/* Initializes the grid with random binary values */
void initialize(int **grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

/* Prints the grid with X for 1 and O for 0 */
void printGrid(int **grid) {
  printf("\n");
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid[i][j]) {
        printf("X ");
      } else {
        printf("O ");
      }
    }
    printf("\n");
  }
}

/* Generates pixel art by grouping neighboring values */
void generatePixelArt(int **grid) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (grid[i][j]) {
        /* Check neighbors */
        int neighbors = 0;
        if (i > 0 && grid[i-1][j]) {
          neighbors++;
        }
        if (i < HEIGHT-1 && grid[i+1][j]) {
          neighbors++;
        }
        if (j > 0 && grid[i][j-1]) {
          neighbors++;
        }
        if (j < WIDTH-1 && grid[i][j+1]) {
          neighbors++;
        }
        if (neighbors > 1) {
          grid[i][j] = 2;
        }
      }
    }
  }
}