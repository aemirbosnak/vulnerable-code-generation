//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point *points;
  int size;
} Path;

int maze[WIDTH][HEIGHT] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Path *path_new() {
  Path *path = malloc(sizeof(Path));
  path->points = malloc(sizeof(Point) * WIDTH * HEIGHT);
  path->size = 0;
  return path;
}

void path_free(Path *path) {
  free(path->points);
  free(path);
}

void path_add(Path *path, Point point) {
  path->points[path->size] = point;
  path->size++;
}

int path_is_valid(Point point) {
  return point.x >= 0 && point.x < WIDTH && point.y >= 0 && point.y < HEIGHT && maze[point.x][point.y] == 0;
}

Path *path_find(Point start, Point end) {
  Path *path = path_new();
  path_add(path, start);

  while (path->size > 0) {
    Point point = path->points[path->size - 1];

    if (point.x == end.x && point.y == end.y) {
      return path;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        Point neighbor = {point.x + i, point.y + j};

        if (path_is_valid(neighbor) && !path_contains(path, neighbor)) {
          path_add(path, neighbor);
        }
      }
    }

    path->size--;
  }

  path_free(path);
  return NULL;
}

int path_contains(Path *path, Point point) {
  for (int i = 0; i < path->size; i++) {
    if (path->points[i].x == point.x && path->points[i].y == point.y) {
      return 1;
    }
  }

  return 0;
}

void path_print(Path *path) {
  for (int i = 0; i < path->size; i++) {
    Point point = path->points[i];
    printf("(%d, %d)\n", point.x, point.y);
  }
}

int main() {
  Point start = {0, 0};
  Point end = {WIDTH - 1, HEIGHT - 1};

  Path *path = path_find(start, end);

  if (path != NULL) {
    path_print(path);
    path_free(path);
  } else {
    printf("No path found.\n");
  }

  return 0;
}