//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

Polygon* create_polygon(int size) {
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    polygon->size = size;
    polygon->points = (Point *)malloc(size * sizeof(Point));
    return polygon;
}

void free_polygon(Polygon *polygon) {
    free(polygon->points);
    free(polygon);
}

void input_polygon(Polygon *polygon) {
    printf("Enter %d points (x y):\n", polygon->size);
    for (int i = 0; i < polygon->size; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &(polygon->points[i].x), &(polygon->points[i].y));
    }
}

void print_polygon(const Polygon *polygon) {
    printf("Polygon Points:\n");
    for (int i = 0; i < polygon->size; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

double calculate_area(const Polygon *polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->size; i++) {
        int next = (i + 1) % polygon->size;
        area += polygon->points[i].x * polygon->points[next].y;
        area -= polygon->points[next].x * polygon->points[i].y;
    }
    return fabs(area) / 2.0;
}

double calculate_perimeter(const Polygon *polygon) {
    double perimeter = 0.0;
    for (int i = 0; i < polygon->size; i++) {
        int next = (i + 1) % polygon->size;
        double dx = polygon->points[next].x - polygon->points[i].x;
        double dy = polygon->points[next].y - polygon->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void print_area_and_perimeter(const Polygon *polygon) {
    double area = calculate_area(polygon);
    double perimeter = calculate_perimeter(polygon);
    printf("Area of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);
}

int main() {
    int num_points;
    
    printf("Enter number of points for the polygon: ");
    scanf("%d", &num_points);

    if (num_points < 3) {
        printf("A polygon must have at least 3 points.\n");
        return 1;
    }

    Polygon *polygon = create_polygon(num_points);
    input_polygon(polygon);
    
    print_polygon(polygon);
    print_area_and_perimeter(polygon);
    
    free_polygon(polygon);
    
    return 0;
}