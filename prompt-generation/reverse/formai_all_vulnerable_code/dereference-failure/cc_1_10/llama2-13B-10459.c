//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Structure to represent a line segment
typedef struct {
    int x1, y1;  // Start coordinates of the line segment
    int x2, y2;  // End coordinates of the line segment
} line_segment_t;

// Function to find the intersection of two line segments
line_segment_t *line_segments_intersect(line_segment_t *ls1, line_segment_t *ls2) {
    // Calculate the direction vectors of the two line segments
    int dx1 = ls1->x2 - ls1->x1;
    int dy1 = ls1->y2 - ls1->y1;
    int dx2 = ls2->x2 - ls2->x1;
    int dy2 = ls2->y2 - ls2->y1;

    // Calculate the cross product of the two direction vectors
    int dx = dx1 * dy2 - dx2 * dy1;
    int dy = dx1 * dx2 - dy1 * dy2;

    // Check if the line segments are parallel
    if (dx == 0 && dy == 0) {
        // If the line segments are parallel, they do not intersect
        return NULL;
    }

    // Calculate the intersection point
    int x = ls1->x1 + dx / (double)dy;
    int y = ls1->y1 + dy / (double)dx;

    // Create a new line segment structure to represent the intersection
    line_segment_t *intersection = malloc(sizeof(line_segment_t));
    intersection->x1 = x;
    intersection->y1 = y;
    intersection->x2 = ls1->x2;
    intersection->y2 = ls1->y2;

    return intersection;
}

int main() {
    // Create two line segments
    line_segment_t ls1 = {100, 100, 200, 200};
    line_segment_t ls2 = {300, 300, 400, 400};

    // Find the intersection of the two line segments
    line_segment_t *intersection = line_segments_intersect(&ls1, &ls2);

    // Print the intersection point
    printf("Intersection point: (%d, %d)\n", intersection->x1, intersection->y1);

    return 0;
}