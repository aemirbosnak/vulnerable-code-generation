//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct line {
    point p1;
    point p2;
} line;

typedef struct triangle {
    point p1;
    point p2;
    point p3;
} triangle;

typedef struct circle {
    point center;
    double radius;
} circle;

// Function to create a new point with the given coordinates
point* createPoint(double x, double y) {
    point *p = (point*)malloc(sizeof(point));

    p->x = x;
    p->y = y;

    return p;
}

// Function to create a new line with the given points
line* createLine(point *p1, point *p2) {
    line *l = (line*)malloc(sizeof(line));

    l->p1 = *p1;
    l->p2 = *p2;

    return l;
}

// Function to create a new triangle with the given points
triangle* createTriangle(point *p1, point *p2, point *p3) {
    triangle *t = (triangle*)malloc(sizeof(triangle));

    t->p1 = *p1;
    t->p2 = *p2;
    t->p3 = *p3;

    return t;
}

// Function to create a new circle with the given center and radius
circle* createCircle(point *center, double radius) {
    circle *c = (circle*)malloc(sizeof(circle));

    c->center = *center;
    c->radius = radius;

    return c;
}

// Function to calculate the distance between two points
double distance(point *p1, point *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;

    return sqrt(dx * dx + dy * dy);
}

// Function to check if two lines intersect
int linesIntersect(line *l1, line *l2) {
    double x1 = l1->p1.x;
    double y1 = l1->p1.y;
    double x2 = l1->p2.x;
    double y2 = l1->p2.y;
    double x3 = l2->p1.x;
    double y3 = l2->p1.y;
    double x4 = l2->p2.x;
    double y4 = l2->p2.y;

    double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

    if (denominator == 0) {
        return 0; // Lines are parallel
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denominator;
    double u = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denominator;

    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        return 1; // Lines intersect
    }

    return 0; // Lines do not intersect
}

// Function to check if a point is inside a circle
int pointInCircle(point *p, circle *c) {
    double dx = p->x - c->center.x;
    double dy = p->y - c->center.y;

    double distance_squared = dx * dx + dy * dy;

    if (distance_squared <= c->radius * c->radius) {
        return 1; // Point is inside the circle
    }

    return 0; // Point is outside the circle
}

// Function to check if a triangle is inside a circle
int triangleInCircle(triangle *t, circle *c) {
    if (pointInCircle(&t->p1, c) && pointInCircle(&t->p2, c) && pointInCircle(&t->p3, c)) {
        return 1; // Triangle is inside the circle
    }

    return 0; // Triangle is outside the circle
}

int main() {
    // Create the points
    point *p1 = createPoint(0, 0);
    point *p2 = createPoint(1, 0);
    point *p3 = createPoint(0, 1);
    point *p4 = createPoint(1, 1);

    // Create the lines
    line *l1 = createLine(p1, p2);
    line *l2 = createLine(p3, p4);

    // Create the triangle
    triangle *t = createTriangle(p1, p2, p3);

    // Create the circle
    point *c = createPoint(0.5, 0.5);
    circle *circle = createCircle(c, 0.5);

    // Check if the lines intersect
    if (linesIntersect(l1, l2)) {
        printf("The lines intersect\n");
    } else {
        printf("The lines do not intersect\n");
    }

    // Check if the point is inside the circle
    if (pointInCircle(p1, circle)) {
        printf("The point is inside the circle\n");
    } else {
        printf("The point is outside the circle\n");
    }

    // Check if the triangle is inside the circle
    if (triangleInCircle(t, circle)) {
        printf("The triangle is inside the circle\n");
    } else {
        printf("The triangle is outside the circle\n");
    }

    return 0;
}