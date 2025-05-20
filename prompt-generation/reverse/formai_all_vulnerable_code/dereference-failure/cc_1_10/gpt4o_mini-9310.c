//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SHAPE_CIRCLE,
    SHAPE_RECTANGLE,
    SHAPE_TRIANGLE,
    SHAPE_INVALID
} ShapeType;

typedef struct {
    ShapeType type;
    union {
        struct {
            float radius;
        } circle;
        struct {
            float length;
            float width;
        } rectangle;
        struct {
            float base;
            float height;
        } triangle;
    } data;
} Shape;

// Function prototypes
void handle_error(const char *message);
Shape* create_shape(ShapeType type);
void calculate_area(Shape *shape);
void release_shape(Shape *shape);

int main() {
    Shape *shapes[3];

    // Create a circle
    shapes[0] = create_shape(SHAPE_CIRCLE);
    shapes[0]->data.circle.radius = 5.0;

    // Create a rectangle
    shapes[1] = create_shape(SHAPE_RECTANGLE);
    shapes[1]->data.rectangle.length = 4.0;
    shapes[1]->data.rectangle.width = 6.0;

    // Create a triangle
    shapes[2] = create_shape(SHAPE_TRIANGLE);
    shapes[2]->data.triangle.base = 3.0;
    shapes[2]->data.triangle.height = 4.0;

    // Calculate areas and handle errors
    for (int i = 0; i < 3; i++) {
        if (shapes[i]) {
            calculate_area(shapes[i]);
        }
    }

    // Release shapes
    for (int i = 0; i < 3; i++) {
        release_shape(shapes[i]);
    }

    return 0;
}

// Handle error messages and exit
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Create a shape and check for allocation errors
Shape* create_shape(ShapeType type) {
    Shape *shape = malloc(sizeof(Shape));
    if (!shape) {
        handle_error("Failed to allocate memory for shape.");
    }

    shape->type = type;

    return shape;
}

// Calculate area based on shape type and handle unexpected types
void calculate_area(Shape *shape) {
    if (!shape) {
        handle_error("Null shape reference.");
    }

    float area = 0;

    switch (shape->type) {
        case SHAPE_CIRCLE:
            area = 3.14159f * shape->data.circle.radius * shape->data.circle.radius;
            printf("Circle Area: %.2f\n", area);
            break;
        case SHAPE_RECTANGLE:
            area = shape->data.rectangle.length * shape->data.rectangle.width;
            printf("Rectangle Area: %.2f\n", area);
            break;
        case SHAPE_TRIANGLE:
            area = 0.5f * shape->data.triangle.base * shape->data.triangle.height;
            printf("Triangle Area: %.2f\n", area);
            break;
        default:
            handle_error("Invalid shape type encountered during area calculation.");
    }
}

// Release shape resources safely
void release_shape(Shape *shape) {
    if (shape) {
        free(shape);
        shape = NULL;
    } else {
        handle_error("Attempted to release a null shape reference.");
    }
}