//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point* points;
  int size;
  int capacity;
} PointArray;

PointArray* point_array_new() {
  PointArray* array = malloc(sizeof(PointArray));
  array->points = malloc(sizeof(Point) * 10);
  array->size = 0;
  array->capacity = 10;
  return array;
}

void point_array_free(PointArray* array) {
  free(array->points);
  free(array);
}

void point_array_add(PointArray* array, Point point) {
  if (array->size == array->capacity) {
    array->capacity *= 2;
    array->points = realloc(array->points, sizeof(Point) * array->capacity);
  }
  array->points[array->size++] = point;
}

Point point_new(int x, int y) {
  Point point = {x, y};
  return point;
}

int point_distance(Point a, Point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
  PointArray* points = point_array_new();
  point_array_add(points, point_new(0, 0));
  point_array_add(points, point_new(1, 0));
  point_array_add(points, point_new(2, 0));
  point_array_add(points, point_new(3, 0));
  point_array_add(points, point_new(0, 1));
  point_array_add(points, point_new(1, 1));
  point_array_add(points, point_new(2, 1));
  point_array_add(points, point_new(3, 1));
  point_array_add(points, point_new(0, 2));
  point_array_add(points, point_new(1, 2));
  point_array_add(points, point_new(2, 2));
  point_array_add(points, point_new(3, 2));

  for (int i = 0; i < points->size; i++) {
    for (int j = 0; j < points->size; j++) {
      printf("%d ", point_distance(points->points[i], points->points[j]));
    }
    printf("\n");
  }

  point_array_free(points);
  return 0;
}