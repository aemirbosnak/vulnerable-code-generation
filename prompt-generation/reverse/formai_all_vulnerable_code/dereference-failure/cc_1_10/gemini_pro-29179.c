//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the width and height of the maze
#define WIDTH 20
#define HEIGHT 20

// Define the different types of cells in the maze
enum CellType {
  WALL,
  PATH,
  VISITED
};

// Define the directions that we can move in
enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

// Define the data structure for a cell in the maze
typedef struct Cell {
  enum CellType type;
  int visited;
  struct Cell *north, *east, *south, *west;
} Cell;

// Define the data structure for the maze
typedef struct Maze {
  Cell **cells;
  int width, height;
} Maze;

// Create a new maze
Maze *create_maze(int width, int height) {
  Maze *maze = malloc(sizeof(Maze));
  maze->width = width;
  maze->height = height;
  maze->cells = malloc(sizeof(Cell *) * height);
  for (int i = 0; i < height; i++) {
    maze->cells[i] = malloc(sizeof(Cell) * width);
  }
  return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    free(maze->cells[i]);
  }
  free(maze->cells);
  free(maze);
}

// Initialize the maze with all walls
void initialize_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      maze->cells[i][j].type = WALL;
      maze->cells[i][j].visited = 0;
      maze->cells[i][j].north = NULL;
      maze->cells[i][j].east = NULL;
      maze->cells[i][j].south = NULL;
      maze->cells[i][j].west = NULL;
    }
  }
}

// Set the north wall of a cell
void set_north_wall(Maze *maze, int x, int y) {
  maze->cells[y][x].north = &maze->cells[y - 1][x];
}

// Set the east wall of a cell
void set_east_wall(Maze *maze, int x, int y) {
  maze->cells[y][x].east = &maze->cells[y][x + 1];
}

// Set the south wall of a cell
void set_south_wall(Maze *maze, int x, int y) {
  maze->cells[y][x].south = &maze->cells[y + 1][x];
}

// Set the west wall of a cell
void set_west_wall(Maze *maze, int x, int y) {
  maze->cells[y][x].west = &maze->cells[y][x - 1];
}

// Get a random direction
enum Direction get_random_direction() {
  return rand() % 4;
}

// Generate a maze using the recursive backtracking algorithm
void generate_maze(Maze *maze) {
  // Start at the top-left corner of the maze
  int x = 0;
  int y = 0;

  // Mark the current cell as visited
  maze->cells[y][x].visited = 1;

  // While there are still unvisited cells
  while (1) {
    // Get a random direction
    enum Direction direction = get_random_direction();

    // If the cell in the chosen direction is unvisited
    switch (direction) {
      case NORTH:
        if (y > 0 && !maze->cells[y - 1][x].visited) {
          // Set the north wall of the current cell
          set_north_wall(maze, x, y);

          // Mark the cell in the chosen direction as visited
          maze->cells[y - 1][x].visited = 1;

          // Move to the cell in the chosen direction
          y--;
        }
        break;
      case EAST:
        if (x < maze->width - 1 && !maze->cells[y][x + 1].visited) {
          // Set the east wall of the current cell
          set_east_wall(maze, x, y);

          // Mark the cell in the chosen direction as visited
          maze->cells[y][x + 1].visited = 1;

          // Move to the cell in the chosen direction
          x++;
        }
        break;
      case SOUTH:
        if (y < maze->height - 1 && !maze->cells[y + 1][x].visited) {
          // Set the south wall of the current cell
          set_south_wall(maze, x, y);

          // Mark the cell in the chosen direction as visited
          maze->cells[y + 1][x].visited = 1;

          // Move to the cell in the chosen direction
          y++;
        }
        break;
      case WEST:
        if (x > 0 && !maze->cells[y][x - 1].visited) {
          // Set the west wall of the current cell
          set_west_wall(maze, x, y);

          // Mark the cell in the chosen direction as visited
          maze->cells[y][x - 1].visited = 1;

          // Move to the cell in the chosen direction
          x--;
        }
        break;
    }

    // If all cells have been visited, break out of the loop
    if (all_cells_visited(maze)) {
      break;
    }
  }
}

// Check if all cells in the maze have been visited
int all_cells_visited(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      if (!maze->cells[i][j].visited) {
        return 0;
      }
    }
  }
  return 1;
}

// Print the maze to the console
void print_maze(Maze *maze) {
  for (int i = 0; i < maze->height; i++) {
    for (int j = 0; j < maze->width; j++) {
      switch (maze->cells[i][j].type) {
        case WALL:
          printf("#");
          break;
        case PATH:
          printf(" ");
          break;
        case VISITED:
          printf(".");
          break;
      }
    }
    printf("\n");
  }
}

// The main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new maze
  Maze *maze = create_maze(WIDTH, HEIGHT);

  // Initialize the maze with all walls
  initialize_maze(maze);

  // Generate the maze
  generate_maze(maze);

  // Print the maze to the console
  print_maze(maze);

  // Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}