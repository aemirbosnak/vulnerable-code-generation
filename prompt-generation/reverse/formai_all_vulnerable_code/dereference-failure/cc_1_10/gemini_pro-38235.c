//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point structure
typedef struct {
    double x;
    double y;
} Point;

// Cluster structure
typedef struct {
    Point centroid;
    int num_points;
    Point *points;
} Cluster;

// Function to initialize a point
Point point_init(double x, double y) {
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

// Function to initialize a cluster
Cluster cluster_init(Point centroid, int num_points, Point *points) {
    Cluster cluster;
    cluster.centroid = centroid;
    cluster.num_points = num_points;
    cluster.points = points;
    return cluster;
}

// Function to calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to assign a point to a cluster
int assign_point(Point point, Cluster *clusters, int num_clusters) {
    int closest_cluster = -1;
    double min_distance = INFINITY;
    for (int i = 0; i < num_clusters; i++) {
        double dist = distance(point, clusters[i].centroid);
        if (dist < min_distance) {
            min_distance = dist;
            closest_cluster = i;
        }
    }
    return closest_cluster;
}

// Function to update the centroid of a cluster
void update_centroid(Cluster *cluster) {
    double x = 0, y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        x += cluster->points[i].x;
        y += cluster->points[i].y;
    }
    cluster->centroid.x = x / cluster->num_points;
    cluster->centroid.y = y / cluster->num_points;
}

// Function to k-means clustering
void k_means(Point *points, int num_points, int num_clusters) {
    // Initialize clusters
    Cluster *clusters = malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = cluster_init(points[i], 0, NULL);
    }

    // Assign points to clusters
    for (int i = 0; i < num_points; i++) {
        int cluster_index = assign_point(points[i], clusters, num_clusters);
        clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(Point) * (clusters[cluster_index].num_points + 1));
        clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
    }

    // Update centroids
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Repeat until convergence
    int converged = 0;
    while (!converged) {
        // Assign points to clusters
        for (int i = 0; i < num_points; i++) {
            int cluster_index = assign_point(points[i], clusters, num_clusters);
            if (cluster_index != assign_point(points[i], clusters, num_clusters)) {
                converged = 0;
            }
            clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(Point) * (clusters[cluster_index].num_points + 1));
            clusters[cluster_index].points[clusters[cluster_index].num_points++] = points[i];
        }

        // Update centroids
        for (int i = 0; i < num_clusters; i++) {
            update_centroid(&clusters[i]);
        }
    }

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

// Main function
int main() {
    // Points
    Point points[] = {
        point_init(1, 1),
        point_init(1, 2),
        point_init(1, 3),
        point_init(2, 1),
        point_init(2, 2),
        point_init(2, 3),
        point_init(3, 1),
        point_init(3, 2),
        point_init(3, 3)
    };

    // Number of points
    int num_points = sizeof(points) / sizeof(points[0]);

    // Number of clusters
    int num_clusters = 3;

    // Perform k-means clustering
    k_means(points, num_points, num_clusters);

    return 0;
}