//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Shape Shifting Clustering Algorithm

// Struct to represent a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Struct to represent a cluster of points
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Function to calculate the Euclidean distance between two points
double distance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

// Function to initialize the clusters with random centroids
void init_clusters(Cluster* clusters, int num_clusters, Point* points, int num_points) {
    // Randomly choose initial centroids from the points
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = points[rand() % num_points];
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

// Function to assign each point to the nearest cluster
void assign_points(Cluster* clusters, int num_clusters, Point* points, int num_points) {
    // Assign each point to the nearest cluster
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int nearest_cluster = 0;
        for (int j = 0; j < num_clusters; j++) {
            double d = distance(points[i], clusters[j].centroid);
            if (d < min_distance) {
                min_distance = d;
                nearest_cluster = j;
            }
        }
        // Add point to the nearest cluster
        clusters[nearest_cluster].num_points++;
        clusters[nearest_cluster].points = realloc(clusters[nearest_cluster].points, clusters[nearest_cluster].num_points * sizeof(Point));
        clusters[nearest_cluster].points[clusters[nearest_cluster].num_points - 1] = points[i];
    }
}

// Function to update the centroids of each cluster
void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double avg_x = 0.0;
        double avg_y = 0.0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            avg_x += clusters[i].points[j].x;
            avg_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = avg_x / clusters[i].num_points;
        clusters[i].centroid.y = avg_y / clusters[i].num_points;
        free(clusters[i].points);
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

// Main function to perform Shape Shifting Clustering algorithm
int main() {
    // Generate some random test points
    Point points[] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0} };
    int num_points = sizeof(points) / sizeof(Point);

    // Set the initial number of clusters
    int num_clusters = 2;

    // Initialize the clusters
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    init_clusters(clusters, num_clusters, points, num_points);

    // Keep iterating until convergence
    int iterations = 0;
    while (1) {
        // Assign each point to its nearest cluster
        assign_points(clusters, num_clusters, points, num_points);

        // Update the centroids of each cluster
        update_centroids(clusters, num_clusters);

        // If the number of clusters changes, reinitialize the clusters and start over
        if (num_clusters != 1 && num_clusters != num_points && num_points / num_clusters <= 2) {
            free(clusters);
            num_clusters = num_points % num_clusters;
            clusters = malloc(num_clusters * sizeof(Cluster));
            init_clusters(clusters, num_clusters, points, num_points);
            iterations = 0;
            continue;
        }

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].num_points == 0) {
                // If a cluster has no points, reinitialize the clusters and start over
                free(clusters);
                num_clusters = num_points % num_clusters;
                clusters = malloc(num_clusters * sizeof(Cluster));
                init_clusters(clusters, num_clusters, points, num_points);
                iterations = 0;
                converged = 0;
                break;
            } else if (distance(clusters[i].centroid, points[i % num_points]) > 0.1) {
                converged = 0;
                break;
            }
        }
        if (converged) break;

        iterations++;
        if (iterations > 10000) {
            printf("Maximum iterations reached\n");
            break;
        }
    }

    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i+1);
        printf("Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Points:");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf(" (%.2f, %.2f)", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    free(clusters);
    return 0;
}