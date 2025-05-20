//Falcon-180B DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about a shape
typedef struct {
    int type;
    int x, y;
    int width, height;
    char color[10];
} Shape;

// Function to create a new shape
Shape* createShape(int type, int x, int y, int width, int height, char color[10]) {
    Shape* shape = (Shape*) malloc(sizeof(Shape));
    if (shape == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    shape->type = type;
    shape->x = x;
    shape->y = y;
    shape->width = width;
    shape->height = height;
    strcpy(shape->color, color);
    return shape;
}

// Function to draw a shape
void drawShape(Shape* shape) {
    printf("Drawing shape: %s (%d, %d) - (%d, %d)\n", shape->color, shape->x, shape->y, shape->x + shape->width, shape->y + shape->height);
}

// Function to free memory used by a shape
void freeShape(Shape* shape) {
    free(shape);
}

// Main function
int main() {
    // Create some shapes
    Shape* circle = createShape(1, 0, 0, 50, 50, "red");
    Shape* square = createShape(2, 100, 100, 100, 100, "blue");
    Shape* triangle = createShape(3, 200, 200, 75, 100, "green");

    // Draw the shapes
    drawShape(circle);
    drawShape(square);
    drawShape(triangle);

    // Free memory used by the shapes
    freeShape(circle);
    freeShape(square);
    freeShape(triangle);

    return 0;
}