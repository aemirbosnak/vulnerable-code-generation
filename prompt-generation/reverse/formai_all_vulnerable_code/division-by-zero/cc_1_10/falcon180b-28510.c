//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEVEL 20
#define SCALE 0.8
#define MAX_SIZE 1000000

typedef struct {
  int x, y;
} Point;

void drawLine(Point p1, Point p2, int color) {
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  int steps = abs(dx) + abs(dy);

  if (steps == 0) {
    printf("\033[0;%dm ", color);
    printf("\033[0m");
    return;
  }

  int x = p1.x;
  int y = p1.y;
  int i = 0;

  while (i < steps) {
    printf("\033[0;%dm ", color);
    x += dx / steps;
    y += dy / steps;
    i++;
  }

  printf("\033[0m");
}

void drawTriangle(Point p1, Point p2, Point p3, int color) {
  drawLine(p1, p2, color);
  drawLine(p2, p3, color);
  drawLine(p3, p1, color);
}

void fractal(int level, Point p, int color) {
  if (level == 0) {
    drawTriangle(p, p, p, color);
    return;
  }

  Point a = (Point) { p.x, p.y - 1 };
  Point b = (Point) { p.x - 1, p.y };
  Point c = (Point) { p.x + 1, p.y };

  fractal(level - 1, a, color);
  fractal(level - 1, b, color);
  fractal(level - 1, c, color);
}

int main() {
  int width, height;
  printf("Enter the width and height of the fractal: ");
  scanf("%d %d", &width, &height);

  int size = (int) pow(2, MAX_LEVEL) * (MAX_SIZE / (width * height));
  int max_level = log2(size / 3);

  Point center = (Point) { width / 2, height / 2 };
  fractal(max_level, center, 1);

  return 0;
}