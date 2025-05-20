//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>
#include <math.h>

// define a structure for 2D points
typedef struct {
    double x;
    double y;
} Point;

// define a function to find the distance between two points
double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // dynamically allocate memory for an array of n points
    Point *points = (Point*) malloc(n * sizeof(Point));

    // prompt the user to enter n points
    printf("Enter %d points in the format x,y:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf,%lf", &points[i].x, &points[i].y);
    }

    // find the convex hull of the points using the Graham scan algorithm
    // first, sort the points lexicographically by their (x,y) coordinates
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((points[i].x > points[j].x) || ((points[i].x == points[j].x) && (points[i].y > points[j].y))) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    // initialize a stack for the points used in the convex hull
    Point *stack = (Point*) malloc(n * sizeof(Point));
    int top = -1;

    // push the first two points onto the stack
    stack[++top] = points[0];
    stack[++top] = points[1];

    // iterate through the remaining points and add them to the convex hull
    for (int i = 2; i < n; i++) {
        while (top >= 1 && ((points[i].y - stack[top].y) * (stack[top].x - stack[top-1].x) <
                (stack[top].y - stack[top-1].y) * (points[i].x - stack[top].x))) {
            top--;
        }
        stack[++top] = points[i];
    }

    // print out the points on the convex hull in clockwise order
    printf("The points on the convex hull are:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%lf,%lf)\n", stack[i].x, stack[i].y);
    }

    // calculate the perimeter of the convex hull
    double perimeter = 0.0;
    for (int i = 0; i <= top; i++) {
        perimeter += distance(stack[i], stack[(i+1)%(top+1)]);
    }
    printf("The perimeter of the convex hull is %lf\n", perimeter);

    return 0;
}