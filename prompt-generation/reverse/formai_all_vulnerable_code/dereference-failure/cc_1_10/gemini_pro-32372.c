//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Point p1, p2, p3;
} Triangle;

// Function to create a new point
Point *new_point(double x, double y) {
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

// Function to create a new line
Line *new_line(Point *p1, Point *p2) {
    Line *l = (Line *)malloc(sizeof(Line));
    l->p1 = *p1;
    l->p2 = *p2;
    return l;
}

// Function to create a new triangle
Triangle *new_triangle(Point *p1, Point *p2, Point *p3) {
    Triangle *t = (Triangle *)malloc(sizeof(Triangle));
    t->p1 = *p1;
    t->p2 = *p2;
    t->p3 = *p3;
    return t;
}

// Function to compute the distance between two points
double distance(Point *p1, Point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

// Function to check if two lines intersect
int do_lines_intersect(Line *l1, Line *l2) {
    double x1 = l1->p1.x, y1 = l1->p1.y, x2 = l1->p2.x, y2 = l1->p2.y;
    double x3 = l2->p1.x, y3 = l2->p1.y, x4 = l2->p2.x, y4 = l2->p2.y;

    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (denom == 0) return 0; // Lines are parallel

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
    double u = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;

    return (t >= 0 && t <= 1 && u >= 0 && u <= 1); // Lines intersect
}

// Function to check if a point is inside a triangle
int is_point_in_triangle(Triangle *t, Point *p) {
    double area = fabs((t->p1.x * (t->p2.y - t->p3.y) + t->p2.x * (t->p3.y - t->p1.y) + t->p3.x * (t->p1.y - t->p2.y)) / 2);
    double area1 = fabs((p->x * (t->p2.y - t->p3.y) + t->p2.x * (t->p3.y - p->y) + t->p3.x * (p->y - t->p2.y)) / 2);
    double area2 = fabs((t->p1.x * (p->y - t->p3.y) + p->x * (t->p3.y - t->p1.y) + t->p3.x * (t->p1.y - p->y)) / 2);
    double area3 = fabs((t->p1.x * (t->p2.y - p->y) + t->p2.x * (p->y - t->p1.y) + p->x * (t->p1.y - t->p2.y)) / 2);
    return (area == area1 + area2 + area3); // Point is inside the triangle
}

int main() {
    // Create some points
    Point *p1 = new_point(0, 0);
    Point *p2 = new_point(1, 0);
    Point *p3 = new_point(0, 1);
    Point *p4 = new_point(1, 1);

    // Create some lines
    Line *l1 = new_line(p1, p2);
    Line *l2 = new_line(p3, p4);

    // Check if the lines intersect
    if (do_lines_intersect(l1, l2)) {
        printf("The lines intersect.\n");
    } else {
        printf("The lines do not intersect.\n");
    }

    // Create a triangle
    Triangle *t = new_triangle(p1, p2, p3);

    // Check if the point p4 is inside the triangle
    if (is_point_in_triangle(t, p4)) {
        printf("The point is inside the triangle.\n");
    } else {
        printf("The point is not inside the triangle.\n");
    }

    // Free the memory
    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(l1);
    free(l2);
    free(t);

    return 0;
}