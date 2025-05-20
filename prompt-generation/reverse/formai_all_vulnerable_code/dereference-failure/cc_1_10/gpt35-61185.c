//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Cyberpunk
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// Struct for holding coordinates
struct Point {
    double x;
    double y;
};

// Function to calculate distance between two points
double distance(struct Point p1, struct Point p2) {
    double x_diff = p1.x - p2.x;
    double y_diff = p1.y - p2.y;
    return sqrt(x_diff*x_diff + y_diff*y_diff);
}

// Function to assign each point to a cluster
void assign_clusters(struct Point* points, int n_points, struct Point* centroids, int n_clusters, int* assignments) {
    for (int i = 0; i < n_points; i++) {
        double min_dist = INFINITY;
        for (int j = 0; j < n_clusters; j++) {
            double dist = distance(points[i], centroids[j]);
            if (dist < min_dist) {
                min_dist = dist;
                assignments[i] = j;
            }
        }
    }
}

// Function to update the centroids to the mean of their assigned points
void update_centroids(struct Point* points, int n_points, struct Point* centroids, int n_clusters, int* assignments) {
    for (int i = 0; i < n_clusters; i++) {
        int count = 0;
        double sum_x = 0;
        double sum_y = 0;
        for (int j = 0; j < n_points; j++) {
            if (assignments[j] == i) {
                count++;
                sum_x += points[j].x;
                sum_y += points[j].y;
            }
        }
        centroids[i].x = sum_x / count;
        centroids[i].y = sum_y / count;
    }
}

int main() {
    // Set up random number generator
    srand(time(NULL));

    // Generate some random points
    int n_points = 100;
    struct Point* points = malloc(n_points * sizeof(struct Point));
    for (int i = 0; i < n_points; i++) {
        points[i].x = (double)rand() / RAND_MAX * 100;
        points[i].y = (double)rand() / RAND_MAX * 100;
    }

    // Set up initial centroids
    int n_clusters = 3;
    struct Point* centroids = malloc(n_clusters * sizeof(struct Point));
    for (int i = 0; i < n_clusters; i++) {
        centroids[i].x = (double)rand() / RAND_MAX * 100;
        centroids[i].y = (double)rand() / RAND_MAX * 100;
    }

    // Set up assignments array
    int* assignments = malloc(n_points * sizeof(int));

    // Do clustering (assign clusters and update centroids)
    int max_iterations = 10;
    int iteration = 0;
    while (iteration < max_iterations) {
        assign_clusters(points, n_points, centroids, n_clusters, assignments);
        update_centroids(points, n_points, centroids, n_clusters, assignments);
        iteration++;
    }

    // Print out final assignments and centroids
    printf("Final assignments:\n");
    for (int i = 0; i < n_points; i++) {
        printf("%d ", assignments[i]);
    }
    printf("\n");

    printf("Final centroids:\n");
    for (int i = 0; i < n_clusters; i++) {
        printf("(%f, %f) ", centroids[i].x, centroids[i].y);
    }
    printf("\n");

    // Clean up memory
    free(points);
    free(centroids);
    free(assignments);

    return 0;
}