//MISTRAL-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct {
    double x, y;
    char name[50];
} Point;

void print_point(Point p) {
    printf("%s: (%5.2f, %5.2f)\n", p.name, p.x, p.y);
}

double euclidean_distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int i, j, k, num_points;
    double max_distance, closest_distance;
    Point *points, p1, p2;

    // Seed random number generator
    srand(time(NULL));

    // Read number of points from user
    printf("Enter number of points: ");
    scanf("%d", &num_points);

    // Allocate memory for points array
    points = (Point*) malloc(num_points * sizeof(Point));

    // Initialize points with random names and positions
    for (i = 0; i < num_points; i++) {
        sprintf(points[i].name, "Point %d", i+1);
        points[i].x = rand() % 100 + 1;
        points[i].y = rand() % 100 + 1;
    }

    // Initialize variables
    max_distance = 0;
    closest_distance = INFINITY;

    // Find closest pair of points
    for (i = 0; i < num_points; i++) {
        p1 = points[i];
        for (j = i+1; j < num_points; j++) {
            p2 = points[j];
            double dist = euclidean_distance(p1, p2);
            if (dist < closest_distance) {
                closest_distance = dist;
                printf("New closest pair found:\n");
                print_point(p1);
                print_point(p2);
                printf("Distance: %5.2f\n", closest_distance);
            }
            if (dist > max_distance) {
                max_distance = dist;
                printf("Maximum distance found:\n");
                print_point(p1);
                print_point(p2);
                printf("Distance: %5.2f\n", max_distance);
            }
        }
    }

    // Free memory
    free(points);

    return 0;
}

// Now, let me tell you a little joke...
// Why don't scientists trust atoms?
// Because they make up everything!