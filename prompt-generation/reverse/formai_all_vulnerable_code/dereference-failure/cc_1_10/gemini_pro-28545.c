//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000
#define MAX_CLUSTERS 10

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point centroid;
    int num_points;
    point* points;
} cluster;

// Function to calculate the distance between two points
double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to find the closest cluster to a point
int find_closest_cluster(point p, cluster* clusters, int num_clusters) {
    int closest_cluster_index = -1;
    double closest_distance = INFINITY;

    for (int i = 0; i < num_clusters; i++) {
        double dist = distance(p, clusters[i].centroid);
        if (dist < closest_distance) {
            closest_distance = dist;
            closest_cluster_index = i;
        }
    }

    return closest_cluster_index;
}

// Function to update the centroid of a cluster
void update_centroid(cluster* cluster) {
    double sum_x = 0;
    double sum_y = 0;

    for (int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }

    cluster->centroid.x = sum_x / cluster->num_points;
    cluster->centroid.y = sum_y / cluster->num_points;
}

// Function to perform k-means clustering
void k_means(point* points, int num_points, int num_clusters) {
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
        int closest_cluster_index = find_closest_cluster(points[i], clusters, num_clusters);
        clusters[closest_cluster_index].num_points++;
        clusters[closest_cluster_index].points = realloc(clusters[closest_cluster_index].points, sizeof(point) * clusters[closest_cluster_index].num_points);
        clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points - 1] = points[i];
    }

    // Update the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Repeat the previous two steps until the centroids no longer change
    int converged = 0;
    while (!converged) {
        converged = 1;

        // Assign each point to its closest cluster
        for (int i = 0; i < num_points; i++) {
            int closest_cluster_index = find_closest_cluster(points[i], clusters, num_clusters);
            if (closest_cluster_index != find_closest_cluster(points[i], clusters, num_clusters)) {
                converged = 0;
            }
            clusters[closest_cluster_index].num_points++;
            clusters[closest_cluster_index].points = realloc(clusters[closest_cluster_index].points, sizeof(point) * clusters[closest_cluster_index].num_points);
            clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points - 1] = points[i];
        }

        // Update the centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            update_centroid(&clusters[i]);
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
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
}

int main() {
    // Define the points
    point points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
    };
    int num_points = sizeof(points) / sizeof(point);

    // Perform k-means clustering
    int num_clusters = 3;
    k_means(points, num_points, num_clusters);

    return 0;
}