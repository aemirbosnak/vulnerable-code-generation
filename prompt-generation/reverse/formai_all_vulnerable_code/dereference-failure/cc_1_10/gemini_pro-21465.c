//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef double real;

void rand_init(unsigned int *seed) {
  struct timespec ts;
  clock_gettime(CLOCK_REALTIME, &ts);
  *seed ^= ts.tv_sec ^ ts.tv_nsec;
}

unsigned int rand_next(unsigned int *seed) {
  *seed ^= (*seed >> 13);
  *seed ^= (*seed << 17);
  *seed ^= (*seed >> 5);
  return *seed;
}

real rand_real(unsigned int *seed) {
  return rand_next(seed) / (4294967296.0);
}

typedef struct Point2D {
  real x;
  real y;
} Point2D;

typedef struct Circle {
  Point2D center;
  real radius;
} Circle;

typedef struct Rectangle {
  Point2D min;
  Point2D max;
} Rectangle;

int circle_intersects_rectangle(const Circle *circle, const Rectangle *rectangle) {
  if (rectangle->min.x > circle->center.x + circle->radius ||
      rectangle->max.x < circle->center.x - circle->radius ||
      rectangle->min.y > circle->center.y + circle->radius ||
      rectangle->max.y < circle->center.y - circle->radius)
    return 0;
  return 1;
}

int main(int argc, char **argv) {
  unsigned int seed;
  rand_init(&seed);

  int num_circles = 10000;
  int num_rectangles = 1000;
  int num_intersections = 0;

  Circle *circles = malloc(sizeof(Circle) * num_circles);
  for (int i = 0; i < num_circles; i++) {
    circles[i].center.x = rand_real(&seed) * 1000.0;
    circles[i].center.y = rand_real(&seed) * 1000.0;
    circles[i].radius = rand_real(&seed) * 100.0;
  }

  Rectangle *rectangles = malloc(sizeof(Rectangle) * num_rectangles);
  for (int i = 0; i < num_rectangles; i++) {
    rectangles[i].min.x = rand_real(&seed) * 1000.0;
    rectangles[i].min.y = rand_real(&seed) * 1000.0;
    rectangles[i].max.x = rectangles[i].min.x + rand_real(&seed) * 100.0;
    rectangles[i].max.y = rectangles[i].min.y + rand_real(&seed) * 100.0;
  }

  for (int i = 0; i < num_circles; i++) {
    for (int j = 0; j < num_rectangles; j++) {
      if (circle_intersects_rectangle(&circles[i], &rectangles[j]))
        num_intersections++;
    }
  }

  printf("Number of intersections: %d\n", num_intersections);

  free(circles);
  free(rectangles);

  return 0;
}