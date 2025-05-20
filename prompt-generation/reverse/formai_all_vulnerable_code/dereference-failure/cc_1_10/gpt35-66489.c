//FormAI DATASET v1.0 Category: Game of Life ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

int count_neighbors(int *grid, int x, int y);
void print_grid(int *grid);
void update_grid(int *grid, int *new_grid);

int main() {
  // initialize grid to all zeros
  int *grid = calloc(WIDTH * HEIGHT, sizeof(int));
  int *new_grid = calloc(WIDTH * HEIGHT, sizeof(int));

  // set some random cells to be alive
  srand(time(NULL));
  for (int i = 0; i < WIDTH * HEIGHT / 4; i++) {
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    grid[y * WIDTH + x] = 1;
  }

  // run the simulation
  for (int i = 0; i < 100; i++) {
    update_grid(grid, new_grid);
    print_grid(new_grid);
    int *temp = grid;
    grid = new_grid;
    new_grid = temp;
    // wait for a short time before updating again
    struct timespec delay = {0, 200000000}; // 0.2 seconds
    nanosleep(&delay, NULL);
  }

  free(grid);
  free(new_grid);
  return 0;
}

// count the number of live neighbors around cell (x,y)
int count_neighbors(int *grid, int x, int y) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      int nx = x + i;
      int ny = y + j;
      if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
        if (grid[ny * WIDTH + nx] == 1) {
          count++;
        }
      }
    }
  }
  return count;
}

// print the grid to the console
void print_grid(int *grid) {
  system("clear"); // clear the console before printing
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (grid[y * WIDTH + x] == 1) {
        printf("O");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

// update the grid for the next generation
void update_grid(int *grid, int *new_grid) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int count = count_neighbors(grid, x, y);
      if (grid[y * WIDTH + x] == 1) {
        if (count < 2 || count > 3) {
          new_grid[y * WIDTH + x] = 0; // cell dies
        } else {
          new_grid[y * WIDTH + x] = 1; // cell lives
        }
      } else {
        if (count == 3) {
          new_grid[y * WIDTH + x] = 1; // cell is born
        } else {
          new_grid[y * WIDTH + x] = 0; // cell remains dead
        }
      }
    }
  }
}