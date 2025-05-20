//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point struct
typedef struct point {
    double x;
    double y;
} point;

// Define a line struct
typedef struct line {
    point p1;
    point p2;
} line;

// Define a circle struct
typedef struct circle {
    point center;
    double radius;
} circle;

// Function to create a new point
point *new_point(double x, double y) {
    point *p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

// Function to create a new line
line *new_line(point *p1, point *p2) {
    line *l = malloc(sizeof(line));
    l->p1 = *p1;
    l->p2 = *p2;
    return l;
}

// Function to create a new circle
circle *new_circle(point *center, double radius) {
    circle *c = malloc(sizeof(circle));
    c->center = *center;
    c->radius = radius;
    return c;
}

// Function to calculate the distance between two points
double distance(point *p1, point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

// Function to check if a point is on a line
int is_on_line(point *p, line *l) {
    return (p->x - l->p1.x) * (l->p2.y - l->p1.y) == (p->y - l->p1.y) * (l->p2.x - l->p1.x);
}

// Function to check if a point is inside a circle
int is_inside_circle(point *p, circle *c) {
    return distance(p, &c->center) <= c->radius;
}

// Function to print a point
void print_point(point *p) {
    printf("(%.2f, %.2f)\n", p->x, p->y);
}

// Function to print a line
void print_line(line *l) {
    printf("Line: ");
    print_point(&l->p1);
    print_point(&l->p2);
}

// Function to print a circle
void print_circle(circle *c) {
    printf("Circle: ");
    print_point(&c->center);
    printf("Radius: %.2f\n", c->radius);
}

// Main function
int main() {
    // Create some points
    point *p1 = new_point(0, 0);
    point *p2 = new_point(3, 4);
    point *p3 = new_point(1, 1);

    // Create a line
    line *l = new_line(p1, p2);

    // Create a circle
    circle *c = new_circle(p3, 2);

    // Print the points
    printf("Point 1: ");
    print_point(p1);
    printf("Point 2: ");
    print_point(p2);
    printf("Point 3: ");
    print_point(p3);

    // Print the line
    print_line(l);

    // Print the circle
    print_circle(c);

    // Check if p3 is on the line
    if (is_on_line(p3, l)) {
        printf("Point 3 is on the line.\n");
    } else {
        printf("Point 3 is not on the line.\n");
    }

    // Check if p3 is inside the circle
    if (is_inside_circle(p3, c)) {
        printf("Point 3 is inside the circle.\n");
    } else {
        printf("Point 3 is not inside the circle.\n");
    }

    // Free the allocated memory
    free(p1);
    free(p2);
    free(p3);
    free(l);
    free(c);

    return 0;
}