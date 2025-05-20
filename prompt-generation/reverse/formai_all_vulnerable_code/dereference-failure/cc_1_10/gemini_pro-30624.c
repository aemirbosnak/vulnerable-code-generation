//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complex
// Complex C Clustering Algorithm Implementation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a data point
typedef struct {
    double x;
    double y;
} Point;

// Define a cluster
typedef struct {
    Point centroid;
    int num_points;
    Point* points;
} Cluster;

// Create a new cluster
Cluster* create_cluster(Point centroid, int num_points, Point* points) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_points = num_points;
    cluster->points = (Point*)malloc(sizeof(Point) * num_points);
    for (int i = 0; i < num_points; i++) {
        cluster->points[i] = points[i];
    }
    return cluster;
}

// Free a cluster
void free_cluster(Cluster* cluster) {
    free(cluster->points);
    free(cluster);
}

// Calculate the distance between two points
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Assign a point to a cluster
void assign_point_to_cluster(Point point, Cluster* cluster) {
    double min_distance = distance(point, cluster->centroid);
    for (int i = 0; i < cluster->num_points; i++) {
        double distance_to_point = distance(point, cluster->points[i]);
        if (distance_to_point < min_distance) {
            min_distance = distance_to_point;
            cluster->centroid = cluster->points[i];
        }
    }
    cluster->num_points++;
}

// Calculate the centroid of a cluster
void calculate_centroid(Cluster* cluster) {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }
    cluster->centroid.x = sum_x / cluster->num_points;
    cluster->centroid.y = sum_y / cluster->num_points;
}

// Perform k-means clustering
void k_means_clustering(Point* points, int num_points, int num_clusters) {
    // Initialize clusters
    Cluster** clusters = (Cluster**)malloc(sizeof(Cluster*) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = create_cluster(points[i], 1, &points[i]);
    }

    // Iterate until clusters are stable
    int stable = 0;
    while (!stable) {
        // Assign points to clusters
        for (int i = 0; i < num_points; i++) {
            assign_point_to_cluster(points[i], clusters[0]);
        }

        // Calculate centroids
        for (int i = 0; i < num_clusters; i++) {
            calculate_centroid(clusters[i]);
        }

        // Check if clusters are stable
        stable = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i]->centroid.x != clusters[i]->points[0].x || clusters[i]->centroid.y != clusters[i]->points[0].y) {
                stable = 0;
            }
        }
    }

    // Print clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("  (%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
    }

    // Free clusters
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(clusters[i]);
    }
    free(clusters);
}

// Main function
int main() {
    // Initialize data points
    Point points[] = {
        {1.0, 1.0},
        {1.5, 2.0},
        {2.0, 3.0},
        {2.5, 4.0},
        {3.0, 5.0},
        {3.5, 6.0},
        {4.0, 7.0},
        {4.5, 8.0},
        {5.0, 9.0},
        {5.5, 10.0}
    };
    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering
    int num_clusters = 3;
    k_means_clustering(points, num_points, num_clusters);

    return 0;
}