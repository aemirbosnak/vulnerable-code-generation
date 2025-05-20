//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int width;
  int height;
  bool **maze;
} Maze;

bool is_valid_point(const Maze *maze, Point point) {
  return point.x >= 0 && point.x < maze->width && point.y >= 0 && point.y < maze->height && !maze->maze[point.y][point.x];
}

bool is_end_point(const Point point, const Point end) {
  return point.x == end.x && point.y == end.y;
}

void print_maze(const Maze *maze) {
  for (int y = 0; y < maze->height; y++) {
    for (int x = 0; x < maze->width; x++) {
      printf("%c", maze->maze[y][x] ? '#' : '.');
    }
    printf("\n");
  }
}

bool find_path(Maze *maze, Point start, Point end) {
  // Create a stack to store the points to visit
  Point *stack = malloc(sizeof(Point) * maze->width * maze->height);
  int top = 0;

  // Push the start point to the stack
  stack[top++] = start;

  // While the stack is not empty
  while (top > 0) {
    // Pop the top point from the stack
    Point point = stack[--top];

    // If the point is the end point, return true
    if (is_end_point(point, end)) {
      return true;
    }

    // Check the four adjacent points (up, down, left, right)
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        // Make sure the point is within the bounds of the maze and not a wall
        if (i != 0 || j != 0) {
          Point adjacent_point = {point.x + i, point.y + j};
          if (is_valid_point(maze, adjacent_point)) {
            // Push the adjacent point to the stack
            stack[top++] = adjacent_point;

            // Mark the adjacent point as visited by setting it to a wall
            maze->maze[adjacent_point.y][adjacent_point.x] = true;
          }
        }
      }
    }
  }

  // If the stack is empty, return false
  return false;
}

int main() {
  // Create a maze
  Maze maze = {
    .width = 10,
    .height = 10,
    .maze = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
      {0, 1, 0, 0, 0, 0, 1, 1, 0, 0},
      {0, 1, 1, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 1, 0, 0, 1, 0},
      {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 0, 1, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    }
  };

  // Print the maze
  printf("Maze:\n");
  print_maze(&maze);

  // Find the path from the start point to the end point
  Point start = {0, 0};
  Point end = {9, 9};
  bool path_found = find_path(&maze, start, end);

  // Print the result
  printf("Path found: %s\n", path_found ? "true" : "false");

  return 0;
}