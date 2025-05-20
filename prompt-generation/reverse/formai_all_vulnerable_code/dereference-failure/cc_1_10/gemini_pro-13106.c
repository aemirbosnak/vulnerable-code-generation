//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A point in 2D space
typedef struct point {
    double x;
    double y;
} point;

// A cluster of points
typedef struct cluster {
    int num_points;
    point *points;
    double centroid_x;
    double centroid_y;
} cluster;

// Create a new point
point *new_point(double x, double y) {
    point *p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

// Create a new cluster
cluster *new_cluster() {
    cluster *c = malloc(sizeof(cluster));
    c->num_points = 0;
    c->points = NULL;
    c->centroid_x = 0;
    c->centroid_y = 0;
    return c;
}

// Add a point to a cluster
void add_point_to_cluster(cluster *c, point *p) {
    c->num_points++;
    c->points = realloc(c->points, sizeof(point) * c->num_points);
    c->points[c->num_points - 1] = *p;
}

// Calculate the centroid of a cluster
void calculate_centroid(cluster *c) {
    double sum_x = 0;
    double sum_y = 0;
    for (int i = 0; i < c->num_points; i++) {
        sum_x += c->points[i].x;
        sum_y += c->points[i].y;
    }
    c->centroid_x = sum_x / c->num_points;
    c->centroid_y = sum_y / c->num_points;
}

// Assign points to clusters
void assign_points_to_clusters(cluster **clusters, int num_clusters, point *points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int min_cluster_index = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(points[i].x - clusters[j]->centroid_x, 2) + pow(points[i].y - clusters[j]->centroid_y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster_index = j;
            }
        }
        add_point_to_cluster(clusters[min_cluster_index], &points[i]);
    }
}

// Update the centroids of the clusters
void update_centroids(cluster **clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        calculate_centroid(clusters[i]);
    }
}

// Perform k-means clustering
cluster **k_means(point *points, int num_points, int num_clusters) {
    // Create the clusters
    cluster **clusters = malloc(sizeof(cluster *) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = new_cluster();
    }

    // Assign points to clusters
    assign_points_to_clusters(clusters, num_clusters, points, num_points);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Repeat until the centroids no longer change
    int iterations = 0;
    while (iterations < 100) {
        // Assign points to clusters
        assign_points_to_clusters(clusters, num_clusters, points, num_points);

        // Update the centroids of the clusters
        update_centroids(clusters, num_clusters);

        iterations++;
    }

    return clusters;
}

// Print the clusters
void print_clusters(cluster **clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%f, %f)\n", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }
}

// Free the memory allocated for the clusters
void free_clusters(cluster **clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i]->points);
        free(clusters[i]);
    }
    free(clusters);
}

int main() {
    // Create the points
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

    int num_points = sizeof(points) / sizeof(points[0]);

    // Perform k-means clustering
    int num_clusters = 3;
    cluster **clusters = k_means(points, num_points, num_clusters);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    // Free the memory allocated for the clusters
    free_clusters(clusters, num_clusters);

    return 0;
}