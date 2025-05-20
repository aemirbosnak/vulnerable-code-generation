//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point *points;
  int size;
} Maze;

Maze *create_maze(int width, int height) {
  // Allocate memory for the maze
  Maze *maze = malloc(sizeof(Maze));
  maze->points = malloc(width * height * sizeof(Point));
  maze->size = width * height;

  // Initialize the points in the maze
  for (int i = 0; i < width; i++) {
    for (int j = 0; j < height; j++) {
      maze->points[i * height + j].x = i;
      maze->points[i * height + j].y = j;
    }
  }

  // Randomly shuffle the points
  srand(time(NULL));
  for (int i = 0; i < width * height; i++) {
    int j = rand() % (width * height);
    Point tmp = maze->points[i];
    maze->points[i] = maze->points[j];
    maze->points[j] = tmp;
  }

  return maze;
}

void print_maze(Maze *maze) {
  // Print the top border
  for (int i = 0; i < maze->size; i++) {
    printf("+---");
  }
  printf("+\n");

  // Print the maze
  for (int i = 0; i < maze->size; i++) {
    // Print the left border
    printf("| ");

    // Print the point
    Point point = maze->points[i];
    printf("%2d %2d ", point.x, point.y);

    // Print the right border
    printf("| ");

    // Print the bottom border if we are at the bottom of the row
    if (i % WIDTH == WIDTH - 1) {
      printf("\n");
      for (int j = 0; j < maze->size; j++) {
        printf("+---");
      }
      printf("+\n");
    }
  }
}

void free_maze(Maze *maze) {
  free(maze->points);
  free(maze);
}

int main() {
  // Create a maze
  Maze *maze = create_maze(WIDTH, HEIGHT);

  // Print the maze
  print_maze(maze);

  // Free the maze
  free_maze(maze);

  return 0;
}