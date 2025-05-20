//GEMINI-pro DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLANK ' '
#define FILLED 'x'
#define MIN_SIZE 3
#define MAX_SIZE 9

// Structure to represent a cell in the grid
typedef struct cell {
  char value;
  int num_adjacent;
} cell;

// Structure to represent the grid
typedef struct grid {
  int size;
  cell **cells;
} grid;

// Function to create a new grid
grid *create_grid(int size) {
  grid *new_grid = malloc(sizeof(grid));
  new_grid->size = size;

  new_grid->cells = malloc(size * sizeof(cell *));
  for (int i = 0; i < size; i++) {
    new_grid->cells[i] = malloc(size * sizeof(cell));
  }

  return new_grid;
}

// Function to free the memory allocated for a grid
void free_grid(grid *grid) {
  for (int i = 0; i < grid->size; i++) {
    free(grid->cells[i]);
  }

  free(grid->cells);
  free(grid);
}

// Function to fill a cell with either a blank or a filled value
void fill_cell(cell *cell) {
  cell->value = rand() % 2 == 0 ? BLANK : FILLED;
}

// Function to generate a random grid
grid *generate_random_grid(int size) {
  grid *new_grid = create_grid(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      fill_cell(&new_grid->cells[i][j]);
    }
  }

  return new_grid;
}

// Function to print a grid
void print_grid(grid *grid) {
  for (int i = 0; i < grid->size; i++) {
    for (int j = 0; j < grid->size; j++) {
      printf("%c ", grid->cells[i][j].value);
    }
    printf("\n");
  }
}

// Function to check if a cell is valid
int is_valid_cell(grid *grid, int row, int col) {
  return row >= 0 && row < grid->size && col >= 0 && col < grid->size;
}

// Function to count the number of adjacent filled cells
int count_adjacent_filled_cells(grid *grid, int row, int col) {
  int count = 0;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) continue;

      int x = row + i;
      int y = col + j;

      if (is_valid_cell(grid, x, y) && grid->cells[x][y].value == FILLED) {
        count++;
      }
    }
  }

  return count;
}

// Function to update the number of adjacent filled cells for each cell in the grid
void update_num_adjacent_filled_cells(grid *grid) {
  for (int i = 0; i < grid->size; i++) {
    for (int j = 0; j < grid->size; j++) {
      grid->cells[i][j].num_adjacent = count_adjacent_filled_cells(grid, i, j);
    }
  }
}

// Function to check if a grid is solved
int is_grid_solved(grid *grid) {
  for (int i = 0; i < grid->size; i++) {
    for (int j = 0; j < grid->size; j++) {
      if (grid->cells[i][j].value == BLANK) {
        return 0;
      }
    }
  }

  return 1;
}

// Function to get the number of unsolved cells in a grid
int get_num_unsolved_cells(grid *grid) {
  int count = 0;

  for (int i = 0; i < grid->size; i++) {
    for (int j = 0; j < grid->size; j++) {
      if (grid->cells[i][j].value == BLANK) {
        count++;
      }
    }
  }

  return count;
}

// Function to solve a grid using a simple algorithm
int solve_grid(grid *grid) {
  int num_unsolved_cells = get_num_unsolved_cells(grid);

  while (num_unsolved_cells > 0) {
    for (int i = 0; i < grid->size; i++) {
      for (int j = 0; j < grid->size; j++) {
        if (grid->cells[i][j].value == BLANK) {
          int num_adjacent_filled_cells = grid->cells[i][j].num_adjacent;

          if (num_adjacent_filled_cells == 0 || num_adjacent_filled_cells == grid->size - 1) {
            grid->cells[i][j].value = FILLED;
            num_unsolved_cells--;
          }
        }
      }
    }

    update_num_adjacent_filled_cells(grid);
  }

  return is_grid_solved(grid);
}

// Main function
int main() {
  // Set the random seed
  srand(time(NULL));

  // Get the grid size from the user
  int size;
  printf("Enter the size of the grid (between %d and %d): ", MIN_SIZE, MAX_SIZE);
  scanf("%d", &size);

  // Create a new grid
  grid *grid = generate_random_grid(size);

  // Print the grid
  printf("Initial grid:\n");
  print_grid(grid);

  // Solve the grid
  int solved = solve_grid(grid);

  // Print the solved grid
  printf("Solved grid:\n");
  print_grid(grid);

  // Free the memory allocated for the grid
  free_grid(grid);

  return 0;
}