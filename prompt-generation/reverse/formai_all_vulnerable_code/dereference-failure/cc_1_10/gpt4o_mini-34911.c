//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x, y;
} Point;

// Function to compare points based on their polar angle
int compare(const void *p1, const void *p2) {
    Point *point1 = (Point *)p1;
    Point *point2 = (Point *)p2;
    if (point1->y == point2->y) {
        return point1->x - point2->x;
    }
    return point1->y - point2->y;
}

// Function to determine the orientation of the triplet (p, q, r)
// Returns a positive value if r is to the left of line pq,
// negative if to the right, and zero if they are collinear
int orientation(Point p, Point q, Point r) {
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

// Function to find the convex hull using the Graham scan algorithm
void convexHull(Point points[], int n) {
    // Step 1: Find the point with the lowest y-coordinate
    Point pivot = points[0];
    for (int i = 1; i < n; i++) {
        if (points[i].y < pivot.y || (points[i].y == pivot.y && points[i].x < pivot.x)) {
            pivot = points[i];
        }
    }

    // Step 2: Sort points based on polar angle with respect to pivot
    qsort(points, n, sizeof(Point), compare);

    // Step 3: Create an empty stack to store the points of the convex hull
    Point *stack = malloc(n * sizeof(Point));
    int top = -1;

    // Step 4: Iterate through sorted points and maintain the convex hull
    for (int i = 0; i < n; i++) {
        while (top >= 1 && orientation(stack[top - 1], stack[top], points[i]) <= 0) {
            top--; // Pop from stack if we have a non-left turn
        }
        stack[++top] = points[i]; // Push current point to stack
    }

    // Step 5: Print the points in the convex hull
    printf("Convex Hull:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
    }

    // Free the allocated memory
    free(stack);
}

int main() {
    int n;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = malloc(n * sizeof(Point));

    printf("Enter the points (x y):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    convexHull(points, n);

    // Free the allocated memory before exiting
    free(points);
    return 0;
}