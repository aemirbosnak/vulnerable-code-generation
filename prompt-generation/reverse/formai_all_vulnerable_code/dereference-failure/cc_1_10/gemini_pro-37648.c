//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} point;

typedef struct {
  point *points;
  int size;
} point_set;

point_set *create_point_set(int size) {
  point_set *set = malloc(sizeof(point_set));
  set->points = malloc(sizeof(point) * size);
  set->size = size;
  return set;
}

void destroy_point_set(point_set *set) {
  free(set->points);
  free(set);
}

void add_point(point_set *set, point p) {
  set->points[set->size++] = p;
}

double distance(point p1, point p2) {
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double furthest_pair(point_set *set) {
  double max_distance = 0;
  for (int i = 0; i < set->size; i++) {
    for (int j = i + 1; j < set->size; j++) {
      double d = distance(set->points[i], set->points[j]);
      if (d > max_distance) {
        max_distance = d;
      }
    }
  }
  return max_distance;
}

int main() {
  point_set *set = create_point_set(10);
  add_point(set, (point){0, 0});
  add_point(set, (point){1, 0});
  add_point(set, (point){0, 1});
  add_point(set, (point){1, 1});
  add_point(set, (point){0.5, 0.5});
  add_point(set, (point){0.25, 0.25});
  add_point(set, (point){0.75, 0.75});
  add_point(set, (point){0.125, 0.125});
  add_point(set, (point){0.875, 0.875});
  add_point(set, (point){0.0625, 0.0625});

  double max_distance = furthest_pair(set);
  printf("The furthest pair of points is %.3f units apart.\n", max_distance);

  destroy_point_set(set);

  return 0;
}