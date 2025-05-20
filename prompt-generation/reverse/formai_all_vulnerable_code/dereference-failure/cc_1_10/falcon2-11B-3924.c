//Falcon2-11B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the shape data
typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} Shape;

// Function to print the shape
void printShape(Shape *shape) {
    printf("(x: %d, y: %d, r: %d, g: %d, b: %d)\n", shape->x, shape->y, shape->r, shape->g, shape->b);
}

// Function to initialize the shape with random values
void initializeShape(Shape *shape) {
    shape->x = rand() % 100;
    shape->y = rand() % 100;
    shape->r = rand() % 255;
    shape->g = rand() % 255;
    shape->b = rand() % 255;
}

// Function to create a new shape and print it
void createShape() {
    Shape *newShape = malloc(sizeof(Shape));
    initializeShape(newShape);
    printShape(newShape);
    free(newShape);
}

// Function to change the shape's color to blue
void changeColor(Shape *shape) {
    shape->r = 0;
    shape->g = 0;
    shape->b = 255;
}

// Function to change the shape's position
void changePosition(Shape *shape, int x, int y) {
    shape->x = x;
    shape->y = y;
}

int main() {
    Shape *shape = malloc(sizeof(Shape));
    initializeShape(shape);
    printShape(shape);
    
    changeColor(shape);
    printShape(shape);
    
    changePosition(shape, 50, 50);
    printShape(shape);
    
    free(shape);
    return 0;
}