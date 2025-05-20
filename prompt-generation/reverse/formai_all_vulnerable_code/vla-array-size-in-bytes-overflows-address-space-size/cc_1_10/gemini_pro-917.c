//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x;
  double y;
} point;

typedef struct {
  point a;
  point b;
} line;

double distance(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int intersect(line l1, line l2) {
  double x1 = l1.a.x;
  double y1 = l1.a.y;
  double x2 = l1.b.x;
  double y2 = l1.b.y;
  double x3 = l2.a.x;
  double y3 = l2.a.y;
  double x4 = l2.b.x;
  double y4 = l2.b.y;

  double t1 = ((x3 - x1) * (y2 - y1) - (y3 - y1) * (x2 - x1)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
  double t2 = ((x1 - x3) * (y4 - y3) - (y1 - y3) * (x4 - x3)) / ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

  return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}

int main() {
  int n, i, j;
  scanf("%d", &n);

  point points[n];
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  int intersections = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      line l1 = {points[i], points[j]};
      intersections += intersect(l1, l1);
    }
  }

  printf("%d\n", intersections);

  return 0;
}