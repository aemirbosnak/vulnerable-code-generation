//GEMINI-pro DATASET v1.0 Category: Educational ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a custom datatype to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point2D;

// Define a function to create a new point in 2D space
Point2D* new_point2d(double x, double y) {
    Point2D* point = malloc(sizeof(Point2D));
    if (point == NULL) {
        return NULL;
    }
    point->x = x;
    point->y = y;
    return point;
}

// Define a function to free a point in 2D space
void free_point2d(Point2D* point) {
    if (point != NULL) {
        free(point);
    }
}

// Define a function to calculate the distance between two points in 2D space
double distance_between_points2d(Point2D* point1, Point2D* point2) {
    if (point1 == NULL || point2 == NULL) {
        return -1.0;
    }
    double dx = point2->x - point1->x;
    double dy = point2->y - point1->y;
    return sqrt(dx * dx + dy * dy);
}

// Define a function to compare two points in 2D space
int compare_points2d(const void* point1, const void* point2) {
    Point2D* p1 = (Point2D*)point1;
    Point2D* p2 = (Point2D*)point2;
    if (p1->x < p2->x) {
        return -1;
    } else if (p1->x > p2->x) {
        return 1;
    } else {
        if (p1->y < p2->y) {
            return -1;
        } else if (p1->y > p2->y) {
            return 1;
        } else {
            return 0;
        }
    }
}

// Define a function to print a point in 2D space
void print_point2d(Point2D* point) {
    if (point != NULL) {
        printf("(%f, %f)", point->x, point->y);
    }
}

// Define a function to test the point2d functionality
void test_point2d() {
    // Create two points in 2D space
    Point2D* point1 = new_point2d(1.0, 2.0);
    Point2D* point2 = new_point2d(3.0, 4.0);

    // Print the points
    printf("Point 1: ");
    print_point2d(point1);
    printf("\n");
    printf("Point 2: ");
    print_point2d(point2);
    printf("\n");

    // Calculate the distance between the points
    double distance = distance_between_points2d(point1, point2);
    printf("Distance between the points: %f\n", distance);

    // Compare the points
    int comparison = compare_points2d(point1, point2);
    if (comparison == -1) {
        printf("Point 1 is less than point 2\n");
    } else if (comparison == 0) {
        printf("Point 1 is equal to point 2\n");
    } else {
        printf("Point 1 is greater than point 2\n");
    }

    // Free the points
    free_point2d(point1);
    free_point2d(point2);
}

int main() {
    test_point2d();
    return 0;
}