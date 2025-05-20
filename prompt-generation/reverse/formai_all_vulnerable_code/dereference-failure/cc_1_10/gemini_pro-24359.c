//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int x, y;
} Point;

int width, height;
int** maze;
Point* stack;
int stack_size;

void init_maze() {
  srand(time(NULL));
  width = rand() % 20 + 10;
  height = rand() % 20 + 10;
  maze = malloc(sizeof(int*) * height);
  for (int i = 0; i < height; i++) {
    maze[i] = malloc(sizeof(int) * width);
    for (int j = 0; j < width; j++) {
      maze[i][j] = 1;
    }
  }
  stack = malloc(sizeof(Point) * width * height);
  stack_size = 0;
}

void free_maze() {
  for (int i = 0; i < height; i++) {
    free(maze[i]);
  }
  free(maze);
  free(stack);
}

void print_maze() {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", maze[i][j] ? '#' : ' ');
    }
    printf("\n");
  }
}

Point get_random_neighbor(Point p) {
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int dir = rand() % 4;
  Point q = {p.x + dx[dir], p.y + dy[dir]};
  if (q.x < 0 || q.x >= width || q.y < 0 || q.y >= height || maze[q.y][q.x]) {
    return get_random_neighbor(p);
  }
  return q;
}

void generate_maze() {
  Point p = {rand() % width, rand() % height};
  stack[stack_size++] = p;
  while (stack_size > 0) {
    p = stack[rand() % stack_size];
    Point q = get_random_neighbor(p);
    maze[(p.y + q.y) / 2][(p.x + q.x) / 2] = 0;
    maze[q.y][q.x] = 0;
    stack[stack_size++] = q;
  }
}

int main() {
  init_maze();
  generate_maze();
  print_maze();
  free_maze();
  return 0;
}