//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *vertices;
    int num_vertices;
} Polygon;

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double polygon_area(Polygon *poly) {
    double area = 0;
    for(int i = 0; i < poly->num_vertices; i++) {
        Point a = poly->vertices[i];
        Point b = poly->vertices[(i + 1) % poly->num_vertices];
        area += (a.x * b.y) - (b.x * a.y);
    }
    return fabs(area) / 2.0;
}

int is_point_in_polygon(Point p, Polygon *poly) {
    int count = 0;
    for (int i = 0; i < poly->num_vertices; i++) {
        Point v1 = poly->vertices[i];
        Point v2 = poly->vertices[(i + 1) % poly->num_vertices];

        if (((v1.y > p.y) != (v2.y > p.y)) && 
            (p.x < (v2.x - v1.x) * (p.y - v1.y) / (v2.y - v1.y) + v1.x)) {
                count++;
        }
    }
    return count % 2;
}

void translate_polygon(Polygon *poly, double tx, double ty) {
    for (int i = 0; i < poly->num_vertices; i++) {
        poly->vertices[i].x += tx;
        poly->vertices[i].y += ty;
    }
}

void rotate_polygon(Polygon *poly, double angle) {
    double radians = angle * (PI / 180.0);
    for (int i = 0; i < poly->num_vertices; i++) {
        double x_old = poly->vertices[i].x;
        double y_old = poly->vertices[i].y;
        poly->vertices[i].x = x_old * cos(radians) - y_old * sin(radians);
        poly->vertices[i].y = x_old * sin(radians) + y_old * cos(radians);
    }
}

Polygon* create_polygon(int num_vertices) {
    Polygon *poly = (Polygon*)malloc(sizeof(Polygon));
    poly->vertices = (Point*)malloc(num_vertices * sizeof(Point));
    poly->num_vertices = num_vertices;
    return poly;
}

void free_polygon(Polygon *poly) {
    free(poly->vertices);
    free(poly);
}

void print_polygon(Polygon *poly) {
    for (int i = 0; i < poly->num_vertices; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, poly->vertices[i].x, poly->vertices[i].y);
    }
}

int main() {
    int num_vertices = 4; 
    Polygon *poly = create_polygon(num_vertices);
    
    poly->vertices[0].x = 0; poly->vertices[0].y = 0; // (0, 0)
    poly->vertices[1].x = 4; poly->vertices[1].y = 0; // (4, 0)
    poly->vertices[2].x = 4; poly->vertices[2].y = 3; // (4, 3)
    poly->vertices[3].x = 0; poly->vertices[3].y = 3; // (0, 3)

    printf("Original Polygon:\n");
    print_polygon(poly);
    
    printf("Area: %.2f\n", polygon_area(poly));
    
    Point p1 = {2, 1}; // Inside the polygon
    Point p2 = {5, 5}; // Outside the polygon
    
    printf("Point (2, 1) is inside the polygon? %s\n", is_point_in_polygon(p1, poly) ? "Yes" : "No");
    printf("Point (5, 5) is inside the polygon? %s\n", is_point_in_polygon(p2, poly) ? "Yes" : "No");
    
    translate_polygon(poly, 2, 1);
    printf("Polygon after translation by (2, 1):\n");
    print_polygon(poly);
    
    rotate_polygon(poly, 90);
    printf("Polygon after rotation by 90 degrees:\n");
    print_polygon(poly);
    
    free_polygon(poly);
    return 0;
}