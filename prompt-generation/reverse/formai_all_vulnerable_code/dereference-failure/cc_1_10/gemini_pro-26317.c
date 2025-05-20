//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdlib.h>
#include <stdio.h>

#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// Defines the directions we can move in the maze
typedef enum {
  NORTH,
  EAST,
  SOUTH,
  WEST
} direction_t;

// Represents a single cell in the maze
typedef struct {
  int x, y;
  int visited;
  int walls[4];
} cell_t;

// Represents the entire maze
typedef struct {
  cell_t cells[MAZE_WIDTH][MAZE_HEIGHT];
} maze_t;

// Creates a new maze
maze_t* create_maze() {
  maze_t* maze = malloc(sizeof(maze_t));

  // Initialize all cells to unvisited and with all walls intact
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      maze->cells[i][j].x = i;
      maze->cells[i][j].y = j;
      maze->cells[i][j].visited = 0;
      for (int k = 0; k < 4; k++) {
        maze->cells[i][j].walls[k] = 1;
      }
    }
  }

  return maze;
}

// Frees the memory allocated for the maze
void destroy_maze(maze_t* maze) {
  free(maze);
}

// Prints the maze to the console
void print_maze(maze_t* maze) {
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      // Print the top wall
      if (maze->cells[i][j].walls[NORTH]) {
        printf("+---");
      } else {
        printf("+   ");
      }
    }
    printf("+\n");

    // Print the left wall and the cell
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      if (maze->cells[i][j].walls[WEST]) {
        printf("|   ");
      } else {
        printf("    ");
      }

      if (maze->cells[i][j].visited) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }
    printf("|\n");
  }

  // Print the bottom wall
  for (int i = 0; i < MAZE_WIDTH; i++) {
    printf("+---");
  }
  printf("+\n");
}

// Generates a maze using a recursive backtracker algorithm
void generate_maze(maze_t* maze) {
  // Choose a random starting cell
  int x = rand() % MAZE_WIDTH;
  int y = rand() % MAZE_HEIGHT;

  // Mark the starting cell as visited
  maze->cells[x][y].visited = 1;

  // Create a stack to store the cells we've visited
  int stack[MAZE_WIDTH * MAZE_HEIGHT];
  int top = 0;

  // While there are still unvisited cells, continue generating the maze
  while (top >= 0) {
    // Get the current cell from the stack
    int x = stack[top];
    int y = stack[top - 1];
    top -= 2;

    // Get a list of unvisited neighbors of the current cell
    int neighbors[4];
    int num_neighbors = 0;
    if (!maze->cells[x][y].walls[NORTH] && !maze->cells[x][y - 1].visited) {
      neighbors[num_neighbors++] = NORTH;
    }
    if (!maze->cells[x][y].walls[EAST] && !maze->cells[x + 1][y].visited) {
      neighbors[num_neighbors++] = EAST;
    }
    if (!maze->cells[x][y].walls[SOUTH] && !maze->cells[x][y + 1].visited) {
      neighbors[num_neighbors++] = SOUTH;
    }
    if (!maze->cells[x][y].walls[WEST] && !maze->cells[x - 1][y].visited) {
      neighbors[num_neighbors++] = WEST;
    }

    // If there are no unvisited neighbors, backtrack
    if (num_neighbors == 0) {
      continue;
    }

    // Choose a random neighbor
    int neighbor = neighbors[rand() % num_neighbors];

    // Knock down the wall between the current cell and the neighbor
    switch (neighbor) {
      case NORTH:
        maze->cells[x][y].walls[NORTH] = 0;
        maze->cells[x][y - 1].walls[SOUTH] = 0;
        break;
      case EAST:
        maze->cells[x][y].walls[EAST] = 0;
        maze->cells[x + 1][y].walls[WEST] = 0;
        break;
      case SOUTH:
        maze->cells[x][y].walls[SOUTH] = 0;
        maze->cells[x][y + 1].walls[NORTH] = 0;
        break;
      case WEST:
        maze->cells[x][y].walls[WEST] = 0;
        maze->cells[x - 1][y].walls[EAST] = 0;
        break;
    }

    // Push the neighbor onto the stack
    stack[top++] = x;
    stack[top++] = y;

    // Mark the neighbor as visited
    maze->cells[x][y].visited = 1;
  }
}

// Solves the maze using a depth-first search algorithm
int solve_maze(maze_t* maze, int x, int y) {
  // Mark the current cell as visited
  maze->cells[x][y].visited = 1;

  // If we have reached the exit, return true
  if (x == MAZE_WIDTH - 1 && y == MAZE_HEIGHT - 1) {
    return 1;
  }

  // Try all possible moves from the current cell
  int moves[4] = {NORTH, EAST, SOUTH, WEST};
  for (int i = 0; i < 4; i++) {
    int move = moves[i];

    // If the move is valid, try it
    if (!maze->cells[x][y].walls[move] && !maze->cells[x][y].visited) {
      switch (move) {
        case NORTH:
          if (solve_maze(maze, x, y - 1)) {
            return 1;
          }
          break;
        case EAST:
          if (solve_maze(maze, x + 1, y)) {
            return 1;
          }
          break;
        case SOUTH:
          if (solve_maze(maze, x, y + 1)) {
            return 1;
          }
          break;
        case WEST:
          if (solve_maze(maze, x - 1, y)) {
            return 1;
          }
          break;
      }
    }
  }

  // If no valid moves were found, backtrack
  maze->cells[x][y].visited = 0;
  return 0;
}

// The main function
int main() {
  // Create a new maze
  maze_t* maze = create_maze();

  // Generate the maze
  generate_maze(maze);

  // Print the maze
  print_maze(maze);

  // Solve the maze
  if (solve_maze(maze, 0, 0)) {
    printf("The maze was solved!\n");
  } else {
    printf("The maze could not be solved.\n");
  }

  // Destroy the maze
  destroy_maze(maze);

  return 0;
}