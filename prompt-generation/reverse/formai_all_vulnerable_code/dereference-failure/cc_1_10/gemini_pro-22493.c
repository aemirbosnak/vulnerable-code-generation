//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

// Custom data types
typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* points;
    int size, capacity;
} Polygon;

// Function prototypes
Polygon* create_polygon(int capacity);
void free_polygon(Polygon* polygon);
void add_point(Polygon* polygon, Point point);
void print_polygon(Polygon* polygon);
double calculate_area(Polygon* polygon);

int main() {
    // Create a polygon with an initial capacity of 4
    Polygon* polygon = create_polygon(4);

    // Add some points to the polygon
    add_point(polygon, (Point) { 0, 0 });
    add_point(polygon, (Point) { 1, 0 });
    add_point(polygon, (Point) { 1, 1 });
    add_point(polygon, (Point) { 0, 1 });

    // Print the polygon
    print_polygon(polygon);

    // Calculate and print the area of the polygon
    double area = calculate_area(polygon);
    printf("Area: %.2f\n", area);

    // Free the memory allocated for the polygon
    free_polygon(polygon);

    return 0;
}

// Function definitions
Polygon* create_polygon(int capacity) {
    Polygon* polygon = malloc(sizeof(Polygon));
    polygon->points = malloc(sizeof(Point) * capacity);
    polygon->size = 0;
    polygon->capacity = capacity;
    return polygon;
}

void free_polygon(Polygon* polygon) {
    free(polygon->points);
    free(polygon);
}

void add_point(Polygon* polygon, Point point) {
    // Check if the polygon is full
    if (polygon->size == polygon->capacity) {
        // Double the capacity of the polygon
        polygon->capacity *= 2;
        polygon->points = realloc(polygon->points, sizeof(Point) * polygon->capacity);
    }

    // Add the point to the polygon
    polygon->points[polygon->size++] = point;
}

void print_polygon(Polygon* polygon) {
    for (int i = 0; i < polygon->size; i++) {
        printf("(%d, %d) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

double calculate_area(Polygon* polygon) {
    double area = 0;

    for (int i = 0; i < polygon->size; i++) {
        int j = (i + 1) % polygon->size;
        area += polygon->points[i].x * polygon->points[j].y - polygon->points[j].x * polygon->points[i].y;
    }

    return abs(area) / 2.0;
}