//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// define the size of the grid
#define ROWS 7
#define COLS 10

// define the start and end coordinates
#define START_ROW 1
#define START_COL 1
#define END_ROW 5
#define END_COL 8

// define the heuristic function
int heuristic(int row, int col) {
  return abs(row - END_ROW) + abs(col - END_COL);
}

// define the cell structure
typedef struct {
  int f_score;
  int g_score;
  int row;
  int col;
} Cell;

// define the grid
const int grid[ROWS][COLS] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
  {1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// define the open and closed lists
Cell open_list[ROWS * COLS];
Cell closed_list[ROWS * COLS];

// define the pointers to the current cell, the start cell, and the end cell
Cell* current_cell;
Cell* start_cell;
Cell* end_cell;

// define the number of cells in the open and closed lists
int open_list_size = 0;
int closed_list_size = 0;

// define the function to add a cell to the open list
void add_to_open_list(int row, int col, int g_score) {
  Cell* cell = malloc(sizeof(Cell));
  cell->row = row;
  cell->col = col;
  cell->g_score = g_score;
  cell->f_score = g_score + heuristic(row, col);
  open_list[open_list_size++] = *cell;
}

// define the function to add a cell to the closed list
void add_to_closed_list(Cell* cell) {
  closed_list[closed_list_size++] = *cell;
}

// define the function to check if a cell is in the open list
int is_in_open_list(int row, int col) {
  for (int i = 0; i < open_list_size; i++) {
    if (open_list[i].row == row && open_list[i].col == col) {
      return 1;
    }
  }
  return 0;
}

// define the function to check if a cell is in the closed list
int is_in_closed_list(int row, int col) {
  for (int i = 0; i < closed_list_size; i++) {
    if (closed_list[i].row == row && closed_list[i].col == col) {
      return 1;
    }
  }
  return 0;
}

int main() {
  // set the start and end cells
  start_cell = malloc(sizeof(Cell));
  start_cell->row = START_ROW;
  start_cell->col = START_COL;
  start_cell->g_score = 0;
  start_cell->f_score = heuristic(start_cell->row, start_cell->col);
  end_cell = malloc(sizeof(Cell));
  end_cell->row = END_ROW;
  end_cell->col = END_COL;
  end_cell->g_score = 0;
  end_cell->f_score = 0;

  // add the start cell to the open list
  add_to_open_list(start_cell->row, start_cell->col, start_cell->g_score);

  // while the open list is not empty
  while (open_list_size > 0) {
    // get the cell in the open list with the lowest f-score
    int min_f_score = __INT_MAX__;
    for (int i = 0; i < open_list_size; i++) {
      if (open_list[i].f_score < min_f_score) {
        min_f_score = open_list[i].f_score;
        current_cell = &open_list[i];
      }
    }

    // if the current cell is the end cell, we have reached our destination
    if (current_cell->row == end_cell->row && current_cell->col == end_cell->col) {
      printf("Destination reached!\n");
      break;
    }

    // remove the current cell from the open list and add it to the closed list
    for (int i = 0; i < open_list_size; i++) {
      if (open_list[i].row == current_cell->row && open_list[i].col == current_cell->col) {
        for (int j = i; j < open_list_size - 1; j++) {
          open_list[j] = open_list[j + 1];
        }
        open_list_size--;
        break;
      }
    }
    add_to_closed_list(current_cell);

    // for each of the current cell's neighbors
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        // skip the current cell
        if (i == 0 && j == 0) {
          continue;
        }

        // calculate the neighbor's coordinates
        int n_row = current_cell->row + i;
        int n_col = current_cell->col + j;

        // skip cells that are outside of the grid
        if (n_row < 0 || n_row >= ROWS || n_col < 0 || n_col >= COLS) {
          continue;
        }

        // skip cells that are not traversable
        if (grid[n_row][n_col] == 1) {
          continue;
        }

        // calculate the neighbor's g-score
        int n_g_score = current_cell->g_score + 1;

        // if the neighbor is in the closed list and the new g-score is higher than the neighbor's g-score, skip the neighbor
        if (is_in_closed_list(n_row, n_col) && n_g_score >= closed_list[closed_list_size - 1].g_score) {
          continue;
        }

        // if the neighbor is in the open list and the new g-score is higher than the neighbor's g-score, skip the neighbor
        if (is_in_open_list(n_row, n_col) && n_g_score >= open_list[open_list_size - 1].g_score) {
          continue;
        }

        // add the neighbor to the open list
        add_to_open_list(n_row, n_col, n_g_score);
      }
    }
  }

  return 0;
}