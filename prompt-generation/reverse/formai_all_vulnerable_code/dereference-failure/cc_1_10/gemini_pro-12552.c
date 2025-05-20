//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data structure for a point in the Euclidean plane.
typedef struct point {
    double x;
    double y;
} point;

// Define the data structure for a cluster.
typedef struct cluster {
    int size;
    point* points;
    point centroid;
} cluster;

// Create a new point.
point* create_point(double x, double y) {
    point* p = (point*)malloc(sizeof(point));
    p->x = x;
    p->y = y;
    return p;
}

// Create a new cluster.
cluster* create_cluster(int size, point* points) {
    cluster* c = (cluster*)malloc(sizeof(cluster));
    c->size = size;
    c->points = points;
    c->centroid = *create_point(0, 0);
    return c;
}

// Free the memory allocated for a point.
void free_point(point* p) {
    free(p);
}

// Free the memory allocated for a cluster.
void free_cluster(cluster* c) {
    for (int i = 0; i < c->size; i++) {
        free_point(&c->points[i]);
    }
    free(c->points);
    free(c);
}

// Compute the Euclidean distance between two points.
double distance(point* p1, point* p2) {
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

// Compute the centroid of a cluster.
point centroid(cluster* c) {
    point centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < c->size; i++) {
        centroid.x += c->points[i].x;
        centroid.y += c->points[i].y;
    }
    centroid.x /= c->size;
    centroid.y /= c->size;
    return centroid;
}

// Assign each point to its closest cluster.
void assign_points(cluster* clusters, int num_clusters, point* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance_to_cluster = distance(&points[i], &clusters[j].centroid);
            if (distance_to_cluster < min_distance) {
                min_distance = distance_to_cluster;
                closest_cluster = j;
            }
        }
        clusters[closest_cluster].points = realloc(clusters[closest_cluster].points, sizeof(point) * (clusters[closest_cluster].size + 1));
        clusters[closest_cluster].points[clusters[closest_cluster].size++] = points[i];
    }
}

// Update the centroids of the clusters.
void update_centroids(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = centroid(&clusters[i]);
    }
}

// Perform the k-means clustering algorithm.
cluster* k_means(point* points, int num_points, int num_clusters) {
    // Initialize the clusters.
    cluster* clusters = (cluster*)malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(0, NULL);
    }

    // Assign each point to its closest cluster.
    assign_points(clusters, num_clusters, points, num_points);

    // Update the centroids of the clusters.
    update_centroids(clusters, num_clusters);

    // Repeat the previous two steps until the centroids no longer change.
    int converged = 0;
    while (!converged) {
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            point old_centroid = clusters[i].centroid;
            update_centroids(clusters, num_clusters);
            if (distance(&old_centroid, &clusters[i].centroid) > 0.001) {
                converged = 0;
            }
        }
        assign_points(clusters, num_clusters, points, num_points);
    }

    return clusters;
}

// Print the clusters.
void print_clusters(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Free the memory allocated for the clusters.
void free_clusters(cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);
}

int main() {
    // Create the points.
    point points[] = {
        *create_point(1, 2),
        *create_point(3, 4),
        *create_point(5, 6),
        *create_point(7, 8),
        *create_point(9, 10),
    };
    int num_points = sizeof(points) / sizeof(point);

    // Perform the k-means clustering algorithm.
    int num_clusters = 2;
    cluster* clusters = k_means(points, num_points, num_clusters);

    // Print the clusters.
    print_clusters(clusters, num_clusters);

    // Free the memory allocated for the points and clusters.
    for (int i = 0; i < num_points; i++) {
        free_point(&points[i]);
    }
    free_clusters(clusters, num_clusters);

    return 0;
}