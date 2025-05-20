//Gemma-7B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>

typedef struct Shape {
  int type;
  union {
    struct Circle {
      int radius;
    } circle;
    struct Rectangle {
      int length;
      int width;
    } rectangle;
  } data;
} Shape;

Shape* allocateShape(int type, int size) {
  Shape* shape = (Shape*)malloc(sizeof(Shape) + size);
  shape->type = type;
  switch (type) {
    case 1:
      shape->data.circle.radius = size;
      break;
    case 2:
      shape->data.rectangle.length = size;
      shape->data.rectangle.width = size;
      break;
  }
  return shape;
}

void freeShape(Shape* shape) {
  free(shape);
}

int main() {
  Shape* circle = allocateShape(1, 10);
  circle->data.circle.radius = 5;
  printf("Circle radius: %d\n", circle->data.circle.radius);

  Shape* rectangle = allocateShape(2, 20);
  rectangle->data.rectangle.length = 10;
  rectangle->data.rectangle.width = 20;
  printf("Rectangle length: %d, width: %d\n", rectangle->data.rectangle.length, rectangle->data.rectangle.width);

  freeShape(circle);
  freeShape(rectangle);

  return 0;
}