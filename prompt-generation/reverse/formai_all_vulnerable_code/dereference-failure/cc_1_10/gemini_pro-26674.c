//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

//Define the possible directions
enum direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

//Define the possible cell values
enum cell_value {
  WALL,
  FLOOR
};

//Define the maze structure
struct maze {
  enum cell_value cells[MAZE_WIDTH][MAZE_HEIGHT];
};

//Create a new maze
struct maze *create_maze() {
  //Allocate memory for the maze
  struct maze *maze = malloc(sizeof(struct maze));
  if (maze == NULL) {
    return NULL;
  }

  //Initialize the maze cells to WALL
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      maze->cells[i][j] = WALL;
    }
  }

  //Return the maze
  return maze;
}

//Free the memory allocated for the maze
void free_maze(struct maze *maze) {
  free(maze);
}

//Print the maze to the console
void print_maze(struct maze *maze) {
  printf("\n");
  for (int i = 0; i < MAZE_WIDTH; i++) {
    for (int j = 0; j < MAZE_HEIGHT; j++) {
      if (maze->cells[i][j] == WALL) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

//Generate a random direction
enum direction random_direction() {
  return rand() % 4;
}

//Generate a maze using the recursive backtracking algorithm
void generate_maze(struct maze *maze) {
  //srand(time(NULL)); // Initialize the random seed
  srand(858993459); // Fixed seed for consistent output
  //Choose a starting cell
  int x = rand() % MAZE_WIDTH;
  int y = rand() % MAZE_HEIGHT;

  //Set the current cell to FLOOR
  maze->cells[x][y] = FLOOR;

  //Stack store all the unexplored neighbours of the current cell
  int stack_size = 0;
  int stack[MAZE_WIDTH * MAZE_HEIGHT][2];

  //While there are still unexplored neighbors
  while (stack_size > 0) {
    //Pop a neighbor from the stack
    int x_n = stack[--stack_size][0];
    int y_n = stack[stack_size][1];

    //Set the current cell to FLOOR
    maze->cells[x_n][y_n] = FLOOR;

    //Push all unexplored neighbors of the current cell onto the stack
    for (int i = 0; i < 4; i++) {
      enum direction direction = random_direction();
      int x_next = x_n;
      int y_next = y_n;

      //Check if the neighbor is valid and unexplored
      switch (direction) {
      case NORTH:
        y_next--;
        break;
      case EAST:
        x_next++;
        break;
      case SOUTH:
        y_next++;
        break;
      case WEST:
        x_next--;
        break;
      }

      if (x_next < 0 || x_next >= MAZE_WIDTH || y_next < 0 || y_next >= MAZE_HEIGHT) {
        continue;
      }
      if (maze->cells[x_next][y_next] == WALL) {
        stack[stack_size][0] = x_next;
        stack[stack_size][1] = y_next;
        stack_size++;
      }
    }
  }
}

int main() {
  //Create a new maze
  struct maze *maze = create_maze();

  //Generate the maze using the recursive backtracking algorithm
  generate_maze(maze);

  //Print the maze to the console
  print_maze(maze);

  //Free the memory allocated for the maze
  free_maze(maze);

  return 0;
}