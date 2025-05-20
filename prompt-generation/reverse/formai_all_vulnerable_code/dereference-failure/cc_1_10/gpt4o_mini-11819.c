//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *type;
    float radius; // for circles
} Circle;

typedef struct {
    char *type;
    float side; // for squares
} Square;

typedef struct {
    char *type;
    float base; // for triangles
    float height;
} Triangle;

typedef struct {
    void *shape;
    char shape_type;
} Shape;

void createCircle(Shape *s) {
    Circle *c = (Circle *)malloc(sizeof(Circle));
    c->type = strdup("Circle");
    c->radius = 0.0f;
    s->shape = c;
    s->shape_type = 'C';
}

void createSquare(Shape *s) {
    Square *sq = (Square *)malloc(sizeof(Square));
    sq->type = strdup("Square");
    sq->side = 0.0f;
    s->shape = sq;
    s->shape_type = 'S';
}

void createTriangle(Shape *s) {
    Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    t->type = strdup("Triangle");
    t->base = 0.0f;
    t->height = 0.0f;
    s->shape = t;
    s->shape_type = 'T';
}

void setCircleAttributes(Circle *c, float radius) {
    c->radius = radius;
}

void setSquareAttributes(Square *sq, float side) {
    sq->side = side;
}

void setTriangleAttributes(Triangle *t, float base, float height) {
    t->base = base;
    t->height = height;
}

void deleteShape(Shape *s) {
    if (s->shape) {
        if (s->shape_type == 'C') {
            Circle *c = (Circle *)s->shape;
            free(c->type);
            free(c);
        } else if (s->shape_type == 'S') {
            Square *sq = (Square *)s->shape;
            free(sq->type);
            free(sq);
        } else if (s->shape_type == 'T') {
            Triangle *t = (Triangle *)s->shape;
            free(t->type);
            free(t);
        }
        s->shape = NULL;
    }
}

void printShapeInfo(Shape *s) {
    if (s->shape_type == 'C') {
        Circle *c = (Circle *)s->shape;
        printf("Shape: %s, Radius: %.2f\n", c->type, c->radius);
    } else if (s->shape_type == 'S') {
        Square *sq = (Square *)s->shape;
        printf("Shape: %s, Side: %.2f\n", sq->type, sq->side);
    } else if (s->shape_type == 'T') {
        Triangle *t = (Triangle *)s->shape;
        printf("Shape: %s, Base: %.2f, Height: %.2f\n", t->type, t->base, t->height);
    } else {
        printf("Unknown shape type.\n");
    }
}

int main() {
    Shape s;
    char choice;
    float attr1, attr2;

    printf("Welcome to the Shape Shifter!\n");

    while (1) {
        printf("Choose a shape to create (C: Circle, S: Square, T: Triangle, Q: Quit): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'C':
                deleteShape(&s); // Clean up any existing shape
                createCircle(&s);
                printf("Enter radius for Circle: ");
                scanf("%f", &attr1);
                setCircleAttributes((Circle *)s.shape, attr1);
                break;

            case 'S':
                deleteShape(&s);
                createSquare(&s);
                printf("Enter side length for Square: ");
                scanf("%f", &attr1);
                setSquareAttributes((Square *)s.shape, attr1);
                break;

            case 'T':
                deleteShape(&s);
                createTriangle(&s);
                printf("Enter the base and height for Triangle: ");
                scanf("%f %f", &attr1, &attr2);
                setTriangleAttributes((Triangle *)s.shape, attr1, attr2);
                break;
            
            case 'Q':
                deleteShape(&s);
                printf("Exiting the Shape Shifter. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
        
        printShapeInfo(&s);
    }

    return 0;
}