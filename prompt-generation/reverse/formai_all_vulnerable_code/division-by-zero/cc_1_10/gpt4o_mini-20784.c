//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    int x;
    int y;
} Point;

// Function to compare two points based on their coordinates
int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->x == p2->x) ? (p1->y - p2->y) : (p1->x - p2->x);
}

// Function to find the orientation of the ordered triplet (p, q, r)
// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

// Function to return the convex hull using the Gift Wrapping algorithm
void convexHull(Point points[], int n) {
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;
    printf("The points in the convex hull are:\n");
    
    do {
        // Print the current point
        printf("(%d, %d)\n", points[p].x, points[p].y);
        // Search for a point 'q' such that orientation(p, x, q) is counterclockwise
        q = (p + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        // Set p as q for the next iteration
        p = q;

    } while (p != l); // While we don't come to first point
}

// Function to read points from user
void readPoints(Point points[], int *n) {
    printf("Enter the number of points: ");
    scanf("%d", n);
    printf("Enter the points (x y format):\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

int main() {
    Point points[100];
    int n;

    readPoints(points, &n);

    // Sort points
    qsort(points, n, sizeof(Point), compare);

    // Find and print the convex hull
    convexHull(points, n);

    return 0;
}