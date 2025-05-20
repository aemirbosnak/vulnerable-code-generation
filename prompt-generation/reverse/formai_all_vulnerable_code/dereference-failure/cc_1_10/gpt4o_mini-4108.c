//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *vertices;
    int num_vertices;
} Polygon;

// Function to create a polygon
Polygon* create_polygon(int num_vertices) {
    Polygon *poly = (Polygon*)malloc(sizeof(Polygon));
    poly->num_vertices = num_vertices;
    poly->vertices = (Point*)malloc(num_vertices * sizeof(Point));
    return poly;
}

// Function to calculate the area of the polygon using the shoelace formula
double calculate_area(Polygon *poly) {
    double area = 0.0;
    int j = poly->num_vertices - 1; // Last vertex is the previous one to the first
    for (int i = 0; i < poly->num_vertices; i++) {
        area += (poly->vertices[j].x + poly->vertices[i].x) * (poly->vertices[j].y - poly->vertices[i].y);
        j = i; // j is previous vertex to i
    }
    return fabs(area) / 2.0;
}

// Function to calculate the centroid of the polygon
Point calculate_centroid(Polygon *poly) {
    double cx = 0.0, cy = 0.0;
    double area = calculate_area(poly);
    double factor = 0.0;

    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices; // wrap around to the first vertex
        factor = (poly->vertices[i].x * poly->vertices[j].y) - (poly->vertices[j].x * poly->vertices[i].y);
        cx += (poly->vertices[i].x + poly->vertices[j].x) * factor;
        cy += (poly->vertices[i].y + poly->vertices[j].y) * factor;
    }

    area *= 6.0; // Factor to adjust for the area in the centroid calculation
    cx /= area;   // final x coordinate of the centroid
    cy /= area;   // final y coordinate of the centroid

    Point centroid = {cx, cy};
    return centroid;
}

// Function to print the polygon details
void print_polygon(Polygon *poly) {
    printf("Polygon vertices:\n");
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

// Function to free the memory allocated for the polygon
void free_polygon(Polygon *poly) {
    free(poly->vertices);
    free(poly);
}

int main() {
    int num_vertices;

    printf("Enter the number of vertices in the polygon: ");
    scanf("%d", &num_vertices);

    if (num_vertices < 3) {
        fprintf(stderr, "A polygon must have at least 3 vertices.\n");
        return 1;
    }

    Polygon *poly = create_polygon(num_vertices);

    // Input the vertices of the polygon
    for (int i = 0; i < num_vertices; i++) {
        printf("Enter coordinates for vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &poly->vertices[i].x, &poly->vertices[i].y);
    }

    print_polygon(poly);

    double area = calculate_area(poly);
    Point centroid = calculate_centroid(poly);

    printf("Area of the polygon: %.2f\n", area);
    printf("Centroid of the polygon: (%.2f, %.2f)\n", centroid.x, centroid.y);

    free_polygon(poly);
    return 0;
}