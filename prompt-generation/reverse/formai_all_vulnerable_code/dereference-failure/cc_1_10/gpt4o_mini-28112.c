//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to define a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

// Function to sort points based on their x coordinate
int compare(const void *a, const void *b) {
    Point *pointA = (Point *)a;
    Point *pointB = (Point *)b;
    return (pointA->x - pointB->x) > 0 ? 1 : -1;
}

// Function to find the closest pair of points using the divide and conquer method
double closestPair(Point *points, int left, int right) {
    // Base case: if there are 2 or 3 points
    if (right - left <= 3) {
        double minDist = INFINITY;
        for (int i = left; i < right; i++)
            for (int j = i + 1; j < right; j++)
                minDist = fmin(minDist, distance(points[i], points[j]));
        return minDist;
    }

    // Recursive case: split the set of points
    int mid = (left + right) / 2;
    double midX = points[mid].x;

    // Find the closest pair in both halves
    double distLeft = closestPair(points, left, mid);
    double distRight = closestPair(points, mid, right);
    double minDist = fmin(distLeft, distRight);

    // Build an array to hold points within minDist of midX
    Point *strip = malloc((right - left) * sizeof(Point));
    int j = 0;
    for (int i = left; i < right; i++) {
        if (fabs(points[i].x - midX) < minDist) {
            strip[j] = points[i];
            j++;
        }
    }

    // Sort the strip based on y coordinates
    qsort(strip, j, sizeof(Point), compare);

    // Check the strip for potential closer pairs
    for (int i = 0; i < j; i++)
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < minDist; k++)
            minDist = fmin(minDist, distance(strip[i], strip[k]));

    free(strip);
    return minDist;
}

// Main function to drive the program
int main() {
    // Example of generating random points
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    Point *points = malloc(n * sizeof(Point));
    srand(time(NULL)); // Seed for random number generation

    // Generating points within certain bounds
    for (int i = 0; i < n; i++) {
        points[i].x = (double)(rand() % 100);
        points[i].y = (double)(rand() % 100);
        printf("Point %d: (%.2f, %.2f)\n", i + 1, points[i].x, points[i].y);
    }

    // Sorting points by x coordinate
    qsort(points, n, sizeof(Point), compare);

    // Calculating the closest pair distance
    double closestDistance = closestPair(points, 0, n);
    printf("The closest distance between points is: %.2f\n", closestDistance);

    // Cleanup
    free(points);
    return 0;
}