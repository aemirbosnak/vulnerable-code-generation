//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point in 2D space
typedef struct Point {
    double x;
    double y;
} Point;

// Define a line segment in 2D space
typedef struct LineSegment {
    Point p1;
    Point p2;
} LineSegment;

// Define a polygon in 2D space
typedef struct Polygon {
    int num_vertices;
    Point *vertices;
} Polygon;

// Create a new point in 2D space
Point *point_create(double x, double y) {
    Point *p = malloc(sizeof(Point));
    if (p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

// Create a new line segment in 2D space
LineSegment *line_segment_create(Point *p1, Point *p2) {
    LineSegment *ls = malloc(sizeof(LineSegment));
    if (ls == NULL) {
        return NULL;
    }
    ls->p1 = *p1;
    ls->p2 = *p2;
    return ls;
}

// Create a new polygon in 2D space
Polygon *polygon_create(int num_vertices) {
    Polygon *p = malloc(sizeof(Polygon));
    if (p == NULL) {
        return NULL;
    }
    p->num_vertices = num_vertices;
    p->vertices = malloc(sizeof(Point) * num_vertices);
    if (p->vertices == NULL) {
        free(p);
        return NULL;
    }
    return p;
}

// Free a point in 2D space
void point_free(Point *p) {
    free(p);
}

// Free a line segment in 2D space
void line_segment_free(LineSegment *ls) {
    free(ls);
}

// Free a polygon in 2D space
void polygon_free(Polygon *p) {
    free(p->vertices);
    free(p);
}

// Print a point in 2D space
void point_print(Point *p) {
    printf("(%f, %f)\n", p->x, p->y);
}

// Print a line segment in 2D space
void line_segment_print(LineSegment *ls) {
    printf("Line segment from ");
    point_print(&ls->p1);
    printf(" to ");
    point_print(&ls->p2);
    printf("\n");
}

// Print a polygon in 2D space
void polygon_print(Polygon *p) {
    printf("Polygon with %d vertices:\n", p->num_vertices);
    for (int i = 0; i < p->num_vertices; i++) {
        point_print(&p->vertices[i]);
    }
    printf("\n");
}

// Compute the distance between two points in 2D space
double point_distance(Point *p1, Point *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}

// Compute the area of a triangle in 2D space
double triangle_area(Point *p1, Point *p2, Point *p3) {
    double a = point_distance(p1, p2);
    double b = point_distance(p2, p3);
    double c = point_distance(p3, p1);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

// Check if a point is inside a polygon in 2D space
int point_in_polygon(Point *p, Polygon *poly) {
    int num_intersections = 0;
    for (int i = 0; i < poly->num_vertices; i++) {
        LineSegment ls = {poly->vertices[i], poly->vertices[(i + 1) % poly->num_vertices]};
        if (line_segment_intersects_ray(ls, p)) {
            num_intersections++;
        }
    }
    return num_intersections % 2 == 1;
}

// Check if two line segments in 2D space intersect
int line_segment_intersects(LineSegment *ls1, LineSegment *ls2) {
    double x1 = ls1->p1.x;
    double y1 = ls1->p1.y;
    double x2 = ls1->p2.x;
    double y2 = ls1->p2.y;
    double x3 = ls2->p1.x;
    double y3 = ls2->p1.y;
    double x4 = ls2->p2.x;
    double y4 = ls2->p2.y;

    double denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (denom == 0) {
        return 0;  // Lines are parallel
    }

    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / denom;
    double u = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / denom;

    return (0 <= t && t <= 1) && (0 <= u && u <= 1);
}

// Check if a line segment in 2D space intersects a ray
int line_segment_intersects_ray(LineSegment *ls, Point *p) {
    double x1 = ls->p1.x;
    double y1 = ls->p1.y;
    double x2 = ls->p2.x;
    double y2 = ls->p2.y;
    double px = p->x;
    double py = p->y;

    double dx = x2 - x1;
    double dy = y2 - y1;
    double t = ((px - x1) * dx + (py - y1) * dy) / (dx * dx + dy * dy);

    if (t < 0 || t > 1) {
        return 0;  // Ray does not intersect line segment
    }

    double x = x1 + t * dx;
    double y = y1 + t * dy;
    return point_distance(p, point_create(x, y)) < 1e-6;
}

// Main function
int main() {
    // Create a point in 2D space
    Point *p = point_create(1.0, 2.0);

    // Print the point
    point_print(p);

    // Free the point
    point_free(p);

    // Create a line segment in 2D space
    LineSegment *ls = line_segment_create(p, point_create(3.0, 4.0));

    // Print the line segment
    line_segment_print(ls);

    // Free the line segment
    line_segment_free(ls);

    // Create a polygon in 2D space
    Polygon *poly = polygon_create(3);
    poly->vertices[0] = *point_create(0.0, 0.0);
    poly->vertices[1] = *point_create(1.0, 0.0);
    poly->vertices[2] = *point_create(1.0, 1.0);

    // Print the polygon
    polygon_print(poly);

    // Free the polygon
    polygon_free(poly);

    return 0;
}