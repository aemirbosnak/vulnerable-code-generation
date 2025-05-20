//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point structure
typedef struct {
    double x;
    double y;
} Point;

// Cluster structure
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to assign a point to the nearest cluster
int assign_point(Point point, Cluster* clusters, int num_clusters) {
    double min_distance = INFINITY;
    int nearest_cluster = -1;

    for (int i = 0; i < num_clusters; i++) {
        double distance_to_centroid = distance(point, clusters[i].centroid);
        if (distance_to_centroid < min_distance) {
            min_distance = distance_to_centroid;
            nearest_cluster = i;
        }
    }

    return nearest_cluster;
}

// Function to calculate the new centroid for a cluster
void update_centroid(Cluster* cluster) {
    cluster->centroid.x = 0;
    cluster->centroid.y = 0;

    for (int i = 0; i < cluster->num_points; i++) {
        cluster->centroid.x += cluster->points[i].x;
        cluster->centroid.y += cluster->points[i].y;
    }

    cluster->centroid.x /= cluster->num_points;
    cluster->centroid.y /= cluster->num_points;
}

// Function to perform k-means clustering
void k_means(Point* points, int num_points, int num_clusters) {
    // Initialize clusters
    Cluster* clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = points[i].x;
        clusters[i].centroid.y = points[i].y;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    // Assign points to clusters
    for (int i = 0; i < num_points; i++) {
        int cluster_index = assign_point(points[i], clusters, num_clusters);
        clusters[cluster_index].num_points++;
        clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(Point) * clusters[cluster_index].num_points);
        clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = points[i];
    }

    // Update centroids
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Iterate until convergence
    int converged = 0;
    while (!converged) {
        // Assign points to clusters
        for (int i = 0; i < num_points; i++) {
            int cluster_index = assign_point(points[i], clusters, num_clusters);
            clusters[cluster_index].num_points++;
            clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(Point) * clusters[cluster_index].num_points);
            clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = points[i];
        }

        // Update centroids
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            Point old_centroid = clusters[i].centroid;
            update_centroid(&clusters[i]);
            if (distance(old_centroid, clusters[i].centroid) > 0.01) {
                converged = 0;
            }
        }
    }

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

int main() {
    // Create some data points
    Point points[] = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 7},
        {8, 8},
        {9, 9},
        {10, 10}
    };

    // Perform k-means clustering
    k_means(points, sizeof(points) / sizeof(Point), 3);

    return 0;
}