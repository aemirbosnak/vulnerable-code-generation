//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the complex number struct
typedef struct complex {
  double real;
  double imag;
} complex;

// Define the shape struct
typedef struct shape {
  int type; // 0 for circle, 1 for square, 2 for triangle
  double radius; // Radius for circle
  double side; // Side length for square
  double base; // Base length for triangle
  double height; // Height for triangle
} shape;

// Define the function to create a circle
shape *create_circle(double radius) {
  shape *circle = malloc(sizeof(shape));
  circle->type = 0;
  circle->radius = radius;
  return circle;
}

// Define the function to create a square
shape *create_square(double side) {
  shape *square = malloc(sizeof(shape));
  square->type = 1;
  square->side = side;
  return square;
}

// Define the function to create a triangle
shape *create_triangle(double base, double height) {
  shape *triangle = malloc(sizeof(shape));
  triangle->type = 2;
  triangle->base = base;
  triangle->height = height;
  return triangle;
}

// Define the function to print the shape
void print_shape(shape *shape) {
  switch (shape->type) {
    case 0:
      printf("Circle with radius %f\n", shape->radius);
      break;
    case 1:
      printf("Square with side length %f\n", shape->side);
      break;
    case 2:
      printf("Triangle with base length %f and height %f\n", shape->base, shape->height);
      break;
  }
}

// Define the function to shift the shape
shape *shape_shift(shape *shape, char direction) {
  printf("Shifting the shape");
  switch (direction) {
    case 'u':
      printf(" upwards\n");
      shape->height += 1;
      break;
    case 'd':
      printf(" downwards\n");
      shape->height -= 1;
      break;
    case 'l':
      printf(" to the left\n");
      shape->base -= 1;
      break;
    case 'r':
      printf(" to the right\n");
      shape->base += 1;
      break;
  }
  return shape;
}

// Define the function to free the memory of the shape
void free_shape(shape *shape) {
  free(shape);
}

int main() {
  // Create a circle
  shape *circle = create_circle(5);

  // Print the circle
  print_shape(circle);

  // Shift the circle upwards
  shape *shifted_circle = shape_shift(circle, 'u');

  // Print the shifted circle
  print_shape(shifted_circle);

  // Free the memory of the circle
  free_shape(shifted_circle);
  free_shape(circle);

  return 0;
}