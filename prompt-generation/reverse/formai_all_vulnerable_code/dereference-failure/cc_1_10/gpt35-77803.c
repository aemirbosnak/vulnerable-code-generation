//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compute the area of a triangle given its vertices
double triangle_area(int* vertices) {
    double x1 = (double)vertices[0];
    double y1 = (double)vertices[1];
    double x2 = (double)vertices[2];
    double y2 = (double)vertices[3];
    double x3 = (double)vertices[4];
    double y3 = (double)vertices[5];
    
    // Compute the area using the formula (1/2) * | ( x1(y2-y3) + x2(y3-y1) + x3(y1-y2) ) |
    return 0.5 * abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

// Function to compute the distance between two points given their coordinates
double distance(int* point1, int* point2) {
    double x1 = (double)point1[0];
    double y1 = (double)point1[1];
    double x2 = (double)point2[0];
    double y2 = (double)point2[1];
    
    // Compute the distance using the formula sqrt( (x2 - x1)^2 + (y2 - y1)^2 )
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Async function to compute the minimum bounding circle
void min_bounding_circle(int n, int** points, int* output, int* done) {
    // Randomly shuffle the order of the points
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i + 1);
        int* temp = points[i];
        points[i] = points[j];
        points[j] = temp;
    }
    
    // Initialize the circle (center and radius) to be the first point
    output[0] = points[0][0];
    output[1] = points[0][1];
    output[2] = 0;
    
    // Iterate over the points to update the circle as needed
    for (int i = 1; i < n; i++) {
        int* point = points[i];
        if (distance(output, point) > output[2]) {
            // The point is outside the circle, so update the circle to include it
            output[2] = 0;
            output[0] = point[0];
            output[1] = point[1];
            for (int j = 0; j < i; j++) {
                int* other = points[j];
                if (distance(other, point) > output[2]) {
                    // The two points are outside the circle, so make a new circle centered between them
                    output[0] = (point[0] + other[0]) / 2;
                    output[1] = (point[1] + other[1]) / 2;
                    output[2] = distance(point, other) / 2;
                    for (int k = 0; k < j; k++) {
                        int* mid = points[k];
                        if (distance(mid, point) > output[2] && distance(mid, other) > output[2]) {
                            // The three points are outside the circle, so make a new circle containing all three
                            int* vertices = (int*)malloc(6 * sizeof(int));
                            vertices[0] = point[0]; vertices[1] = point[1];
                            vertices[2] = other[0]; vertices[3] = other[1];
                            vertices[4] = mid[0]; vertices[5] = mid[1];
                            double area = triangle_area(vertices);
                            output[0] = (int)(((double)point[0] * area) + ((double)other[0] * area) + ((double)mid[0] * area)) / (3 * area);
                            output[1] = (int)(((double)point[1] * area) + ((double)other[1] * area) + ((double)mid[1] * area)) / (3 * area);
                            output[2] = distance(point, output);
                            free(vertices);
                        }
                    }
                }
            }
        }
    }
    
    *done = 1;
}

int main() {
    // Define some points to test the algorithm
    int** points = (int**)malloc(5 * sizeof(int*));
    points[0] = (int*)malloc(2 * sizeof(int)); points[0][0] = 1; points[0][1] = 1;
    points[1] = (int*)malloc(2 * sizeof(int)); points[1][0] = 10; points[1][1] = 10; 
    points[2] = (int*)malloc(2 * sizeof(int)); points[2][0] = 3; points[2][1] = 2;
    points[3] = (int*)malloc(2 * sizeof(int)); points[3][0] = 1; points[3][1] = 3;
    points[4] = (int*)malloc(2 * sizeof(int)); points[4][0] = 5; points[4][1] = 5;
    
    // Initialize output and done value for async call
    int* output = (int*)malloc(3 * sizeof(int));
    int done = 0;
    
    // Call the async function to compute the minimum bounding circle
    min_bounding_circle(5, points, output, &done);
    
    // Wait for async function to finish
    while (!done) {}
    
    // Print the result
    printf("Center: (%d, %d)\nRadius: %d\n", output[0], output[1], output[2]);
    
    // Free memory
    for (int i = 0; i < 5; i++) {
        free(points[i]);
    }
    free(points);
    free(output);
    
    return 0;
}