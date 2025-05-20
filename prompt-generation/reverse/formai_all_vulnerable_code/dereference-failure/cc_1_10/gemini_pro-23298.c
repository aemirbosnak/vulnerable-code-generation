//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
// Convex Hull (Graham's Scan)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
  double x, y;
} Point;

bool cw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

bool ccw(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
}

double dist(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int cmp(const void *a, const void *b) {
  Point *p1 = (Point *)a;
  Point *p2 = (Point *)b;
  return (p1->x == p2->x) ? p1->y - p2->y : p1->x - p2->x;
}

Point *convexHull(Point *points, int n) {
  if (n <= 2) return points;

  qsort(points, n, sizeof(Point), cmp);

  int m = 0;
  Point *hull = malloc(sizeof(Point) * n);

  for (int i = 0; i < n; i++) {
    while (m >= 2 && cw(hull[m - 2], hull[m - 1], points[i])) m--;
    hull[m++] = points[i];
  }

  for (int i = n - 2, t = m + 1; i >= 0; i--) {
    while (m >= t && cw(hull[m - 2], hull[m - 1], points[i])) m--;
    hull[m++] = points[i];
  }

  return hull;
}

int main() {
  int n;
  scanf("%d", &n);

  Point *points = malloc(sizeof(Point) * n);
  for (int i = 0; i < n; i++) scanf("%lf %lf", &points[i].x, &points[i].y);

  Point *hull = convexHull(points, n);

  for (int i = 0; i < n; i++) printf("%.2lf %.2lf\n", hull[i].x, hull[i].y);

  return 0;
}