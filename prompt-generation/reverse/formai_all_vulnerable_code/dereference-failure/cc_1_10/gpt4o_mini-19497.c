//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Shape {
    Point* points;
    int num_points;
} Shape;

Shape* create_shape(int num_points) {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    shape->points = (Point*)malloc(num_points * sizeof(Point));
    shape->num_points = num_points;
    return shape;
}

void free_shape(Shape* shape) {
    free(shape->points);
    free(shape);
}

void read_points(Shape* shape) {
    printf("Enter the coordinates of the points (x y) for the shape:\n");
    for (int i = 0; i < shape->num_points; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &shape->points[i].x, &shape->points[i].y);
    }
}

void print_shape(const Shape* shape) {
    printf("Shape Points:\n");
    for (int i = 0; i < shape->num_points; i++) {
        printf("Point %d: (%.2lf, %.2lf)\n", i + 1, shape->points[i].x, shape->points[i].y);
    }
}

double area_of_polygon(const Shape* shape) {
    double area = 0.0;
    for(int i = 0; i < shape->num_points; i++) {
        int j = (i + 1) % shape->num_points;
        area += shape->points[i].x * shape->points[j].y;
        area -= shape->points[j].x * shape->points[i].y;
    }
    return fabs(area) / 2.0;
}

double perimeter_of_polygon(const Shape* shape) {
    double perimeter = 0.0;
    for(int i = 0; i < shape->num_points; i++) {
        int j = (i + 1) % shape->num_points;
        double dx = shape->points[j].x - shape->points[i].x;
        double dy = shape->points[j].y - shape->points[i].y;
        perimeter += sqrt(dx * dx + dy * dy);
    }
    return perimeter;
}

double circumcircle_radius(const Shape* shape) {
    double max_distance = 0.0;
    int center_index = 0;

    for(int i = 0; i < shape->num_points; i++) {
        double distance = sqrt(shape->points[i].x * shape->points[i].x + 
                               shape->points[i].y * shape->points[i].y);
        if (distance > max_distance) {
            max_distance = distance;
            center_index = i;
        }
    }

    return max_distance; // Radius to the farthest point
}

void rotate_shape(Shape* shape, double angle) {
    double radians = angle * (PI / 180.0);
    double cos_angle = cos(radians);
    double sin_angle = sin(radians);

    for (int i = 0; i < shape->num_points; i++) {
        double x_new = cos_angle * shape->points[i].x - sin_angle * shape->points[i].y;
        double y_new = sin_angle * shape->points[i].x + cos_angle * shape->points[i].y;
        shape->points[i].x = x_new;
        shape->points[i].y = y_new;
    }
}

void translate_shape(Shape* shape, double dx, double dy) {
    for (int i = 0; i < shape->num_points; i++) {
        shape->points[i].x += dx;
        shape->points[i].y += dy;
    }
}

int main() {
    int num_points;
    printf("Enter the number of points for the shape: ");
    scanf("%d", &num_points);

    Shape* shape = create_shape(num_points);
    read_points(shape);
    print_shape(shape);

    double area = area_of_polygon(shape);
    double perimeter = perimeter_of_polygon(shape);
    double radius = circumcircle_radius(shape);

    printf("Area of the polygon: %.2lf\n", area);
    printf("Perimeter of the polygon: %.2lf\n", perimeter);
    printf("Circumcircle radius: %.2lf\n", radius);

    double angle, dx, dy;
    printf("Enter rotation angle (degrees): ");
    scanf("%lf", &angle);
    rotate_shape(shape, angle);
    printf("Shape after rotation:\n");
    print_shape(shape);

    printf("Enter translation (dx dy): ");
    scanf("%lf %lf", &dx, &dy);
    translate_shape(shape, dx, dy);
    printf("Shape after translation:\n");
    print_shape(shape);

    free_shape(shape);
    return 0;
}