//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
// Dive into the realm of C, where we'll embark on an adventure in clustering!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point: a simple structure to represent a data point.
typedef struct {
    double x, y;
} Point;

// Cluster: a collection of points with a centroid.
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Visualize the clusters!
void plot_clusters(Cluster* clusters, int num_clusters) {
    printf("Clusters:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%.2f, %.2f)\n", i+1, clusters[i].centroid.x, clusters[i].centroid.y);
    }
}

// Initialize clusters randomly.
void init_clusters(Point* points, int num_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = points[rand() % num_points].x;
        clusters[i].centroid.y = points[rand() % num_points].y;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

// Assign points to their closest clusters.
void assign_points(Point* points, int num_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_dist = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double dist = sqrt(pow(points[i].x - clusters[j].centroid.x, 2) + pow(points[i].y - clusters[j].centroid.y, 2));
            if (dist < min_dist) {
                min_dist = dist;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].num_points++;
        clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, clusters[closest_cluster].num_points * sizeof(Point));
        clusters[closest_cluster].points[clusters[closest_cluster].num_points-1] = points[i];
    }
}

// Update cluster centroids.
void update_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double cx = 0, cy = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            cx += clusters[i].points[j].x;
            cy += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = cx / clusters[i].num_points;
        clusters[i].centroid.y = cy / clusters[i].num_points;
    }
}

// Main function: let's get clustering!
int main() {
    // Generate some random points.
    int num_points = 100;
    Point* points = malloc(num_points * sizeof(Point));
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Choose the number of clusters.
    int num_clusters = 3;

    // Initialize the clusters.
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    init_clusters(points, num_points, clusters, num_clusters);

    // Iterate over the clustering process.
    int max_iterations = 100;
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        // Assign points to their closest clusters.
        assign_points(points, num_points, clusters, num_clusters);

        // Update the cluster centroids.
        update_centroids(clusters, num_clusters);
        
        // Check for convergence.
        int converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].centroid.x != clusters[i].centroid.x || clusters[i].centroid.y != clusters[i].centroid.y) {
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }
    }

    // Plot the clusters.
    plot_clusters(clusters, num_clusters);

    // Free the allocated memory.
    free(points);
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}