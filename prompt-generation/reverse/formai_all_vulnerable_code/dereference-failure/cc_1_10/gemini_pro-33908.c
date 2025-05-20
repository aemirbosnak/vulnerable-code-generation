//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 10
#define PATH_CHAR '.'
#define WALL_CHAR '#'

// Represents a single cell in the maze
typedef struct Cell {
  char value;
  int visited;
} Cell;

// Represents the entire maze
typedef struct Maze {
  Cell grid[MAZE_SIZE][MAZE_SIZE];
  int start_x;
  int start_y;
  int end_x;
  int end_y;
} Maze;

// Creates a new maze
Maze *create_maze() {
  Maze *maze = malloc(sizeof(Maze));
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze->grid[i][j].value = WALL_CHAR;
      maze->grid[i][j].visited = 0;
    }
  }
  return maze;
}

// Loads a maze from a file
Maze *load_maze(char *filename) {
  Maze *maze = create_maze();
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return NULL;
  }
  char line[MAZE_SIZE + 1];
  for (int i = 0; i < MAZE_SIZE; i++) {
    fgets(line, MAZE_SIZE + 1, file);
    for (int j = 0; j < MAZE_SIZE; j++) {
      maze->grid[i][j].value = line[j];
      if (line[j] == 'S') {
        maze->start_x = i;
        maze->start_y = j;
      } else if (line[j] == 'E') {
        maze->end_x = i;
        maze->end_y = j;
      }
    }
  }
  fclose(file);
  return maze;
}

// Prints the maze
void print_maze(Maze *maze) {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c", maze->grid[i][j].value);
    }
    printf("\n");
  }
}

// Solves the maze using a depth-first search
int solve_maze(Maze *maze, int x, int y) {
  if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE) {
    return 0;
  }
  if (maze->grid[x][y].visited) {
    return 0;
  }
  if (maze->grid[x][y].value == WALL_CHAR) {
    return 0;
  }
  if (x == maze->end_x && y == maze->end_y) {
    return 1;
  }

  maze->grid[x][y].visited = 1;

  if (solve_maze(maze, x + 1, y)) {
    return 1;
  }
  if (solve_maze(maze, x - 1, y)) {
    return 1;
  }
  if (solve_maze(maze, x, y + 1)) {
    return 1;
  }
  if (solve_maze(maze, x, y - 1)) {
    return 1;
  }

  return 0;
}

int main() {
  Maze *maze = load_maze("maze.txt");
  if (maze == NULL) {
    printf("Error loading maze\n");
    return 1;
  }

  print_maze(maze);

  if (solve_maze(maze, maze->start_x, maze->start_y)) {
    printf("Maze solved!\n");
  } else {
    printf("No solution found\n");
  }

  return 0;
}