//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a 2D point structure
typedef struct {
    double x;
    double y;
} Point;

// Define a line segment structure
typedef struct {
    Point p1;
    Point p2;
} LineSegment;

// Function to create a new point
Point *new_point(double x, double y) {
    Point *p = malloc(sizeof(Point));
    if (p == NULL) {
        return NULL;
    }
    p->x = x;
    p->y = y;
    return p;
}

// Function to create a new line segment
LineSegment *new_line_segment(Point *p1, Point *p2) {
    LineSegment *ls = malloc(sizeof(LineSegment));
    if (ls == NULL) {
        return NULL;
    }
    ls->p1 = *p1;
    ls->p2 = *p2;
    return ls;
}

// Function to calculate the distance between two points
double distance(Point *p1, Point *p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

// Function to check if a point is on a line segment
int is_on_line_segment(Point *p, LineSegment *ls) {
    // Check if the point is between the endpoints of the line segment
    if (p->x >= fmin(ls->p1.x, ls->p2.x) && p->x <= fmax(ls->p1.x, ls->p2.x) && p->y >= fmin(ls->p1.y, ls->p2.y) && p->y <= fmax(ls->p1.y, ls->p2.y)) {
        // Check if the point is on the line
        if (fabs((ls->p2.y - ls->p1.y) * (p->x - ls->p1.x) - (ls->p2.x - ls->p1.x) * (p->y - ls->p1.y)) < 1e-6) {
            return 1;
        }
    }
    return 0;
}

// Function to check if two line segments intersect
int do_line_segments_intersect(LineSegment *ls1, LineSegment *ls2) {
    // Check if the endpoints of one line segment are on the other line segment
    if (is_on_line_segment(&ls1->p1, ls2) || is_on_line_segment(&ls1->p2, ls2) || is_on_line_segment(&ls2->p1, ls1) || is_on_line_segment(&ls2->p2, ls1)) {
        return 1;
    }
    // Check if the line segments cross each other
    double d1 = (ls2->p2.x - ls2->p1.x) * (ls1->p1.y - ls2->p1.y) - (ls2->p2.y - ls2->p1.y) * (ls1->p1.x - ls2->p1.x);
    double d2 = (ls2->p2.x - ls2->p1.x) * (ls1->p2.y - ls2->p1.y) - (ls2->p2.y - ls2->p1.y) * (ls1->p2.x - ls2->p1.x);
    double d3 = (ls1->p2.x - ls1->p1.x) * (ls2->p1.y - ls1->p1.y) - (ls1->p2.y - ls1->p1.y) * (ls2->p1.x - ls1->p1.x);
    double d4 = (ls1->p2.x - ls1->p1.x) * (ls2->p2.y - ls1->p1.y) - (ls1->p2.y - ls1->p1.y) * (ls2->p2.x - ls1->p1.x);
    if (d1 * d2 < 0 && d3 * d4 < 0) {
        return 1;
    }
    return 0;
}

// Main function
int main() {
    // Create two points
    Point *p1 = new_point(0, 0);
    Point *p2 = new_point(10, 10);
    
    // Create two line segments
    LineSegment *ls1 = new_line_segment(p1, p2);
    LineSegment *ls2 = new_line_segment(new_point(5, 5), new_point(15, 5));
    
    // Check if the line segments intersect
    if (do_line_segments_intersect(ls1, ls2)) {
        printf("The line segments intersect.\n");
    } else {
        printf("The line segments do not intersect.\n");
    }
    
    // Free the memory allocated for the points and line segments
    free(p1);
    free(p2);
    free(ls1);
    free(ls2);
    
    return 0;
}