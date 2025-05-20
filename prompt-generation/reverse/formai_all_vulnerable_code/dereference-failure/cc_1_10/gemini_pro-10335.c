//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct cluster {
    point centroid;
    int num_points;
    point* points;
} cluster;

// Function to calculate the distance between two points
double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the closest cluster to a point
cluster* find_closest_cluster(point p, cluster* clusters, int num_clusters) {
    double min_distance = INFINITY;
    cluster* closest_cluster = NULL;
    for (int i = 0; i < num_clusters; i++) {
        double dist = distance(p, clusters[i].centroid);
        if (dist < min_distance) {
            min_distance = dist;
            closest_cluster = &clusters[i];
        }
    }
    return closest_cluster;
}

// Function to update the centroid of a cluster
void update_centroid(cluster* c) {
    double x = 0;
    double y = 0;
    for (int i = 0; i < c->num_points; i++) {
        x += c->points[i].x;
        y += c->points[i].y;
    }
    c->centroid.x = x / c->num_points;
    c->centroid.y = y / c->num_points;
}

// Function to perform k-means clustering
cluster* kmeans(point* points, int num_points, int num_clusters) {
    // Initialize the clusters
    cluster* clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = points[i].x;
        clusters[i].centroid.y = points[i].y;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    // Assign each point to its closest cluster
    for (int i = 0; i < num_points; i++) {
        cluster* closest_cluster = find_closest_cluster(points[i], clusters, num_clusters);
        closest_cluster->num_points++;
        closest_cluster->points = realloc(closest_cluster->points, sizeof(point) * closest_cluster->num_points);
        closest_cluster->points[closest_cluster->num_points - 1] = points[i];
    }

    // Update the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Repeat the previous two steps until the centroids no longer change
    int converged = 0;
    while (!converged) {
        converged = 1;
        for (int i = 0; i < num_points; i++) {
            cluster* closest_cluster = find_closest_cluster(points[i], clusters, num_clusters);
            if (closest_cluster != find_closest_cluster(points[i], clusters, num_clusters)) {
                converged = 0;
                break;
            }
        }
        if (!converged) {
            for (int i = 0; i < num_clusters; i++) {
                update_centroid(&clusters[i]);
            }
        }
    }

    // Return the clusters
    return clusters;
}

// Main function
int main() {
    // Define the points
    point points[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering
    int num_clusters = 3;
    cluster* clusters = kmeans(points, num_points, num_clusters);

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
        printf("Points:\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}