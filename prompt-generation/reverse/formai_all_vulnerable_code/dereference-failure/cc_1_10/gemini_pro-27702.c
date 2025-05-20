//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point struct
typedef struct {
    double x;
    double y;
} point;

// Define the cluster struct
typedef struct {
    int size;
    point* points;
    point centroid;
} cluster;

// Create a new cluster
cluster* create_cluster(int size) {
    cluster* c = malloc(sizeof(cluster));
    c->size = size;
    c->points = malloc(sizeof(point) * size);
    return c;
}

// Free the memory allocated for a cluster
void free_cluster(cluster* c) {
    free(c->points);
    free(c);
}

// Add a point to a cluster
void add_point_to_cluster(cluster* c, point p) {
    c->points[c->size++] = p;
}

// Calculate the centroid of a cluster
void calculate_centroid(cluster* c) {
    double x = 0, y = 0;
    for (int i = 0; i < c->size; i++) {
        x += c->points[i].x;
        y += c->points[i].y;
    }
    c->centroid.x = x / c->size;
    c->centroid.y = y / c->size;
}

// Assign a point to the closest cluster
cluster* assign_point_to_cluster(point p, cluster* clusters, int num_clusters) {
    double min_distance = INFINITY;
    cluster* closest_cluster = NULL;
    for (int i = 0; i < num_clusters; i++) {
        double distance = sqrt(pow(p.x - clusters[i].centroid.x, 2) + pow(p.y - clusters[i].centroid.y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest_cluster = &clusters[i];
        }
    }
    return closest_cluster;
}

// Perform k-means clustering
void k_means(point* points, int num_points, int num_clusters) {
    // Initialize the clusters
    cluster* clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(0);
    }

    // Randomly assign the points to the clusters
    for (int i = 0; i < num_points; i++) {
        int cluster_index = rand() % num_clusters;
        add_point_to_cluster(&clusters[cluster_index], points[i]);
    }

    // Calculate the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        calculate_centroid(&clusters[i]);
    }

    // Iterate until the clusters converge
    int converged = 0;
    while (!converged) {
        // Assign the points to the closest clusters
        for (int i = 0; i < num_points; i++) {
            cluster* closest_cluster = assign_point_to_cluster(points[i], clusters, num_clusters);
            add_point_to_cluster(closest_cluster, points[i]);
        }

        // Calculate the centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            calculate_centroid(&clusters[i]);
        }

        // Check if the clusters have converged
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].size != clusters[i].size) {
                converged = 0;
            }
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);
}

// Main function
int main() {
    // Initialize the points
    point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}, {11, 12}, {13, 14}, {15, 16}, {17, 18}, {19, 20}};
    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering
    int num_clusters = 3;
    k_means(points, num_points, num_clusters);

    return 0;
}