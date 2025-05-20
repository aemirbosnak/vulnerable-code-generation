//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct { double x, y; } point;

// Calculate the distance between two points
double dist(point p1, point p2) {
  double dx = p1.x - p2.x, dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

// Calculate the midpoint of two points
point midpoint(point p1, point p2) {
  point res;
  res.x = (p1.x + p2.x) / 2;
  res.y = (p1.y + p2.y) / 2;
  return res;
}

// Check if three points form a triangle
int is_triangle(point p1, point p2, point p3) {
  double d1 = dist(p1, p2), d2 = dist(p2, p3), d3 = dist(p3, p1);
  return d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1;
}

// Print a point in the format (x, y)
void print_point(point p) {
  printf("(%lf, %lf)", p.x, p.y);
}

// Generate random points within a square with side length 'len'
point random_point(double len) {
  point p;
  p.x = (double) rand() / RAND_MAX * len;
  p.y = (double) rand() / RAND_MAX * len;
  return p;
}

int main() {
  srand(time(NULL));
  double side_len = 10;
  int num_points = 100;
  point *points = malloc(num_points * sizeof(point));

  printf("Randomly generated %d points within a square of side length %lf:\n", num_points, side_len);
  for (int i = 0; i < num_points; ++i) {
    point p = random_point(side_len);
    points[i] = p;
    if (i > 0) {
      point prev = points[i - 1];
      if (is_triangle(prev, p, points[i % num_points])) {
        printf("Points %d and %d, and %d form a triangle.\n", i - 1, i, i % num_points);
        print_point(prev);
        printf(", ");
        print_point(p);
        printf(", and ");
        print_point(points[i % num_points]);
        printf(".\n");
      }
    }
  }

  free(points);
  return 0;
}