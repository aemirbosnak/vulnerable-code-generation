//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int count;
} Polygon;

// Function prototypes
Polygon *create_polygon(int num_points);
void free_polygon(Polygon *poly);
void add_point(Polygon *poly, int index, double x, double y);
double calculate_area(Polygon *poly);
double calculate_perimeter(Polygon *poly);
void display_polygon(Polygon *poly);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    int num_points = atoi(argv[1]);
    if (num_points < 3) {
        printf("A polygon must have at least 3 points.\n");
        return EXIT_FAILURE;
    }

    Polygon *my_polygon = create_polygon(num_points);

    printf("Enter the coordinates of the polygon points:\n");
    for (int i = 0; i < my_polygon->count; i++) {
        double x, y;
        printf("Point %d (x y): ", i + 1);
        scanf("%lf %lf", &x, &y);
        add_point(my_polygon, i, x, y);
    }

    printf("Polygon points:\n");
    display_polygon(my_polygon);

    double area = calculate_area(my_polygon);
    double perimeter = calculate_perimeter(my_polygon);

    printf("Area of the polygon: %.2f\n", area);
    printf("Perimeter of the polygon: %.2f\n", perimeter);

    free_polygon(my_polygon);
    return EXIT_SUCCESS;
}

Polygon *create_polygon(int num_points) {
    Polygon *poly = (Polygon *)malloc(sizeof(Polygon));
    if (!poly) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    poly->points = (Point *)malloc(sizeof(Point) * num_points);
    if (!poly->points) {
        free(poly);
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    poly->count = num_points;
    return poly;
}

void free_polygon(Polygon *poly) {
    free(poly->points);
    free(poly);
}

void add_point(Polygon *poly, int index, double x, double y) {
    if (index < poly->count) {
        poly->points[index].x = x;
        poly->points[index].y = y;
    }
}

double calculate_area(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count; // next vertex
        area += (poly->points[i].x * poly->points[j].y);
        area -= (poly->points[j].x * poly->points[i].y);
    }
    return fabs(area) / 2.0;
}

double calculate_perimeter(Polygon *poly) {
    double perimeter = 0.0;
    for (int i = 0; i < poly->count; i++) {
        int j = (i + 1) % poly->count; // next vertex
        double dx = poly->points[j].x - poly->points[i].x;
        double dy = poly->points[j].y - poly->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

void display_polygon(Polygon *poly) {
    for (int i = 0; i < poly->count; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, poly->points[i].x, poly->points[i].y);
    }
}

void print_usage() {
    printf("Usage: polygon_area_perimeter <number_of_points>\n");
    printf("Example: polygon_area_perimeter 4\n");
    printf("This program calculates the area and perimeter of a polygon defined by its vertices.\n");
}