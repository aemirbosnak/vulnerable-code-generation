//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a point in 2D space
typedef struct {
    double x;
    double y;
} point_t;

// Define a line segment in 2D space
typedef struct {
    point_t p1;
    point_t p2;
} line_t;

// Define a polygon in 2D space
typedef struct {
    int num_vertices;
    point_t *vertices;
} polygon_t;

// Allocate memory for a new point
point_t *point_new(double x, double y) {
    point_t *p = malloc(sizeof(point_t));
    if (p == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for point.\n");
        exit(EXIT_FAILURE);
    }
    p->x = x;
    p->y = y;
    return p;
}

// Free the memory allocated for a point
void point_free(point_t *p) {
    free(p);
}

// Allocate memory for a new line segment
line_t *line_new(point_t p1, point_t p2) {
    line_t *l = malloc(sizeof(line_t));
    if (l == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for line.\n");
        exit(EXIT_FAILURE);
    }
    l->p1 = p1;
    l->p2 = p2;
    return l;
}

// Free the memory allocated for a line segment
void line_free(line_t *l) {
    free(l);
}

// Allocate memory for a new polygon
polygon_t *polygon_new(int num_vertices) {
    polygon_t *p = malloc(sizeof(polygon_t));
    if (p == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for polygon.\n");
        exit(EXIT_FAILURE);
    }
    p->num_vertices = num_vertices;
    p->vertices = malloc(sizeof(point_t) * num_vertices);
    if (p->vertices == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for polygon vertices.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

// Free the memory allocated for a polygon
void polygon_free(polygon_t *p) {
    free(p->vertices);
    free(p);
}

// Print a point to the standard output
void point_print(point_t p) {
    printf("(%.2f, %.2f)", p.x, p.y);
}

// Print a line segment to the standard output
void line_print(line_t l) {
    printf("Line: ");
    point_print(l.p1);
    printf(" - ");
    point_print(l.p2);
    printf("\n");
}

// Print a polygon to the standard output
void polygon_print(polygon_t p) {
    printf("Polygon: ");
    for (int i = 0; i < p.num_vertices; i++) {
        point_print(p.vertices[i]);
        printf(" ");
    }
    printf("\n");
}

// Calculate the distance between two points
double point_distance(point_t p1, point_t p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Calculate the length of a line segment
double line_length(line_t l) {
    return point_distance(l.p1, l.p2);
}

// Calculate the area of a polygon
double polygon_area(polygon_t p) {
    double area = 0.0;
    for (int i = 0; i < p.num_vertices; i++) {
        int j = (i + 1) % p.num_vertices;
        area += p.vertices[i].x * p.vertices[j].y - p.vertices[j].x * p.vertices[i].y;
    }
    return fabs(area) / 2.0;
}

// Check if a point is inside a polygon
int point_in_polygon(point_t p, polygon_t poly) {
    int i, j, c = 0;
    for (i = 0, j = poly.num_vertices - 1; i < poly.num_vertices; j = i++) {
        if (((poly.vertices[i].y <= p.y && p.y < poly.vertices[j].y) ||
             (poly.vertices[j].y <= p.y && p.y < poly.vertices[i].y)) &&
            (p.x < (poly.vertices[j].x - poly.vertices[i].x) * (p.y - poly.vertices[i].y) /
                      (poly.vertices[j].y - poly.vertices[i].y) +
                      poly.vertices[i].x))
            c = !c;
    }
    return c;
}

// Main function
int main(int argc, char **argv) {
    // Create a new point
    point_t p1 = *point_new(0.0, 0.0);

    // Print the point to the standard output
    point_print(p1);
    printf("\n");

    // Free the memory allocated for the point
    point_free(&p1);

    // Create a new line segment
    line_t l1 = *line_new(p1, *point_new(1.0, 1.0));

    // Print the line segment to the standard output
    line_print(l1);

    // Free the memory allocated for the line segment
    line_free(&l1);

    // Create a new polygon
    polygon_t poly1 = *polygon_new(4);

    // Set the vertices of the polygon
    poly1.vertices[0] = *point_new(0.0, 0.0);
    poly1.vertices[1] = *point_new(1.0, 0.0);
    poly1.vertices[2] = *point_new(1.0, 1.0);
    poly1.vertices[3] = *point_new(0.0, 1.0);

    // Print the polygon to the standard output
    polygon_print(poly1);

    // Free the memory allocated for the polygon
    polygon_free(&poly1);

    return 0;
}