//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* vertices;
    int num_vertices;
} Polygon;

// Function prototypes
Polygon* create_polygon(int num_vertices);
void set_vertex(Polygon* poly, int index, double x, double y);
void free_polygon(Polygon* poly);
double polygon_area(Polygon* poly);
int is_point_in_polygon(Polygon* poly, Point p);
void print_polygon(Polygon* poly);

int main() {
    int num_vertices;
    printf("Enter the number of vertices for the polygon: ");
    scanf("%d", &num_vertices);

    Polygon* poly = create_polygon(num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        double x, y;
        printf("Enter vertex %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        set_vertex(poly, i, x, y);
    }
    
    printf("\nThe vertices of the polygon are:\n");
    print_polygon(poly);

    double area = polygon_area(poly);
    printf("\nThe area of the polygon is: %.2lf\n", area);

    Point p;
    printf("Enter a point to test (x y): ");
    scanf("%lf %lf", &p.x, &p.y);
    
    if (is_point_in_polygon(poly, p)) {
        printf("The point (%.2lf, %.2lf) is inside the polygon.\n", p.x, p.y);
    } else {
        printf("The point (%.2lf, %.2lf) is outside the polygon.\n", p.x, p.y);
    }

    free_polygon(poly);
    return 0;
}

// Function to create a polygon with the specified number of vertices
Polygon* create_polygon(int num_vertices) {
    Polygon* poly = malloc(sizeof(Polygon));
    poly->vertices = malloc(num_vertices * sizeof(Point));
    poly->num_vertices = num_vertices;
    return poly;
}

// Function to set a vertex of the polygon
void set_vertex(Polygon* poly, int index, double x, double y) {
    if (index >= 0 && index < poly->num_vertices) {
        poly->vertices[index].x = x;
        poly->vertices[index].y = y;
    }
}

// Function to free the allocated memory for the polygon
void free_polygon(Polygon* poly) {
    free(poly->vertices);
    free(poly);
}

// Function to calculate the area of a polygon using the shoelace formula
double polygon_area(Polygon* poly) {
    double area = 0.0;
    int j = poly->num_vertices - 1;  // The last vertex is the 'previous' one to the first
    for (int i = 0; i < poly->num_vertices; i++) {
        area += (poly->vertices[j].x + poly->vertices[i].x) * (poly->vertices[j].y - poly->vertices[i].y);
        j = i;  // j is previous vertex to i
    }
    return fabs(area) / 2.0;  // Absolute value for positive area
}

// Function to print the polygon vertices
void print_polygon(Polygon* poly) {
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Vertex %d: (%.2lf, %.2lf)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

// Function to determine if a point is inside the polygon
int is_point_in_polygon(Polygon* poly, Point p) {
    int count = 0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices;  // Connect to the first vertex
        if (((poly->vertices[i].y > p.y) != (poly->vertices[j].y > p.y)) &&
            (p.x < (poly->vertices[j].x - poly->vertices[i].x) * (p.y - poly->vertices[i].y) /
            (poly->vertices[j].y - poly->vertices[i].y) + poly->vertices[i].x)) {
            count++;
        }
    }
    return count % 2;  // Even count means outside, odd count means inside
}