//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20
#define NUM_CELLS MAZE_WIDTH * MAZE_HEIGHT

// Cell types
typedef enum {
  CELL_EMPTY,
  CELL_WALL,
  CELL_START,
  CELL_END
} CellType;

// Cell structure
typedef struct {
  CellType type;
  int visited;
} Cell;

// Maze structure
typedef struct {
  Cell cells[NUM_CELLS];
  int start_cell;
  int end_cell;
} Maze;

// Function prototypes
Maze* create_maze();
void print_maze(Maze* maze);
void solve_maze(Maze* maze);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new maze
  Maze* maze = create_maze();

  // Print the maze
  print_maze(maze);

  // Solve the maze
  solve_maze(maze);

  return 0;
}

// Function to create a new maze
Maze* create_maze() {
  // Allocate memory for the maze
  Maze* maze = malloc(sizeof(Maze));

  // Initialize the maze cells to empty
  for (int i = 0; i < NUM_CELLS; i++) {
    maze->cells[i].type = CELL_EMPTY;
    maze->cells[i].visited = 0;
  }

  // Set the start and end cells
  maze->start_cell = rand() % NUM_CELLS;
  maze->end_cell = rand() % NUM_CELLS;

  // Generate the maze
  int current_cell = maze->start_cell;
  while (current_cell != maze->end_cell) {
    // Get the possible moves from the current cell
    int possible_moves[4];
    int num_possible_moves = 0;
    if (current_cell % MAZE_WIDTH != 0) {
      possible_moves[num_possible_moves++] = current_cell - 1;
    }
    if (current_cell % MAZE_WIDTH != MAZE_WIDTH - 1) {
      possible_moves[num_possible_moves++] = current_cell + 1;
    }
    if (current_cell / MAZE_WIDTH != 0) {
      possible_moves[num_possible_moves++] = current_cell - MAZE_WIDTH;
    }
    if (current_cell / MAZE_WIDTH != MAZE_HEIGHT - 1) {
      possible_moves[num_possible_moves++] = current_cell + MAZE_WIDTH;
    }

    // Choose a random move
    int next_cell = possible_moves[rand() % num_possible_moves];

    // Set the cell to a wall
    maze->cells[current_cell].type = CELL_WALL;

    // Mark the cell as visited
    maze->cells[current_cell].visited = 1;

    // Move to the next cell
    current_cell = next_cell;
  }

  return maze;
}

// Function to print the maze
void print_maze(Maze* maze) {
  // Print the top border
  for (int i = 0; i < MAZE_WIDTH * 2 + 1; i++) {
    printf("-");
  }
  printf("\n");

  // Print the maze cells
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    // Print the left border
    printf("|");

    // Print the maze cells
    for (int j = 0; j < MAZE_WIDTH; j++) {
      switch (maze->cells[i * MAZE_WIDTH + j].type) {
        case CELL_EMPTY:
          printf(" ");
          break;
        case CELL_WALL:
          printf("#");
          break;
        case CELL_START:
          printf("S");
          break;
        case CELL_END:
          printf("E");
          break;
      }
    }

    // Print the right border
    printf("|\n");
  }

  // Print the bottom border
  for (int i = 0; i < MAZE_WIDTH * 2 + 1; i++) {
    printf("-");
  }
  printf("\n");
}

// Function to solve the maze
void solve_maze(Maze* maze) {
  // Create a stack to store the path
  int stack[NUM_CELLS];
  int stack_top = 0;

  // Start at the start cell
  int current_cell = maze->start_cell;

  // While we haven't reached the end cell
  while (current_cell != maze->end_cell) {
    // Mark the cell as visited
    maze->cells[current_cell].visited = 1;

    // Push the cell onto the stack
    stack[stack_top++] = current_cell;

    // Get the possible moves from the current cell
    int possible_moves[4];
    int num_possible_moves = 0;
    if (current_cell % MAZE_WIDTH != 0 && maze->cells[current_cell - 1].type != CELL_WALL && !maze->cells[current_cell - 1].visited) {
      possible_moves[num_possible_moves++] = current_cell - 1;
    }
    if (current_cell % MAZE_WIDTH != MAZE_WIDTH - 1 && maze->cells[current_cell + 1].type != CELL_WALL && !maze->cells[current_cell + 1].visited) {
      possible_moves[num_possible_moves++] = current_cell + 1;
    }
    if (current_cell / MAZE_WIDTH != 0 && maze->cells[current_cell - MAZE_WIDTH].type != CELL_WALL && !maze->cells[current_cell - MAZE_WIDTH].visited) {
      possible_moves[num_possible_moves++] = current_cell - MAZE_WIDTH;
    }
    if (current_cell / MAZE_WIDTH != MAZE_HEIGHT - 1 && maze->cells[current_cell + MAZE_WIDTH].type != CELL_WALL && !maze->cells[current_cell + MAZE_WIDTH].visited) {
      possible_moves[num_possible_moves++] = current_cell + MAZE_WIDTH;
    }

    // If there are no possible moves, backtrack
    if (num_possible_moves == 0) {
      current_cell = stack[--stack_top];
    }
    // Otherwise, choose a random move
    else {
      current_cell = possible_moves[rand() % num_possible_moves];
    }
  }

  // Print the solution
  printf("Solution:\n");
  for (int i = 0; i < stack_top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}